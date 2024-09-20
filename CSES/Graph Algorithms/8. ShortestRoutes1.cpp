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

vector <ll> dijkstra(vector<vector<pair<int,ll>>>&adj, vector<int>src){
    int n = adj.size();
    vector<ll>dist(n,inf);
    priority_queue<pair<ll,int>>pq;
    for(auto source : src){
        dist[source] = 0;
        pq.push({0,source});
    }
    
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
                dist[v] = d+w;
                pq.push({-1*(d+w),v});
            }
            else if((d+w)==dist[v]){
                // In many problems you will have to do something here
            }
        }
    }
    return dist;
}


signed main(){
    fastio; judge();
    int n,m,u,v; ll w; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n);

    while(m--){
        cin >> u >> v >> w; adj[u-1].pb({v-1,w});
    }

    
    vector<int>dist = dijkstra(adj,{0});
    for(auto x : dist){
        cout << x << ' ';
    }
}