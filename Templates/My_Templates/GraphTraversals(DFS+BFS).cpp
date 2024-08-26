struct Graph{
    vector<bool>vis; vector<vector<int>>adj;
    void build(int n, int m){
        vis.resize(n); adj.resize(n); int u,v;
        for(int i = 0;i<m;i++){
            cin >> u >> v; u--; v--;// Check if 0-based index or not
            adj[u].push_back(v); adj[v].push_back(u);
        }
    }
    //DFS
    void dfs(int node){
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]){
                dfs(child);
            }
        }
    }
    // BFS
    void bfs(int start){
        queue<int>q; q.push(start);
        vis[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child:adj[node]){
                if(!vis[child]){
                    q.push(child);
                }
            }
        }
    }
};