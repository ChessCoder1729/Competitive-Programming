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

int maxD, maxNode;

void dfs( vector<vector<int>>&adj, vector<bool>&vis, int node , int d ){
    vis[node] = 1 ;
    if( d > maxD ){
        maxNode = node ;
        maxD = d ;
    }

     // applying the standard dfs 
    for( auto x : adj[node] ){
        if(vis[x] == 0 ){
            dfs(adj,vis, x,d+1 ) ;
        }
    }
}

void cfsolver(){
    maxD = -1, maxNode = -1; 
    int n; cin >> n; vector<vector<int>>adj(n); vector<bool>vis(n,false);
    for(int i = 0,u,v;i<n;i++){
        cin >> u >> v; adj[u-1].pb(v-1); adj[v-1].pb(u-1);
    }

    
}

signed main(){
    fastio; judge();
    int tc = 1; cin >> tc;
    for(int testcase = 1;testcase<=tc;testcase++){
        //cout << "Case #" << testcase << ": ";
        cfsolver();
        
        
        // cout << "------------------------------------------" << endl;
    }
}