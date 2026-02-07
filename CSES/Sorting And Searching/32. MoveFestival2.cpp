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
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e18;
const ll mod = 1e9+7;

//#define LOCAL // Comment this line before submitting

#ifdef LOCAL
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifdef LOCAL
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif
}


signed main(){
    fastio; judge();
    int n,k; cin >> n >> k;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    auto cmp = [](pair<int,int>&p1, pair<int,int>&p2) ->bool{
        if(p2.second != p1.second){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    };
    sort(all(a),cmp);
    multiset<int>s;
    int cnt = 1;
    s.insert(a[0].second);
    for(int i = 1;i<n;i++){
        auto it = s.upper_bound(a[i].first);
        if(it==s.begin()){
            if((int)(s.size())==k){
                continue;
            }
            s.insert(a[i].second);
            cnt++; continue;
        }
        it--;
        s.erase(it);
        cnt++;
        s.insert(a[i].second);
    }
    cout << cnt;
}
