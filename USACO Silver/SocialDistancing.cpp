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
const int N = 1e5;
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
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H


bool isPossible(ll d, int n, int m, vector<pair<ll,ll>>&a){
    int cnt = 1 + (a[0].second-a[0].first)/d;
    ll last = a[0].first + d*((a[0].second-a[0].first)/d);
    for(int i = 1;i<m;i++){
        ll tmp = last;
        last = max(last+d,a[i].first);
        if(last>a[i].second){
            last = tmp;
        }
        else{
            cnt += 1 + (a[i].second-last)/d;
            last = last + d*((a[i].second-last)/d);
        }
    }
    return (cnt>=n);
}
void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main(){
    fastio; //judge();
    usaco("socdist");
    int n,m; 
    cin >> n >> m;
    vector<pair<ll,ll>>a(m);
    for(int i = 0;i<m;i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end());
    ll start = 0; ll end = 1e9; ll ans = -1;
    while(start<=end){
        ll mid = (start+end)/2;
        if(isPossible(mid,n,m,a)){
            ans = mid; start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout << ans;
}