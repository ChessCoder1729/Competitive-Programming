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


void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
void judge(){
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
int main(){
    fastio; judge();
    int n; cin >> n; ll p; cin >> p;
    vector<ll>t(n);
    for(int i = 0;i<n;i++) cin >> t[i];
    sort(t.begin(),t.end());
    ll low = 0; ll high = p*t[0];
    ll ans = p*t[0];
    while(low<high){
        ll mid = (low+high)/2;
        ll prod = 0;
        for(int i = 0;i<n;i++){
            prod += mid/t[i];
        }
        if(prod>=p){
            high = mid;
            ans = min(ans,mid);
        }
        else{
            low = mid+1;
        }
    }
    ll prod = 0;
    for(int i = 0;i<n;i++){
        prod += low/t[i];
    }
    if(prod>=p){
        ans = min(ans,low);
    }
    cout << ans;
}