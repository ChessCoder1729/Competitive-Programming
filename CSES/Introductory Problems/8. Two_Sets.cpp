#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 1e6 + 1;
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
bool vis[N+1];

 
int main(){
    fastio;
    ll n; cin >> n;
    ll sum = (n*(n+1))/2;
    if((sum%2==1)){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        ll curr = n;
        vector<ll> a;
        ll target = sum/2;
        while(target>0){
            if(target<=n and !vis[target]){
                a.push_back(target); vis[target] = true; target = 0;
            }
            else if(target>=curr){
                vis[curr] = true; a.push_back(curr); target -= curr; curr--;
            }
        }
        cout << a.size() << endl;
        for(auto x : a) cout << x << ' ';
        cout << endl;
        cout << n-a.size() << endl;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cout << i << ' ';
            }
        }
    }
}