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
    int n; cin >> n;
    vector<pair<pair<int,int>,int>>points(n);
    for(int i = 0;i<n;i++){
        cin >> points[i].first.first >> points[i].first.second;
        points[i].second = i;
    }

    sort(points.begin(),points.end(),[](auto &x, auto &y){
        if(x.first.first!=y.first.first){
            return (x.first.first<y.first.first);
        }
        return (x.first.second>y.first.second);
    });
    debug(points);
    vector<int>contains(n,0);
    ordered_set<pair<int,int>>s;
    for(int i = n-1;i>=0;i--){
        contains[points[i].second] = s.order_of_key({points[i].first.second,inf});
        if(i==0){
            debug(s);
        }
        s.insert({points[i].first.second,i});
    }
    s.clear();
    vector<int>contained_in(n,0);
    for(int i = 0;i<n;i++){
        contained_in[points[i].second] = s.size() - s.order_of_key({points[i].first.second,-1});
        s.insert({points[i].first.second,i});
    }
    for(auto x : contains){
        cout << x << ' ';
    }
    cout << endl;
    for(auto x : contained_in){
        cout << x << ' ';
    }
}
