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


vector<vector<int>>build(vector<vector<int>>&adj){// returns {indegree, outdegree}
    int n = adj.size();
    vector<int>in(n,0);
    vector<int>out(n,0);

     for(int node = 0;node<n;node++){
        for(auto child : adj[node]){
            out[node]++; in[child]++;
        }
    }

    return {in,out};

}

void dfs(int node, vector<vector<int>>&adj, vector<int>&in, vector<int>&out, vector<int>&path){
    while(out[node]!=0){
        int child = adj[node][out[node]-1];
        out[node]--;
        dfs(child,adj,in,out,path);
    }
    path.pb(node);
}

int eulerian_check(vector<vector<int>>&adj, vector<int>&in, vector<int>&out){
    int n = adj.size();

    int start = -1; 
    int tmp = -1; // If eulerian cycle i.e. in[i] = out[i] for all
    
    int start_nodes = 0, end_nodes = 0;
    for(int i = 0;i<n;i++){
        if(in[i]-out[i]==1){
            end_nodes++; 
        }
        if(out[i]-in[i]==1){
            start_nodes++; start = i;
        }
        if(out[i]>0){
            tmp = i;
        }
        if(abs(out[i]-in[i])>1){
            return -1;
        }
    }

    // If you want to choose a specific starting element just make changes here
    if((end_nodes==0 and start_nodes==0)){
        return tmp; 
    }
    if(start_nodes==1 and end_nodes==1){
        return start;
    }
    return -1;

}

vector<int> eulerian_path(vector<vector<int>>&adj, int num_edges){
    vector<vector<int>>v = build(adj);
    vector<int>in = v[0]; vector<int>out = v[1]; 

    int start_node = eulerian_check(adj,in,out);
    if(start_node==-1){
        return {-1};
    }
    vector<int>path;
    dfs(start_node,adj,in,out,path);
    
    if(path.size()==num_edges+1){
        reverse(path.begin(),path.end());
        return path;
    }
    return {-1};
}


signed main(){
    fastio; judge();
    int n,m; cin >> n >> m;
    vector<vector<int>>adj(n);
    int u,v;
    for(int i = 0;i<m;i++){
        cin >> u >> v; u--; v--; adj[u].pb(v);
    }

    vector<int>ans = eulerian_path(adj,m);
    if(ans[0]==-1 or ans[m]!=n-1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(auto x : ans){
        cout << x+1 << ' ';
    }
}