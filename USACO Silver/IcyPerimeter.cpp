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
    fastio;
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int n; ll p = 0; ll a = 0; char grid[1001][1001]; ll ansp = 0; ll ansa = 0; bool vis[1001][1001];

void dfs(int r, int c){
    if(r<0 or r>=n or c<0 or c>=n){
        p++; return;
    }
    if(vis[r][c]) return;

    if(grid[r][c]=='.'){
        p++;
        return;
    }
    else{
        vis[r][c] = true;
        a++;
        dfs(r+1,c); dfs(r,c+1); dfs(r-1,c); dfs(r,c-1);
    }
}

int main() {
    usaco("perimeter");
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) cin >> grid[i][j];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j]=='#' and !vis[i][j]){
                dfs(i,j); 
                if(ansa==a){
                    ansp = min(ansp,p);
                }
                else if(ansa<a){
                    ansa = a; ansp = p;
                }
                a = p = 0;
            }
        }
    }
    cout << ansa << ' '  << ansp;
}

