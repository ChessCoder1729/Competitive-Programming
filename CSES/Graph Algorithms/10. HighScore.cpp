// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
typedef long double lld;
#define double lld
typedef long long ll;
typedef unsigned long long ull;
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

void dfs(int node, vector<bool>&vis, vector<vector<pair<int,int>>>&adj){
    vis[node] = true;
    for(auto [child,_] : adj[node]){
        if(!vis[child]){
            dfs(child,vis,adj);
        }
    }
}

signed main(){
    fastio; judge();
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>>adj1(n),adj2(n);
    for(int i = 0,u,v,w;i<m;i++){
        cin >> u >> v >> w; u--; v--;
        adj1[u].pb({v,w}); adj2[v].pb({u,w});
    }

    vector<int>dp(n,-1*inf); queue<int>q; q.push(n-1); dp[n-1] = 0;
    vector<bool>vis1(n,false),vis2(n,false);
    dfs(0,vis1,adj1), dfs(n-1,vis2,adj2);
    
    int op = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        op++;
        if(op==1e7){
            cout << -1; return 0;
        }
        for(auto [child,w] : adj2[node]){
            if(vis1[child] and vis2[child] and dp[child]<=dp[node]+w){
                dp[child] = dp[node]+w;
                q.push(child);
            }
        }
    }
    
    cout << dp[0];
}