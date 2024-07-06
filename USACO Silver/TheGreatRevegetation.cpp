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
vector<vector<int>>adj(N+1); vector<bool>vis(N+1); 

void dfs(int node){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main() {
    fastio;
    usaco("revegetate");
    int n,m; cin >> n >> m;
    int u,v; char c;
    for(int i = 0;i<m;i++){
        cin >> c >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            cnt++; 
            dfs(i);
        }
    }
    if(cnt==0){
        cout << 0;
    }
    else{
        cout << 1;
        while(cnt--){
            cout << 0;
        }
    }
}

