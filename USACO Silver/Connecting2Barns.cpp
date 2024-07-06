#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long inf = 1e18;
const long long mod = 1e9+7;
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const int N = 1e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
#define debug(x) cout << #x <<" = "; _print(x); cout << endl;

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) { _print(p.first);  _print(p.second); }
template <class T> void _print(vector <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(set <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(multiset <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T, class V> void _print(map <T, V> v) { for (auto i : v) {_print(i); cout << " ";} }

 
void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

set<int>dfs(int node,vector<bool>&vis,vector<vector<int>>&adj){
    vis[node] = true; 
    set<int> ans; ans.insert(node);
    for(auto child : adj[node]){
        if(!vis[child]){
            set<int>tmp = dfs(child,vis,adj);
            for(auto x : tmp){
                ans.insert(x);
            }
        }
    }
    return ans;
}

int main() {
    fastio;
    //usaco("");
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<vector<int>> adj(n);
        int u,v;
        for(int i = 0;i<m;i++){
            cin >> u >> v; u--;v--;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        vector<bool>vis(n);
        for(int i = 0;i<n;i++) vis[i] = false;
        set<int>a1 = dfs(0,vis,adj);
        set<int>a2 = dfs(n-1,vis,adj);
        int ans = INT_MAX;
        for(auto x : a1){
            auto it = a2.lower_bound(x);
            ans = min(ans,*it-x);
            if(it!=a2.begin()){
                it--; 
                ans = min(ans,x-*it);
            }
        }
        cout << ans << endl;
    }
}

