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
            //cout << node << ' '; [Based on order of visiting node]
            q.pop();
            for(auto child:adj[node]){
                if(!vis[child]){
                    q.push(child); vis[child] = true;
                }
            }
        }
    }
    void topological_dfs(int node, stack<int>&st){ 
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]) topological_dfs(child,st);
        }
        st.push(child);
    }//for the topological sorting just output the stack 
    vector<int> topological_bfs(){
        queue<int>q;
        vector<int>topological_sort;
        for(int i = 0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topological_sort.pb(node);
            for(auto child : adj[node]){
                indeg[child]--;
                if(indeg[child]==0){
                    q.push(child);
                }
            }
        }
        // if(topological_sort.size()!=n) return false;
        return topological_sort;
    }
};