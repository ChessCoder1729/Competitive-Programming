#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const ll inf = 1e18;
const ll mod = 1e9+7;


#ifndef ONLINE_JUDGE
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}


vector<vector<int>>kosaraju(vector<vector<int>>&adj){
    int n = adj.size();
    vector<bool>vis(n,false);
    stack<int>s;

    auto dfs1 = [&](auto&& self, int node) -> void{
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]){
                self(self,child);
            }
        }
        s.push(node);
    };
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs1(dfs1,i);
        }
    }

    vector<vector<int>>rev_adj(n);
    for(int u = 0;u<n;u++){
        for(auto v : adj[u]){
            rev_adj[v].pb(u);
        }
    }
    fill(vis.begin(),vis.end(),false);
    auto dfs2 = [&](auto&& self, int node, vector<int>&curr) -> void{
        vis[node] = true;
        curr.pb(node);
        for(auto child : rev_adj[node]){
            if(!vis[child]){
                self(self,child,curr);
            }
        }
    };
    vector<vector<int>>components;

    while(true){
        if(s.size()==0){
            break;
        }
        int node = s.top(); s.pop();
        if(vis[node]){
            continue;
        }
        vector<int>vec;
        dfs2(dfs2,node,vec);
        components.pb(vec);
    }

    return components;
}


vector<int> build_topo(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>indeg(n);
    for(int i = 0;i<n;i++){
        for(auto v : adj[i]){
            indeg[v]++;
        }
    }
    queue<int>q; // Sometimes even priority queue if you want lexicographically minimum topo
    for(int i = 0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front(); q.pop();
        topo.pb(node);
        for(auto child : adj[node]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    if(topo.size()<n){
        return {-1};
    }
    return topo;
}

signed main(){
    fastio; judge();
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int>>adj(n);
    vector<pair<int,int>>edges;

    while(m--){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        edges.pb({u,v});
    }

    vector<vector<int>>scc = kosaraju(adj);

    vector<int>comp_val(n);
    for(int i = 0;i<scc.size();i++){
        for(auto node : scc[i]){
            comp_val[node] = i;
        }
    }
    debug(scc);
    n = scc.size();
    vector<vector<int>>adj2(n);
    for(auto [u,v]:edges){
        if(comp_val[u]==comp_val[v]){
            continue;
        }
        adj2[comp_val[u]].pb(comp_val[v]);
    }


    vector<bitset<50000>>dp(n);
    for(int i = 0;i<n;i++){
        for(auto node : scc[i]){
            dp[i][node] = 1;
        }
    }
    vector<int>topo = build_topo(adj2);
    for(int i = n-1;i>=0;i--){
        int node = topo[i];
        for(auto child : adj2[node]){
            dp[node] = (dp[node]|dp[child]);
        }
    }
    while(q--){
        int u,v; cin >> u >> v; u--; v--;
        if(dp[comp_val[u]][v]==1){
            py;
        }
        else{
            pn;
        }
    }
}
