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


void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
vector<int>bash(vector<ll>a){
    vector<int>v = {0};
    for(int i = 1;i<a.size();i++){
        int tmp = 0;
        for(int j = i-1;j>=0;j--){
            if(a[j]<a[i]){
                tmp = j+1;
                break;
            }
        }
        v.push_back(tmp);
    }
    return v;
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    for(int x = 1;x<=10;x++){
        ll n = rand()%10 + 1;
        vector<ll>a(n);
        for(int i = 0;i<n;i++) a[i] = rand()%(2*n) + 1;
        stack<pair<ll,int>>s; vector<int>ans;
        for(int i = 0;i<n;i++){
            while(s.size()>0){
                ll tmp = s.top().first;
                if(tmp>=a[i]){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(s.top().second);
            }
            s.push({a[i],i+1});
        }
        vector<int>v = bash(a);
        if(ans==v){
            cout << "Test Case # " << x << " Passed" << endl;
        }
        else{
            debug(a);
            debug(v);
            debug(ans);
        }
    }
}