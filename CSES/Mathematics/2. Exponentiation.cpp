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
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define pb push_back
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
void cfsolver(){
    ll a,b;
    cin >> a >> b;
    cout << qexp(a,b,mod) << endl;
}
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    int tc = 1; cin >> tc;
    for(int i = 1;i<=tc;i++){
        //cout << "Testcase #" << i << endl;
        cfsolver();
        // cout << "------------------------------------------" << endl;
    }
}