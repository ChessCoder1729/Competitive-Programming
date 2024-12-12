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

int setbit(int x){
    return __builtin_popcount(x);
}

int check(int x, int bit){
    return ((x&(1<<bit))!=0);
}

void input(int &n, int &m, vector<vector<int>>&adj){
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0,u,v;i<m;i++){
        cin >> u >> v; adj[u-1].pb(v-1);
    }
}

int dfs(int node, int mask, vector<vector<int>>&dp, vector<vector<int>>&adj){
    int n = dp.size();
    if(setbit(mask)==n and node==n-1) return 1;
    if(setbit(mask)==n) return 0;
    if(node==n-1) return 0;
    if(dp[node][mask]!=-1) return dp[node][mask];

    int ans = 0;
    for(auto child : adj[node]){
        if(!check(mask,child)){
            ans += dfs(child,mask+(1<<child),dp,adj);
            ans %= mod;
        }
    }
    dp[node][mask] = ans;
    return ans;
}

signed main(){
    fastio; judge();
    int n,m; vector<vector<int>>adj;
    input(n,m,adj);

    vector<vector<int>>dp(n,vector<int>((1<<n),-1));
    
    cout << dfs(0,1,dp,adj);
}