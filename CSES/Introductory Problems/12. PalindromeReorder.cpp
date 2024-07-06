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

 
int main(){
    fastio;
    string s; cin >> s;
    int n = s.size();
    vector <char> v(n);
    map<char,int>cnt;
    for(int i = 0;i<n;i++){
        cnt[s[i]]++;
    }
    if(n%2==0){
        bool temp = true;
        for(auto x : cnt){
            if(cnt[x.first]%2==1){
                temp = false; break;
            }
        }
        if(!temp){
            cout << "NO SOLUTION";
        }
        else{
            int l = 0; int r = n-1;
            for(auto x : cnt){
                while(cnt[x.first]>0){
                    v[l] = x.first; v[r] = x.first; l++; r--;
                    cnt[x.first] -= 2;
                }
            }
            _nospaceprint(v);
        }
    }
    else{
        int count = 0;
        for(auto x : cnt){
            count += cnt[x.first]%2;
        }
        if(count==1){
            int l = 0; int r = n-1;
            for(auto x : cnt){
                if(cnt[x.first]%2==1){
                    v[n/2] = x.first; cnt[x.first]--;
                }
                while(cnt[x.first]>0){
                    v[l] = x.first; v[r] = x.first; l++; r--;
                    cnt[x.first] -= 2;
                }
            }
            _nospaceprint(v);
        }
        else{
            cout << "NO SOLUTION" << endl;
        }
    }
}