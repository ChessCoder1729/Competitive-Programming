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
    int n; cin >> n;
    vector<ll>t(n); for(int i = 0;i<n;i++) cin >> t[i];
    sort(t.begin(),t.end());
    ll sum = 0;
    for(int i = 0;i<n-1;i++){
        sum += t[i];
    }
    if(sum>t[n-1]){
        cout << sum+t[n-1];
    }
    else{
        cout << 2*t[n-1];
    }
}