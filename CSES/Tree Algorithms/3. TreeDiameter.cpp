#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
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
template <class T, class V> void _nospaceprint(pair <T, V> p) { _print(p.first);  _print(p.second); }
template <class T> void _nospaceprint(vector <T> v) { for (T i : v) {_print(i);} }
template <class T> void _nospaceprint(set <T> v) { for (T i : v) {_print(i); } }
template <class T> void _nospaceprint(multiset <T> v) { for (T i : v) {_print(i);} }
template <class T, class V> void _nospaceprint(map <T, V> v) { for (auto i : v) {_print(i);} }

vector<vector<int>>adj(N+1); vector<int>depth(N+1);

void solve(int node, int parent){
    for(auto child : adj[node]){
        if(child != parent){
            depth[child] = depth[node]+1;
            solve(child,node);
        }
    }
}
 
int main(){
    fastio;
    int n; cin >> n; int u,v;
    for(int i = 0;i<n-1;i++){
        cin >> u >> v; u--;v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    depth[0] = 0;
    solve(0,-1);
    int node = 0;
    for(int i = 0;i<n;i++){
        if(depth[i]>depth[node]){
            node = i;
        }
    }
    depth[node] = 0;
    solve(node,-1);
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,depth[i]);
    }
    _print(ans);
}