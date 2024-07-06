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
template <class T, class V> void _print(pair <T, V> p) { _print(p.first); cout << " ";  _print(p.second); }
template <class T> void _print(vector <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(set <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(multiset <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T, class V> void _print(map <T, V> v) { for (auto i : v) {_print(i); cout << " ";} }
template <class T, class V> void _nospaceprint(pair <T, V> p) { _print(p.first);  _print(p.second); }
template <class T> void _nospaceprint(vector <T> v) { for (T i : v) {_print(i);} }
template <class T> void _nospaceprint(set <T> v) { for (T i : v) {_print(i); } }
template <class T> void _nospaceprint(multiset <T> v) { for (T i : v) {_print(i);} }
template <class T, class V> void _nospaceprint(map <T, V> v) { for (auto i : v) {_print(i);} }

void usaco(string s) {
    fastio;
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

map<pair<int,int>,vector<pair<int,int>>>mp; int n; int grid[101][101]; bool vis[101][101];

void dfs(int r, int c){
    if(r<0 or r>=n or c<0 or c>=n or grid[r][c]==0 or vis[r][c]==true){
        return;
    }
    vis[r][c] = true;
    for(auto y : mp[{r,c}]){
        grid[y.first][y.second] = 1;
    }
    dfs(r+1,c); 
    dfs(r-1,c); 
    dfs(r,c+1); 
    dfs(r,c-1);
}
 
int main(){
    usaco("lightson");
    int m;
    cin >> n >> m;
    int x1,x2,y1,y2;
    for(int i = 0;i<m;i++){
        cin >> x1 >> x2 >> y1 >> y2;
        mp[{x1-1,x2-1}].push_back({y1-1,y2-1});
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            grid[i][j] = 0;
        }
    }
    grid[0][0] = 1; int k = 2*n;
    while(k--){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                vis[i][j] = false;
            }
        }
        dfs(0,0);
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cnt += grid[i][j];
        }
    }
    cout << cnt;

}