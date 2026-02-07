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

int log_2(int k){
    return 31 - __builtin_clz(k);
}
// Over here for some reason if u replace jump[bit][n] with jump[n][bit] you get TLE???
signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<int>par(n);
    for(int i = 0;i<n;i++){
        cin >> par[i]; par[i]--;
    }
    int bit = 32;
    vector<vector<int>>jump(bit,vector<int>(n));
    for(int i = 0;i<n;i++){
        jump[0][i] = par[i];
    }
    for(int j = 1;j<bit;j++){
        for(int i = 0;i<n;i++){
            jump[j][i] = jump[j-1][jump[j-1][i]];
        }
    }

    auto jumper = [&](auto&& self, int node, int k)->int{
        if(k==0){
            return node;
        }
        int p = log_2(k);
        return self(self,jump[p][node],(k-(1<<p)));
    };

    while(q--){
        int u,k; cin >> u >> k; u--;
        cout << jumper(jumper,u,k) + 1 << endl;
    }
}
