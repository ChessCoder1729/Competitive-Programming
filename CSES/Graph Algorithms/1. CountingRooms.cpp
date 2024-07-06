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

char c[1001][1001]; bool vis[1001][1001]; int cnt = 0; int n,m;

void dfs(int r, int col){
    if(r>=n or col>=m or r<0 or col<0 or vis[r][col]==true or c[r][col]=='#'){
        return;
    }
    else{
        vis[r][col] = true; dfs(r+1,col); dfs(r-1,col); dfs(r,col+1); dfs(r,col-1); 
    }
}

 
int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> c[i][j];
        }
    }  
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(c[i][j]=='.' and !vis[i][j]){
                cnt++; dfs(i,j);
            }
        }
    }
    cout << cnt;
}