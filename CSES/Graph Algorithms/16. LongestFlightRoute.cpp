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
//#define int long long
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
vector<vector<int>>adj;
vector<bool>vis; 

void dfs(int node,stack<int>&s){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child,s);
        }
    }
    s.push(node);
}


signed main(){
    fastio; judge();
    int n,m; 
    cin >> n; cin >> m; adj.resize(n); vis.resize(n);
    
    int u,v;
    while(m--){
        cin >> u >> v; u--; v--; adj[u].pb(v);
    }

    stack<int>s;
    vector<int>par(n);
    for(int i = 0;i<n;i++){
        par[i] = i; vis[i] = false;
    }

    vector<int>topological_sort;
    vector<int>dist(n,-1);
    dfs(0,s);
    while(s.size()>0){
        topological_sort.pb(s.top()); s.pop();
    }

    dist[0] = 0;
    for(auto node : topological_sort){
        if(dist[node]>=0){
            for(auto child : adj[node]){
                if(dist[child]<dist[node]+1){
                    dist[child] = dist[node] + 1;
                    par[child] = node;
                }
            }
        }
    }
    
    if(dist[n-1]==-1){
        cout << "IMPOSSIBLE"; return 0;
    }

    cout << dist[n-1] + 1 << endl;
    vector<int>ans; int curr = n-1;
    while(curr!=0){
        ans.pb(curr); 
        curr = par[curr];
    }
    ans.pb(0);
    reverse(ans.begin(),ans.end());
    for(auto x : ans){
        cout << x+1 << ' ';
    }
}