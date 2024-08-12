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
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    int t; cin >> t;
    while(t--){
        int n,x; cin >> n >> x;
        set<int>s;
        vector<int>a(n);
        for(int i = 0;i<n;i++) cin >> a[i];
        int cnt = 1;  s.insert(a[0]);
        for(int i = 1;i<n;i++){
            if(x%a[i]==0){
                vector<int>v = {a[i]};
                for(auto d : s){
                    if((x/a[i])%d==0){
                        v.pb(d*a[i]);
                    }
                }
                for(auto x : v){
                    s.insert(x);
                }
                if(s.count(x)>=1){
                    cnt++; s.clear(); s.insert(a[i]);
                }
            }
        }
        cout << cnt << endl;
    }
}