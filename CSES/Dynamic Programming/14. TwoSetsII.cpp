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
        int n; cin >> n;
        int sum = n*(n+1)/2;
        if(sum%2==1){
            cout << 0; return 0;
        }
        sum /= 2;
        ll dp[n+1][sum+1]; dp[1][0] = 0; dp[1][1] = 1;
        for(int i = 2;i<=sum;i++){
            dp[1][i] = 0;
        }
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<i;j++){
                dp[i][j] = dp[i-1][j];
            }
            for(int j = i;j<=sum;j++){
                dp[i][j] = (dp[i-1][j-i]+dp[i-1][j])%mod;
            }
        }
        cout << dp[n][sum];
    }
    
}