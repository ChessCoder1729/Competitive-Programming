// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e18;
const ll mod = 1e9+7;

//#define LOCAL // Comment this line before submitting

#ifdef LOCAL
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifdef LOCAL
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif
}

struct ufds{
    vector<int>par;
    vector<int>sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0;i<n;i++){
            par[i] = i; sz[i] = 1;
        }
    }
    int get(int u){
        if(u==par[u]) return u;
        return par[u] = get(par[u]);
    }
    void unite(int u, int v){
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
    int n,q; cin >> n >> q;
    vector<int>par(n);
    for(int i = 0,u;i<n;i++){
        cin >> u; u--; par[i] = u;
    }
    ufds p;
    p.init(n);
    vector<vector<int>>cycles;
    vector<bool>isCycle(n,false);
    vector<int>position(n,inf); // position of the ith node in the cycle
    vector<int>sz(n,inf); // size of cycle the ith node is in
    for(int i = 0;i<n;i++){
        if(p.get(i)==p.get(par[i])){
            isCycle[i] = true;
            vector<int>vec = {i}; // the cycle through i
            while(true){
                position[vec.back()] = (int)(vec.size())-1;
                isCycle[vec.back()] = true;
                if(par[vec.back()]==i){
                    break;
                }
                vec.pb(par[vec.back()]);
            }
            for(auto x : vec){
                sz[x] = (int)(vec.size());
            }
            cycles.pb(vec);
        }
        else{
            p.unite(i,par[i]);
        }
    }

    vector<vector<int>>rev_adj(n);
    for(int i = 0;i<n;i++){
        if(isCycle[i]){
            continue;
        }
        rev_adj[par[i]].pb(i);
    }
    vector<int>dist(n);
    auto dfs = [&](auto &&self, int node) ->void{
        for(auto child : rev_adj[node]){
            dist[child] = dist[node]+1;
            self(self,child);
        }
    };
    for(int i = 0;i<n;i++){
        if(isCycle[i]){
            dist[i] = 0;
            dfs(dfs,i);
        }
    }
    int bits = 20;
    vector<vector<int>>up(n,vector<int>(bits));
    for(int i = 0;i<n;i++){
        up[i][0] = par[i];
    }
    for(int j = 1;j<bits;j++){
        for(int i = 0;i<n;i++){
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    auto jumper = [&](auto &&self, int node, int k) ->int{
        if(k==0){
            return node;
        }
        int p = log2(k);
        return self(self,up[node][p],k-(1<<p));
    };

    while(q--){
        int u,v; cin >> u >> v;
        u--; v--;
        if(p.get(u)!=p.get(v)){
            cout << -1 << endl; continue;
        }
        if(dist[u]<dist[v]){
            cout << -1 << endl; continue;
        }
        if(dist[u]==0){
            if(position[u]<=position[v]){
                cout << position[v] - position[u] << endl; continue;
            }
            cout << sz[u] + position[v] - position[u] << endl; continue;
        }
        if(dist[v]==0){
            int extra = dist[u];
            u = jumper(jumper,u,dist[u]);
            if(position[u]<=position[v]){
                cout << extra + position[v] - position[u] << endl; continue;
            }
            cout << extra + sz[u] + position[v] - position[u] << endl; continue;
        }
        int node = jumper(jumper,u,dist[u]-dist[v]);
        if(node==v){
            cout << dist[u]-dist[v] << endl; continue;
        }
        cout << -1 << endl;
    }
}
