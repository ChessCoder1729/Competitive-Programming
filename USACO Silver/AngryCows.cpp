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
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 5e4;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}


bool isPossible(ll r,vector<ll>&a, int n, int k){
    int cnt = 0; ll far = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>far){
            cnt++; far = a[i] + 2*r;
        }
    }
    return (cnt<=k);
}

// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; //judge();
    usaco("angry");
    int n,k; cin >> n >> k;
    vector<ll>a(n); 
    for(int i = 0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll start = 0; ll end = 1e9; ll ans = 1e9;
    while(start<=end){
        ll mid = (start + end)/2;
        if(isPossible(mid,a,n,k)){
            ans = mid; end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    cout << ans << endl;
}