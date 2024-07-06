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

bool vis[N+1]; vector <vector <int>> adj(N+1); vector <int> col(N+1);
bool bipartite = true;
 
void colour(int node, int c){
    if(col[node]==3-c){
        bipartite = false; return;
    }
    col[node] = c;
    if(!vis[node]){
        vis[node] = true;
        for(auto child : adj[node]){
            colour(child,3-c);
        }
    }
}

int main(){
    fastio;
    int n,m; cin >> n >> m;
    int u,v;
    for(int i = 0;i<m;i++){
        cin >> u >> v; u--;v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    colour(0,1);
    for(int i = 1;i<n;i++){
        if(!vis[i]){
            colour(i,1);
        }
    }
    if(bipartite){
        for(int i = 0;i<n;i++){
            cout << col[i] << ' ';
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
}