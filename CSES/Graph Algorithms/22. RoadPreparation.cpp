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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// Check for queue, priorioty_queue, stack, ordered_set solutions
// stack => LIFO (whatever goes in last comes out last)
// queue => FIFO (whatever goes in first comes out first)
// priority_queue => Dynamic queries of minimum/maximum
// ordered_set => set in vector form
//[order_of_key(k) gives number of elements less than k, while find_by_order(i) gives i^th element]

// To comment multiple lines : ctrl + /
// To find and replace : ctrl+H

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

// For finding the Minimum Spanning Tree

struct ufds{
    vector<ll>par; 
    vector<ll>sz; 
    void build(ll n){
        par.resize(n); 
        sz.resize(n);
        for(ll i = 0;i<n;i++){
            par[i] = i; sz[i] = 1;
        }
    }
    ll get(ll u){
        if(u==par[u]) return u;
        return par[u] = get(par[u]);
    }
    void unite(ll u, ll v){
        //u--; v--;
        u = get(u); v = get(v);
        if(u!=v){
            if(sz[u]>sz[v]){
                swap(u,v);
            }
            par[u] = v;
            sz[v] += sz[u];
        }
    }
}; 

int mstweight = 0; // Weight of mst
vector<pair<int,int>>mst; // Edges in mst

void kruskal(int n, vector<pair<ll,pair<int,int>>>&edges){ // {weight,{u,v}}
    

    sort(edges.begin(),edges.end());

    ufds p; p.build(n);

    for(auto edge : edges){
        ll weight = edge.first;
        int u = edge.second.first; int v = edge.second.second;

        if(p.get(u)!=p.get(v)){
            mstweight += weight;
            mst.pb({u,v});
            p.unite(u,v);
        }
    }
} 

signed main(){
    fastio; judge();
    int n,m,u,v; ll w; cin >> n >> m;  
    vector<pair<ll,pair<int,int>>>edges;

    while(m--){
        cin >> u >> v >> w; u--; v--;
        edges.pb({w,{u,v}});
    }

    kruskal(n,edges);

    if(mst.size()==n-1){
        cout << mstweight; return 0;
    }

    cout << "IMPOSSIBLE";
}