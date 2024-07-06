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
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    int n; cin >> n; ll x; cin >> x;
    vector<pair<ll,int>>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i].first; a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    int p = -1, q = -1, m = -1;
    for(int i = 0;i<n;i++){
        ll num = x - a[i].first;
        int l = i+1; int r = n-1;
        while(l<r){
            if(a[l].first+a[r].first==num){
                break;
            }
            if((a[l].first+a[r].first)<num){
                l++;
            }
            else{
                r--;
            }
        }
        if(l<r){
            p = a[i].second; q = a[l].second; m = a[r].second;
        }        
    }
    if(p==-1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << p << ' ' << q << ' ' << m;
    }
}