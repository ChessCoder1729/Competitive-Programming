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

vector<vector<int>>cycles; vector<bool>cycle;
void find2(int node, vector<int>&par,int target, vector<int>&curr){
    cycle[node] = true;
    curr.pb(node);
    if(node==target){
        return;
    }
    find2(par[node],par,target,curr);
}

void backdfs(int node, vector<vector<int>>&adj2){
    for(auto child : adj2[node]){
        if(!cycle[child]){
            cycle[child] = true; backdfs(child,adj2);
        }
    }
}

void dfs(int node, vector<int>&adj, vector<vector<int>>&adj2, vector<int>&par, vector<bool>&vis){
    vis[node] = true;
    if(vis[adj[node]]){
        if(!cycle[adj[node]]){
            vector<int>curr;
            find2(node,par,adj[node],curr);
            cycles.pb(curr);
            for(auto x : curr){
                backdfs(x,adj2);
            }
        } 

        return;
    }
    par[adj[node]] = node;
    dfs(adj[node],adj,adj2,par,vis);
}

int solve(int x, vector<int>&dp, vector<int>&adj){
    if(dp[x]!=-1){
        return dp[x];
    }
    dp[x] = solve(adj[x],dp,adj) + 1;
    return dp[x];
}

signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<int>adj(n); vector<vector<int>>adj2(n);
    for(int i = 0,u;i<n;i++){
        cin >> u; u--; adj[i] = u; adj2[u].pb(i);
    }
    vector<bool>vis(n,false); vector<int>par(n); cycle.resize(n,false);
    
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,adj2,par,vis);
        }
    }
    vector<int>dp(n,-1);
    for(auto v : cycles){
        for(auto x : v){
            dp[x] = v.size();
        }
    }
    for(int i = 0;i<n;i++){
        if(dp[i]==-1){
            dp[i] = solve(i,dp,adj);
        }
    }
    for(auto x : dp) cout << x << ' ';
}