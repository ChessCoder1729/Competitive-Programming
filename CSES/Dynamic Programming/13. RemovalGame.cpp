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

int range(int l, int r, vector<int>&a){
    if(l==0) return a[r]; return a[r] - a[l-1];
}

signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<int>a(n); for(auto &x : a) cin >> x;

    vector<vector<int>>dp(n,vector<int>(n,inf));
    vector<int>psum(n); psum[0] = a[0]; 
    for(int i = 1;i<n;i++) psum[i] = psum[i-1] + a[i];

    for(int d = 0; d<n;d++){
        for(int start = 0;start<n-d;start++){
            int end = start+d;
            if(start==end){
                dp[start][end] = a[start];
            }
            else{
                // If I take from start
                int score1 = a[start] + range(start+1,end,psum) - dp[start+1][end];
                int score2 = a[end] + range(start,end-1,psum) - dp[start][end-1];
                dp[start][end] = max(score1,score2);
            }
        }
    }
    cout << dp[0][n-1];
}