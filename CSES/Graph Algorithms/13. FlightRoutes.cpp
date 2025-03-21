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


signed main(){
    fastio; judge();
    int n,m,u,v,w,k; cin >> n >> m >> k;
    vector<vector<pair<int,ll>>>adj(n);
    while(m--){
        cin >> u >> v >> w; adj[u-1].pb({v-1,w});
    }

    vector<vector<ll>>dist;
    vector<int>tmp;
    for(int i = 0;i<10;i++){
        tmp.pb(inf);
    }
    for(int i = 0;i<n;i++){
        dist.pb(tmp);
    }

    priority_queue<pair<ll,int>>pq;
    pq.push({0,0});
    
    while(!pq.empty()){
        auto x = pq.top();
        ll d = -1*x.first; int node = x.second;
        pq.pop();
        
        if(dist[node].size()== 10 and d>dist[node][9]){ // VERY IMPORTANT (PREVENTS TLE)
            continue;
        }
        for(auto child : adj[node]){
            int v = child.first; ll w = child.second;
            if((d+w)<dist[v][9]){
                // parent[v]  = node;
                dist[v].pop_back();
                dist[v].pb(d+w);
                sort(dist[v].begin(),dist[v].end());
                pq.push({-1*(d+w),v});
                
            }
        }
    }

    for(int i = 0;i<k;i++){
        cout << dist[n-1][i] << ' ';
    }
}