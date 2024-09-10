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
 
vector<vector<int>>adj; vector<bool>vis;
void join(int u, int v){
    u--; v--; adj[v].pb(u);
}

void dfs(int node, stack<int>&s){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child,s);
        }
    }
    s.push(node);
}

int add(int a, int b){
    return (a%mod + b%mod)%mod;
}

signed main(){
    fastio; judge();
    int n,m; cin >> n >> m; adj.resize(n); int u,v;
    while(m--){
        cin >> u >> v; join(u,v);
    }
    vis.resize(n); for(int i = 0;i<n;i++) vis[i] = false;
    
    stack<int>s;
    dfs(n-1,s);
    vector<int>topological_sort;
    while(s.size()>0){
        topological_sort.pb(s.top()); s.pop();
    }

    vector<ll>ans(n,0);
    ans[n-1] = 1;
    for(auto node : topological_sort){
        for(auto child : adj[node]){
            ans[child] = add(ans[child],ans[node]);
        }
    }
    
    cout << ans[0];
}