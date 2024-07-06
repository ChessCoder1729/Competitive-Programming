#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 1e6  + 1;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// to comment multiple lines at once ctrl+/

// Find and replace Ctrl+H
map<pair<int,int>,ll>dp;

int n, x;

ll solve(int target, int last, vector<int>&c){
    if(target==0){
        return 1;
    }
    if(dp[{target,last}]){
        return dp[{target,last}];
    }
    ll ans = 0;
    for(int i = last;i<n;i++){
        if(target>=c[i]){
            ans += solve(target-c[i],i,c);
            ans = ans%mod;
        }
        else{
            break;
        }
    }
    dp[{target,last}] = ans;
    return ans;
}

int main(){
    fastio;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    cin >> n >> x; vector<int>c(n);
    for(int i = 0;i<n;i++) cin >> c[i];
    sort(c.begin(),c.end());
    //cout << x << ' ';
    cout << solve(x,0,c) << ' ';
}