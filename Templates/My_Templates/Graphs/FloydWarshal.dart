// For distances between any 2 nodes in graph

// Time Complexity : O(N^3)


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