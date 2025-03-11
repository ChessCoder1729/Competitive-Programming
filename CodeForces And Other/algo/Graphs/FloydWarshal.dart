// For distances between any 2 nodes in graph

// Time Complexity : O(N^3)


vector<vector<ll>>flyod_warshal(vector<vector<pair<int,int>>>&adj){
    int n = adj.size();
    vector<vector<ll>>dist(n, vector<ll>(n,inf));
    for(int i = 0;i<n;i++)dist[i][i] = 0;
    
    for(int node = 0;node<n;node++){
        for(auto [child,wt]:adj[node]){
            dist[node][child] = min(dist[node][child],wt);
        }
    }

    for(int via = 0;via<n;via++){
        for(int start = 0;start<n;start++){
            for(int end = 0;end<n;end++){
                if(dist[start][via]!=inf and dist[via][end]!=inf){
                    dist[start][end] = min(dist[start][end],dist[start][via] + dist[via][end]);
                }
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