#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5 + 3;
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
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

 
void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
vector<vector<int>>adj(N+1); bool closed[N+1];


void dfs(int node,vector<bool>&vis){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child] and !closed[child]){
            dfs(child,vis);
        }
    }
}

int connected(int node, int n){
    vector <bool> vis(n);
    for(int i = 0;i<n;i++) vis[i] = false;
    dfs(node,vis);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        cnt += vis[i];
    }
    return cnt;
}

 
int main(){
    fastio;
    usaco("closing");
    int n,m; cin >> n >> m;
    int u,v;
    for(int i = 0;i<m;i++){
        cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int cnt = 0;
    if(connected(0,n)==n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    for(int i = 1;i<n;i++){
        cin >> u; u--; closed[u] = true;
        for(int j = 0;j<n;j++){
            if(!closed[j]){
                if(connected(j,n)==n-i){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
                break;
            }
        }
    }
}