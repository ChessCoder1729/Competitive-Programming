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
ll dp[1000001];

int main(){
    fastio; judge();
    int n; int x; cin >> n >> x;
    vector<int>coins(n);
    for(int i = 0;i<n;i++) cin >> coins[i];
    sort(coins.begin(),coins.end());
    dp[0] = 1;
    for(int j = 0;j<n;j++){
        for(int i = 0;i<=x;i++){
            if(i>=coins[j]){
                dp[i] += dp[i-coins[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x];
}