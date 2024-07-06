#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
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
    int n; cin >> n;
    vector<ll>a(n);
    for(int i = 0;i<n;i++) cin >> a[i];
    pbds s; int tmp;
    for(int i = 0;i<n;i++){
        s.insert(i);
    }
    for(int i = 0;i<n;i++){
        cin >> tmp; tmp--;
        int pos = *s.find_by_order(tmp);
        cout << a[pos] << ' ';
        s.erase(pos); 
    }
    
    
}