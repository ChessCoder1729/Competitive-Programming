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
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// Check for queue, priorioty_queue, stack, ordered_set solutions
// stack => LIFO (whatever goes in last comes out last)
// queue => FIFO (whatever goes in first comes out first)
// priority_queue => Dynamic queries of minimum/maximum
// ordered_set => set in vector form
//[order_of_key(k) gives number of elements less than k, while find_by_order(i) gives i^th element]

// To comment multiple lines : ctrl + /
// To find and replace : ctrl+H

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
 
vector<vector<ll>>flyod_warshal(int n, vector<vector<ll>>&edges){
    vector<vector<ll>>matrix(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            matrix[i].push_back(inf);
        }
        matrix[i][i] = 0;
    }
    for(auto e : edges){
        int u = e[0]; int v = e[1]; ll w = e[2];
        matrix[u][v] = min(matrix[u][v],w);
    }
    for (int k = 0; k < n; k++) {
        for (int start = 0; start<n; start++) {
            for (int end = 0; end < n; end++) {
                if (matrix[start][k] < inf && matrix[k][end] < inf)
                    matrix[start][end] = min(matrix[start][end], matrix[start][k] + matrix[k][end]); 
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(matrix[i][i]<0){
            return {{-1}}; // not possible that is negative cycle
        }
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==inf){
                matrix[i][j] = -1;
            }
        }
    }

    return matrix;
} 

signed main(){
    fastio; judge();
    int n,m,q;
    cin >> n >> m >> q;
    int u,v; ll w; vector<vector<ll>>edges;
    while(m--){
        cin >> u >> v >> w;
        edges.pb({u-1,v-1,w}); edges.pb({v-1,u-1,w});
    }

    vector<vector<ll>>ans = flyod_warshal(n,edges);

    while(q--){
        cin >> u >> v; u--; v--;
        cout << ans[u][v] << endl;
    }
}