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
void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
// to comment multiple lines at once ctrl+/

// Find and replace Ctrl+H
ll dp[n]; bool vis[n]; 

vector<int>c(100); int n, x;

ll solve(int target){
    if(vis[target]){
        return dp[target];
    }
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(target>=c[i]){
            ans += solve(target-c[i]);
            ans = ans%mod;
        }
    }
    vis[target] = true;
    dp[target] = ans; return ans;
}

int main(){
    fastio;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    dp[0] = 1LL; vis[0] = true;
    cin >> n >> x;
    for(int i = 0;i<n;i++) cin >> c[i];
    
    cout << solve(x) << ' ';
    // for(int i = 0;i<n;i++){
    //     ans += solve(c[i],x);
    //     cout << solve(c[i],x) << ' ';
    // }
}