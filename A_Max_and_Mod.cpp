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


// #ifndef ONLINE_JUDGE
// #include "algo/Standard_Stuff/debug.cpp"
// #else
// #define debug(...) 42
// #endif

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

void codeforces_solver(){
    int n; cin >> n;
    if(n%2==0){
        cout << -1 << endl; return;
    }
    cout << n << ' ';
    for(int i = 1;i<n;i++){
        cout << i << ' ';
    }
    cout << endl;
}

signed main(){
    fastio; //judge();
    int tc = 1; cin >> tc;
    for(int testcase = 1;testcase<=tc;testcase++){
        //cout << "Case #" << testcase << ": ";
        codeforces_solver();


        // cout << "------------------------------------------" << endl;
    }
}
