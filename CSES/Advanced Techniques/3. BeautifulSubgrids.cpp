#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e18;
const ll mod = 1e9+7;


#ifndef ONLINE_JUDGE
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}


signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<bitset<3000>>vec(n);
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        for(int j = 0;j<n;j++){
            vec[i][j] = (s[j]-'0');
        }
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int x = (vec[i]&vec[j]).count();
            ans += (x*(x-1))/2;
        }
    }
    cout << ans;
}
