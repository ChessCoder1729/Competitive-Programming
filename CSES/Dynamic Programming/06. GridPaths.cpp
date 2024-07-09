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
int n; ll dp[1001][1001];
int main(){
    fastio; judge();
    cin >> n;
    char c[n][n];
    for(int i = 0;i<n;i++){
        for(int j  = 0;j<n;j++){
            cin>>c[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 1;i<n;i++){
        if(c[0][i]=='.'){
            dp[0][i] = 1;
        }
        else{
            break;
        }
    }
    for(int i = 1;i<n;i++){
        if(c[i][0]=='.'){
            dp[i][0] = 1;
        }
        else{
            break;
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<n;j++){
            if(c[i][j]=='.'){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
    }
    if(c[0][0]=='*'){
        cout << 0;
    }
    else{
        cout << dp[n-1][n-1];
    }
}   