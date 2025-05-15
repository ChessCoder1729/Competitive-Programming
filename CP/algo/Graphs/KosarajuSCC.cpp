vector<vector<int>>kosaraju(vector<vector<int>>&adj){
    int n = adj.size();
    vector<bool>vis(n,false);
    stack<int>s;

    auto dfs1 = [&](auto&& self, int node) -> void{
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]){
                self(self,child);
            }
        }
        s.push(node);
    };
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs1(dfs1,i);
        }
    }

    vector<vector<int>>rev_adj(n);
    for(int u = 0;u<n;u++){
        for(auto v : adj[u]){
            rev_adj[v].pb(u);
        }
    }
    fill(vis.begin(),vis.end(),false);
    auto dfs2 = [&](auto&& self, int node, vector<int>&curr) -> void{
        vis[node] = true;
        curr.pb(node);
        for(auto child : rev_adj[node]){
            if(!vis[child]){
                self(self,child,curr);
            }
        }
    };
    vector<vector<int>>components;

    while(true){
        if(s.size()==0){
            break;
        }
        int node = s.top(); s.pop();
        if(vis[node]){
            continue;
        }
        vector<int>vec;
        dfs2(dfs2,node,vec);
        components.pb(vec);
    }

    return components;
}
