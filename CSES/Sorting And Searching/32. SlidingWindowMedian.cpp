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


// Look for edge cases!!!
signed main(){
    fastio; judge();
    int n,k; cin >> n >> k;
    multiset<int>s1, s2;
    vector<int>a(n); for(auto &x : a) cin >> x;
    vector<int> ans;
    if(k==1){
        ans = a;
        for(auto x : ans){
            cout << x << ' ';
        }
        return 0;
    }
    if(k==2){
        for(int i = 0;i<n-1;i++){
            ans.pb(min(a[i],a[i+1]));
        }
        for(auto x : ans){
            cout << x << ' ';
        }
        return 0;
    }

    for(int i = 0;i<(k+1)/2;i++) s1.insert(a[i]);
    for(int i = (k+1)/2;i<k;i++){
        auto it = s1.end(); it--;
        if(a[i]<*it){
            s2.insert(*it);
            s1.erase(it);
            s1.insert(a[i]);
        }
        else{
            s2.insert(a[i]);
        }
    }


    auto it = s1.end(); it--; ans.pb(*it);

    for(int i = k;i<n;i++){
        // remove a[i-k]
        auto it = s1.lower_bound(a[i-k]);
        if(it!=s1.end() and *it==a[i-k]){
            s1.erase(s1.find(a[i-k]));
            // if i remove from s1
            // s2 has atleast one element
            if(a[i]<=*s2.begin()){
                s1.insert(a[i]);
            }
            else{
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
                s2.insert(a[i]);
            }
        }
        else{
            s2.erase(s2.find(a[i-k]));
            auto it2 = s1.end(); it2--;
            if(a[i]<=*it2){
                s2.insert(*it2);
                s1.erase(it2);
                s1.insert(a[i]);
            }
            else{
                s2.insert(a[i]);
            }
        }
        auto it3 = s1.end(); it3--;
        ans.pb(*it3);
    }
    // cout << *max_element(ans.begin(),ans.end());
    for(auto x : ans){
        cout << x << ' ';
    }
}
