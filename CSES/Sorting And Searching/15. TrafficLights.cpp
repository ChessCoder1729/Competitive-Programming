#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void judge(){
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
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

 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    ll x; cin >> x; int n; cin >> n;
    vector<ll>a(n); set<ll>s = {0,x};
    for(int i = 0;i<n;i++) {
        cin >> a[i]; s.insert(a[i]);
    }
    ll maxi = 0; vector<ll>ans(n);
    ll prev = 0;
    for(auto p : s){
        maxi = max(maxi,p-prev);
        prev = p;
    }
    ans[n-1] = maxi;
    for(int i = n-1;i>0;i--){
        s.erase(a[i]);
        auto it = s.upper_bound(a[i]);
        ll high = *it; it--;
        ll low = *it;
        maxi = max(maxi,high-low);
        ans[i-1] = maxi;
    }
    _print(ans);
}