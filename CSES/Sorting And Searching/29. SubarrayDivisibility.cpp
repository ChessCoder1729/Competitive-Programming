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

ll bash(vector<ll>a){
    ll n = a.size();
    ll cnt = 0; ll prefix[n];
    prefix[0] = a[0]%n;
    for(int i = 1;i<n;i++){
        prefix[i] = prefix[i-1]+ a[i];
        prefix[i] = prefix[i]%n;
    }
    for(int i = 0;i<n;i++){
        if(prefix[i]==0){
            cnt++;
        }
        for(int j = 0;j<i;j++){
            if(prefix[i]==prefix[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    ll n; cin >> n;
    vector<ll>a(n);
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        if(a[i]<0){
            a[i] = (n-((-1*a[i])%n));
        }
    }
    map<ll,ll>cnt; ll curr = 0;
    cnt[0] = 1LL; ll ans = 0;
    for(ll i = 0;i<n;i++){
        curr += a[i];
        curr = curr%n;
        ans += cnt[curr];
        cnt[curr]++;
    }
    cout << ans;
}