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
vector<ll>cnt(1000001);
set<int>digits(int n){
    set<int>v;
    while(n>0){
        if(n%10!=0){
            v.insert(n%10);
        }
        n = n/10;
    }    
    return v;
}

int main(){
    fastio; judge(); int n; cin >> n;
    cnt[0] = 0;
    for(int i = 1;i<=9;i++){
        cnt[i] = 1;
    }
    for(int i = 10;i<=n;i++){
        set<int>s = digits(i);
        ll ans = inf;
        for(auto x : s){
            ans = min(ans,1+cnt[i-x]);
        }
        cnt[i] = ans;
    }
    cout << cnt[n];
}