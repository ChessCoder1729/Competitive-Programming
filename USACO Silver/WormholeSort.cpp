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

vector<int>p(N+1); vector<vector<pair<int,ll>>>adj(N+1);

void cost(int node, vector<ll>&dp){
    for(auto x : adj[node]){
        int child = x.first; ll c = x.second;
        if(dp[child]<min(dp[node],c)){
            dp[child] = min(dp[node],c);
            cost(child,dp);
        }
    }
}

int main() {
    fastio;
    usaco("wormsort");
    int n,m; cin >> n >> m;
    map<int,int>pos;
    for(int i = 0;i<n;i++){
        cin >> p[i]; p[i]--; pos[p[i]] = i;
    }
    int u,v,c;
    for(int i = 0;i<m;i++){
        cin >> u >> v >> c; u--;v--;
        adj[u].push_back({v,c}); adj[v].push_back({u,c});
    }
    ll ans = -1;
    for(int i = 0;i<n;i++){
        if(p[i]!=i){
            vector<ll>dp(n);
            for(int j = 0;j<n;j++) dp[j] = -1;
            dp[i] = inf;
            cost(i,dp);
            if(ans==-1){
                ans = dp[p[i]];
            }                  
            else{
                ans = min(ans,dp[p[i]]);
            }
            // i is at the p[i]th positiob
            pos[p[i]] = pos[i];
            p[pos[i]] = p[i];
        }
    }
    cout << ans;
}

