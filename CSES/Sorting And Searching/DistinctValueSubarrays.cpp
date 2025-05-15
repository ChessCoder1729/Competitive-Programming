// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
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

void compress(vector<int>&a){
    int n = a.size();
    vector<int>vec;
    map<int,int>mp;
    int curr = 0;
    for(int i = 0;i<n;i++){
        if(mp.count(a[i])){
            vec.pb(mp[a[i]]);
        }
        else{
            mp[a[i]] = curr;
            vec.pb(curr);
            curr++;
        }
    }
    a = vec;
}

// Look for edge cases!!!
signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    compress(a);

    int l = 0, r = 0;
    int ans = 0;
    vector<bool>vis(n,false);

    while(true){
        if(r==n){
            cout << ans; return 0;
        }
        if(!vis[a[r]]){
            vis[a[r]] = true;
            ans += r - l + 1;
            r++;
        }
        else{
            vis[a[l]] = false;
            l++;
        }
    }
}
