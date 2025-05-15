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

int power_9(int d){int ans = 1; while(d--) ans *= 9; return ans;}

bool is_good(int x){
    string s = to_string(x);
    for(int i = 0;i<(int)(s.size())-1;i++){
        if(s[i]==s[i+1]){
            return false;
        }
    }
    return true;
}

int count(int x){
    if(x<=0){
        return x+1;
    }

    string s = to_string(x);
    int d = s.size();
    int ans = 1 + is_good(x);

    ans += (power_9(d) - 9)/8;

    ans += (int)(s[0]-'1')*power_9(d-1);

    for(int i = 1;i<d;i++){
        int lesser = (s[i]-'0') - (s[i-1]<s[i]);
        ans += lesser*power_9(d-i-1);
        if(s[i]==s[i-1]){
            return ans;
        }
    }

    return ans;
}


signed main(){
    fastio; judge();
    int l,r; cin >> l >> r;
    cout << count(r) - count(l-1);
}
