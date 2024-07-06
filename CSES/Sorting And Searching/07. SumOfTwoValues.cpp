#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 1e5;
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
template <class T, class V> void _print(pair <T, V> p) { _print(p);  _print(p.second); }
template <class T> void _print(vector <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(set <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T> void _print(multiset <T> v) { for (T i : v) {_print(i); cout << " ";} }
template <class T, class V> void _print(map <T, V> v) { for (auto i : v) {_print(i); cout << " ";} }
template <class T, class V> void _nospaceprint(pair <T, V> p) { _print(p);  _print(p.second); }
template <class T> void _nospaceprint(vector <T> v) { for (T i : v) {_print(i);} }
template <class T> void _nospaceprint(set <T> v) { for (T i : v) {_print(i); } }
template <class T> void _nospaceprint(multiset <T> v) { for (T i : v) {_print(i);} }
template <class T, class V> void _nospaceprint(map <T, V> v) { for (auto i : v) {_print(i);} }
 
 
int main(){
    fastio;
    int n; cin >> n; ll x; cin >> x;
    vector<ll>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    map<ll,vector<int>>m;
    for(int i = 0;i<n;i++){
        m[a[i]].push_back(i);
    }
    sort(a.begin(),a.end());
    int idx1 = -1; int idx2 = -1;
    vector<ll>::iterator it;
    for(int i = 0;i<n-1;i++){        
        if(a[i]+a[i+1]==x){
            vector<int> v1 = m[a[i]]; vector<int>v2 = m[a[i+1]];
            idx1 = v1[0]; idx2 = v2[v2.size()-1];    break;
        }
        else if(a[i]+a[n-1]<x){
            continue;
        }
        else if(2*a[i]<=x){
            it = lower_bound(a.begin(),a.end(),x-a[i]);
            if((a[i]+a[it-a.begin()])==x and a[i]!=a[it-a.begin()]){
                idx1 = *m[a[i]].begin(); idx2 = *m[a[it-a.begin()]].begin(); break;
            }
        }
        else{
            break;
        }
    }
    if(idx1==-1 and idx2==-1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << idx1+1 << ' ' << idx2+1;
    }
}