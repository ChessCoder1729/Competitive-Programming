// DFS
void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child,adj,vis);
        }
    }
}

// BFS
void bfs(int start,vector<vector<int>>&adj, vector<bool>&vis){
    queue<int>q; q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child:node){
            if(!vis[child]){
                q.push(child);
            }
        }
    }
}