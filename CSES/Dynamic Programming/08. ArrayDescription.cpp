#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define pb push_back
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    int tc = 1;
    while(tc--){
        int n,m; cin >> n >> m;
        int v; cin >> v;
        ll dp[n][m+1]; // dp[i][j] = Number of ways st at i^th pos j is there
        if(v==0){
            for(int i = 1;i<=m;i++){
                dp[0][i] = 1;
            }
        }
        else{
            for(int i = 1;i<=m;i++){
                dp[0][i] = 0;
            }
            dp[0][v] = 1;
        }
        for(int i = 1;i<n;i++){
            cin >> v;
            if(v==0){
                for(int j = 1;j<=m;j++){
                    dp[i][j] = dp[i-1][j];
                    if(j>=2){
                        dp[i][j] += dp[i-1][j-1]; dp[i][j] %= mod;
                    }
                    if(j<m){
                        dp[i][j] += dp[i-1][j+1]; dp[i][j] %= mod;
                    }
                }
            }
            else{
                for(int j = 1;j<=m;j++){
                    dp[i][j] = 0;
                }
                dp[i][v] = dp[i-1][v];
                if(v>=2){
                    dp[i][v] += dp[i-1][v-1];
                    dp[i][v] %= mod;
                }
                if(v<m){
                    dp[i][v] += dp[i-1][v+1]; dp[i][v] %= mod;
                }
            }
        }
        ll ans = 0;
        for(int i = 1;i<=m;i++){
            ans += dp[n-1][i]; ans %= mod;
        }
        cout << ans;
    }
    
}