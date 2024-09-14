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
vector<ll>dist; vector<ll>cnt; vector<int>mini; vector<int>maxi;

void dijkstra(vector<vector<pair<int,ll>>>&adj, int src){
    int n = adj.size();
    dist[src] = 0; cnt[src] = 1; mini[src] = 1; maxi[src] = 1;
    priority_queue<pair<ll,int>>pq;
    pq.push({0,src});
    
    while(!pq.empty()){
        auto x = pq.top();
        ll d = -1*x.first; int node = x.second;
        pq.pop();
        
        if(d!=dist[node]){ // VERY IMPORTANT (PREVENTS TLE)
            continue;
        }
        for(auto child : adj[node]){
            int v = child.first; ll w = child.second;
            if((d+w)<dist[v]){
                // parent[v]  = node;
                cnt[v] = cnt[node];
                mini[v] = mini[node]+1;
                maxi[v] = maxi[node]+1;
                dist[v] = d+w;
                pq.push({-1*dist[v],v});
            }
            else if((d+w)==dist[v]){
                cnt[v] += cnt[node]; cnt[v] %= mod;
                mini[v] = min(mini[v],mini[node]+1);
                maxi[v] = max(maxi[v],maxi[node]+1);
            }
        }
    }
} 

signed main(){
    fastio; judge();
    int n,m,u,v,w; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n);
    while(m--){
        cin >> u >> v >> w; adj[u-1].pb({v-1,w});
    }

    dist.resize(n); fill(dist.begin(),dist.end(),inf);
    cnt.resize(n); fill(cnt.begin(),cnt.end(),0LL);
    mini.resize(n); fill(mini.begin(),mini.end(),inf);
    maxi.resize(n); fill(maxi.begin(),maxi.end(),0);
    dijkstra(adj,0);
    cout << dist[n-1] << ' ' << cnt[n-1] << ' ' << mini[n-1]-1 << ' ' << maxi[n-1]-1; 
}