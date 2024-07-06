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

vector <bool> vis(N+1); vector <vector<int>> adj(N+1); vector<ll> xcord(N+1); vector<ll> ycord(N+1);

vector<ll>dfs(int node){
    vis[node] = true;
    ll xmin, xmax, ymin, ymax; 
    xmin = xcord[node]; xmax = xcord[node]; ymin = ycord[node]; ymax = ycord[node];
    vector<ll> ans = {xmin,xmax,ymin,ymax};
    for(auto child : adj[node]){
        if(!vis[child]){
            vector<ll>a = dfs(child);
            ans[0] = min(a[0],ans[0]); ans[1] = max(a[1],ans[1]); ans[2] = min(ans[2],a[2]);
            ans[3] = max(a[3],ans[3]);
        }
    }
    return ans;
}

int main() {
    fastio;
    usaco("fenceplan");
    int n,m; cin >> n >> m;
    for(int i = 0;i<n;i++) cin >> xcord[i] >> ycord[i];
    int u,v;
    for(int i = 0;i<m;i++){
        cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    ll ans = inf;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            vector<ll>a = dfs(i);
            ans = min(ans,2*(a[1]-a[0])+2*(a[3]-a[2]));
        }
    }
    cout << ans;

}

