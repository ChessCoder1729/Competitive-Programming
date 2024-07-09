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
int dp[1000][100001]; vector<int>h(1000); vector<int>s(1000);

int main(){
    fastio; judge();
    int n,x; cin >> n >> x;
    for(int i = 0;i<n;i++) cin >> h[i];
    for(int i = 0;i<n;i++) cin >> s[i];
    for(int i = 0;i<=x;i++){
        //dp[n-1][i]
        if(h[n-1]>i){
            dp[n-1][i] = 0;
        }
        else{
            dp[n-1][i] = s[n-1];
        }
    }
    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=x;j++){
            if(h[i]>j){
                dp[i][j]  = dp[i+1][j];
            }
            else{
                dp[i][j] = max(dp[i+1][j],s[i]+dp[i+1][j-h[i]]);
            }
        }
    }
    cout << dp[0][x];
}