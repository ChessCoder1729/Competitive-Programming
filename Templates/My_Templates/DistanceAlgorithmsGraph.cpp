#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

struct DistAlgGraphs{
vector<int>parent; // If we need to retrace path just backtrack

    // For distance between a given node and any other node, edges>=0
vector <ll> dijkstra(vector<vector<pair<int,ll>>>&adj, vector<int>&src){
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
// For distance between a given node and any other node(Weights be negative)
vector<ll> bellman_ford(vector<vector<ll>>& adj, int src) {
    int n = adj.size();
    vector<ll>dist(n,1e8);
    dist[src] = 0;
    for(int i = 0;i<n-1;i++){
        for(auto e : adj){
            int u = e[0]; int v = e[1]; ll w = e[2];
            if(dist[u]!=1e8 and dist[v]>dist[u]+w){
                //parent[v] = u;
                dist[v] = dist[u]+w;
            }
        }
    }
    for(auto e :adj){
        int u = e[0]; int v = e[1]; int w = e[2];
        if(dist[u]!=1e8 and dist[v]>dist[u]+w){
            return {-1}; // Negative cycle
        }
    }
    return dist;
}
// For distances between any 2 nodes in graph
vector<vector<ll>>flyod_warshal(int n, vector<vector<ll>>&adj){
    vector<vector<ll>>dist(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            dist[i].push_back(inf);
        }
        dist[i][i] = 0;
    }
    for(auto e : adj){
        int u = e[0]; int v = e[1]; ll w = e[2];
        dist[u][v] = min(dist[u][v],w);
    }
    for (int k = 0; k < n; k++) {
        for (int start = 0; start<n; start++) {
            for (int end = 0; end < n; end++) {
                if (dist[start][k] < inf && dist[k][end] < inf)
                    dist[start][end] = min(dist[start][end], dist[start][k] + dist[k][end]); 
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(dist[i][i]<0){
            return {{-1}}; // not possible that is negative cycle
        }
    }
    return dist;
}
// If weights = 0,1 [If weights = 1 then just bfs]
vector<ll>bfs_0_1(int src, vector<vector<pair<int,ll>>>&adj){
    vector<ll>dist(adj.size(),inf); parent.resize(adj.size());
    deque <int> q;
    dist[src] = 0;
    q.push_back(src);
    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto child : adj[v]){
            if (dist[child.first] > dist[v] + child.second){
                parent[child.first] = v;
                dist[child.first] = dist[v] + child.second;
                if (child.second == 0)
                    q.push_front(child.first);
                else
                    q.push_back(child.first);
            }
        }
    }
    return dist;
}
};