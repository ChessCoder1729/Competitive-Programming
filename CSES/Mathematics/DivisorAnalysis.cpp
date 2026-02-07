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

int qexp(int a, int b, int m = mod) {
    int res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
int inv(int a){
    return qexp(a,mod-2,mod);
}

// Look for edge cases!!!
signed main(){
    fastio; judge();
    int n; cin >> n;
    int num = 1, sum = 1, prod = 1;

    vector<pair<int,int>>a(n);

    for(int i = 0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 0;i<n;i++){
        num = (num*qexp(a[i].first,a[i].second))%mod;
    }

    for(int i = 0;i<n;i++){
        int mul = qexp(a[i].first,a[i].second+1)%mod;
        mul = (mul-1+mod)%mod;
        mul = (mul*inv(a[i].first-1))%mod;
        sum = (sum*mul)%mod;
        // cout << sum << endl;
    }
    int total = 1;
    int total2 = 1;
    bool done = false;
    //cout << total2 << endl;
    for(int i = 0;i<n;i++){
        total = (total*(a[i].second+1))%mod;
        if(!done and a[i].second%2==1){
            total2 = (total2*((a[i].second+1)/2))%(mod-1);
            done = true;
        }
        else{
            total2 = (total2*(a[i].second+1))%(mod-1);
        }
    }
    debug(total,sum);
    //debug(done);
    for(int i = 0;i<n;i++){
        if(done){
            int tmp = total2;
            //cout << tmp << endl;
            tmp = (tmp*a[i].second)%(mod-1);
            //cout << tmp << endl;
            prod = (prod*qexp(a[i].first,tmp))%mod;
        }
        else{
            int tmp = total2;
            tmp = ((ull)(tmp*(a[i].second/2)))%(mod-1);
            prod = ((ull)(prod*qexp(a[i].first,tmp)))%mod;
        }
    }
    debug(prod);
    cout << total << ' ' << sum << ' ' << prod << endl;
}
