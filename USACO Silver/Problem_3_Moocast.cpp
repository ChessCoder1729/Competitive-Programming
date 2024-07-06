#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long inf = 1e18;
const long long mod = 1e9+7;
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const int N = 25000;
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
vector<vector<int>>adj(N+1); bool vis[N+1];

int dfs(int node){
    int ans = 1;
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]){
            ans += dfs(child);
        }
    }
    return ans;
}

int main() {
    fastio;
    //usaco("");
    int n; cin >> n;
    vector<pair<ll,ll>>v(n); vector<ll>pow(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first >> v[i].second >> pow[i];
        pow[i] = pow[i]*pow[i];
    }
    ll a[n][n];
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            a[i][j] = (v[j].first-v[i].first)*(v[j].first-v[i].first) + (v[j].second-v[i].second)*(v[j].second-v[i].second);
            a[j][i] = a[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(a[i][j]<=pow[i]){
                adj[i].push_back(j);
            }
        }
        for(int j = i+1;j<n;j++){
            if(a[i][j]<=pow[i]){
                adj[i].push_back(j);
            }
        }
    }
    int ans = 1;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            ans = max(ans,dfs(i));
        }
    }
    cout << ans;
}

