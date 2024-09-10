#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void judge(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	#endif
}
struct ufds{
    vector<ll>par; ll comp; ll max_comp;
    vector<ll>sz; 
    void build(ll n){
        par.resize(n); 
        sz.resize(n);
        for(ll i = 0;i<n;i++){
            par[i] = i; sz[i] = 1;
        }
		comp = n; max_comp = 1;
    }
    ll get(ll u){
        if(u==par[u]) return u;
        return par[u] = get(par[u]);
    }
    void unite(ll u, ll v){
        u = get(u); v = get(v);
        if(u!=v){
            if(sz[u]>sz[v]){
                swap(u,v);
            }
            par[u] = v;
            sz[v] += sz[u];
			comp--; 
			max_comp = max(max_comp,sz[v]);
        }
    }
	void print(){
		cout << comp << ' ' << max_comp << endl;
	}
}; 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
	fastio; judge();
	ll n; cin >> n;
	ufds p; p.build(n);
	int m; cin >> m; ll u,v; 
	while(m--){
		cin >> u >> v; u--; v--;
		p.unite(u,v);
		p.print();
	}
}