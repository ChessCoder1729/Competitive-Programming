// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

vector<int>subset_vals(vector<int>&a){
    int n = a.size();
    vector<int>ans;
    for(int i = 0;i<(1<<n);i++){
        int s = 0;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                s += a[j];
            }
        }
        ans.pb(s);
    }
    sort(ans.begin(),ans.end());
    return ans;
}


signed main(){
    fastio; judge();
    int n,x; cin >> n >> x;
    vector<int>a(n);
    for(auto &p : a) cin >> p;

    vector<int>vec1,vec2;
    {
        vector<int>b;
        for(int i = 0;i<n/2;i++){
            b.pb(a[i]);
        }
        vec1 = subset_vals(b);
    }
    {
        vector<int>b;
        for(int i = n/2;i<n;i++){
            b.pb(a[i]);
        }
        vec2 = subset_vals(b);
    }

    int ans = 0;
    for(auto num : vec1){
        if(num>x){
            break;
        }
        auto it1 = lower_bound(vec2.begin(),vec2.end(),x-num);
        auto it2 = upper_bound(vec2.begin(),vec2.end(),x-num);
        ans += (it2-it1);
    }
    cout << ans;
}
