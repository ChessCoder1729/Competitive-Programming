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
    freopen("Error.txt", "w", stderr);
    #define debug(x...) cerr << #x <<" = "; _print(x); cerr << endl;
    #else
    #define debug(x...)
    #endif
}

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void dfs(int node, int par, vector<int>&dist, vector<int>&subtree, vector<vector<int>>&adj){
    for(auto child : adj[node]){
        if(child==par){
            continue;
        }
        dist[child] = dist[node]+1;
        dfs(child,node,dist,subtree,adj);
        subtree[node] += subtree[child] + 1;
    }
}

void dfs2(int node, int par, vector<int>&dist, vector<int>&subtree, vector<int>&ans, vector<vector<int>>&adj){
    for(auto child : adj[node]){
        if(child==par){
            continue;
        }
        ans[child] = ans[node]  + dist.size() - 2*subtree[child] -2;
        dfs2(child,node,dist,subtree,ans,adj);
    }
}

signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<vector<int>>adj(n);
    for(int i = 0,u,v;i<n-1;i++){
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    vector<int>dist(n), subtree(n,0);
    dist[0] = 0;
    dfs(0,-1,dist,subtree,adj);
    
    vector<int>ans(n);
    for(auto x : dist) ans[0] += x;
    dfs2(0,-1,dist,subtree,ans,adj);
    
    for(auto x : ans) cout << x << ' ';
}