#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "Yes" << endl;
#define pn cout << "No" << endl;
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
    int n,q; cin >> n >> q;
    ordered_set<pair<ll,ll>>s;
    vector<ll>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i]; s.insert({a[i],i});
    }
    while(q--){
        char c; ll p, q; cin >> c >> p >> q;
        if(c=='!'){
            p--;
            s.erase({a[p],p});
            a[p] = q;
            s.insert({a[p],p});
        }
        else{
            cout << s.order_of_key({q,inf}) - s.order_of_key({p-1,inf}) << endl;
        }
    }
}