vector<int>parent; // If we need to retrace path just backtrack

// Time Complexity : O(v*e).
// Space : O(v)

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