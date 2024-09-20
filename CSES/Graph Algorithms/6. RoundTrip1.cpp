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

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

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

signed main(){
    fastio; judge();
    int n,m,u,v; cin >> n >> m;
    vector<vector<int>>adj(n);

    while(m--){
        cin >> u >> v; u--; v--; adj[u].pb(v); adj[v].pb(u);
    }

    ufds p;
    p.build(n); u = -1; v = -1;

    for(int i = 0;i<n;i++){
        for(auto j : adj[i]){
            if(i<j){
                if(p.get(i)==p.get(j)){
                    u = i; v = j; break;
                }
                else{
                    p.unite(i,j);
                }
            }
        }
        if(u>-1){
            break;
        }
    }

    if(u==-1){
        cout << "IMPOSSIBLE"; return 0;
    }

    adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
    adj[v].erase(find(adj[v].begin(),adj[v].end(),u));

    queue<int>q;
    q.push(u);
    vector<int>dist(n,inf); vector<int>par(n,-1);
    dist[u] = 0; par[u] = u;

    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto child : adj[node]){
            if(dist[child]>dist[node]+1){
                dist[child] = dist[node]+1;
                par[child] = node;
                q.push(child);
            }
        }
    }

    vector<int>ans = {u+1};
    for(int x = v; x != u; x = par[x]){
        ans.pb(x+1);
    }
    ans.pb(u+1);

    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << ' ';
    }
}