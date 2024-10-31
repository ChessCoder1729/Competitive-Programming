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
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// Check for queue, priorioty_queue, stack, ordered_set solutions
// stack => LIFO (whatever goes in last comes out last)
// queue => FIFO (whatever goes in first comes out first)
// priority_queue => Dynamic queries of minimum/maximum
// ordered_set => set in vector form
//[order_of_key(k) gives number of elements less than k, while find_by_order(i) gives i^th element]

// To comment multiple lines : ctrl + /
// To find and replace : ctrl+H

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<pair<pair<int,int>,int>>v(n);
    for(int i = 0;i<n;i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    sort(v.begin(),v.end());

    vector<pair<int,int>>a(n); vector<int>b(n);
    for(int i = 0;i<n;i++){
        a[i].first = v[i].first.first, a[i].second = v[i].first.second;
        b[i] = v[i].second;
    }

    vector<int>dp(n,-1);
    dp[n-1] = b[n-1];
    for(int i = n-2;i>=0;i--){
        dp[i] = dp[i+1];
        pair<int,int>p = {a[i].second,inf};
        auto it = lower_bound(a.begin()+i,a.end(),p);
        if(it-a.begin()<n){
            dp[i] = max(dp[i],b[i]+dp[it-a.begin()]);
        }
        else{
            dp[i] = max(dp[i],b[i]);
        }
    }
    cout << dp[0];
}