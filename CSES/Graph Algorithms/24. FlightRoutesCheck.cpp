#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
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
template <class T, class V> void _nospaceprint(pair <T, V> p) { _print(p.first);  _print(p.second); }
template <class T> void _nospaceprint(vector <T> v) { for (T i : v) {_print(i);} }
template <class T> void _nospaceprint(set <T> v) { for (T i : v) {_print(i); } }
template <class T> void _nospaceprint(multiset <T> v) { for (T i : v) {_print(i);} }
template <class T, class V> void _nospaceprint(map <T, V> v) { for (auto i : v) {_print(i);} }

vector<vector<int>>adj1(N+1); vector<vector<int>>adj2(N+1);

void dfs1(int node, vector<bool>&vis){
    vis[node] = true;
    for(auto child : adj1[node]){
        if(!vis[child]){ 
            dfs1(child,vis);
        }
    }
}
void dfs2(int node, vector<bool>&vis){
    vis[node] = true;
    for(auto child : adj2[node]){
        if(!vis[child]){ 
            dfs2(child,vis);
        }
    }
}
 
int main(){
    fastio;
    int n,m; cin >> n >> m;
    int u,v;
    for(int i = 0;i<m;i++){
        cin >> u >> v; u--; v--;
        adj1[u].push_back(v); 
        adj2[v].push_back(u);
    }
    bool tmp = true;
    vector<bool>vis(n);
    for(int i = 0;i<n;i++) vis[i] = false;
    dfs1(0,vis);
    for(int j = 0;j<n;j++){
        if(!vis[j]){
            cout << "NO" << endl;
            cout << 1 << ' ' << j+1;
            tmp = false; break;
        }
    }
    if(tmp){
        for(int i = 0;i<n;i++) vis[i] = false;
        dfs2(0,vis);
        for(int j = 0;j<n;j++){
        if(!vis[j]){
                cout << "NO" << endl;
                cout << j+1 << ' ' << 1;
                tmp = false; break;
            }
        }
        if(tmp){
            cout << "YES";
        }
    }
}