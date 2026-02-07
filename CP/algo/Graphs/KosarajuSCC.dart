struct Kosaraju{
    vector<bool>visited;
    vector<vector<int>>components;
    vector<vector<int>>adj_cond;

    void dfs(int v,vector<vector<int>>&adj, vector<int>&output){
        visited[v] = true;
        for(auto u : adj[v]){
            if(!visited[u]){
                dfs(u,adj,output);
            }
        }
        output.push_back(v);
    }

    void strongly_connected_components(vector<vector<int>>&adj){
        int n = adj.size();

        vector<int>order;
        visited.assign(n,false);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj, order);
            }
        }

        vector<vector<int>>adj_rev(n);
        for(int v = 0;v<n;v++){
            for(auto u : adj[v]){
                adj_rev[u].pb(v);
            }
        }

        reverse(all(order));

        vector<int>roots(n,0);
        visited.assign(n,false);
        for(auto v : order){
            if(!visited[v]){

                vector<int>component;
                dfs(v,adj_rev,component);
                components.pb(component);

                int root = *component.begin();
                for(auto u : component){
                    roots[u] = root;
                }
            }
        }

        adj_cond.assign(n,{});
        for(int v = 0;v<n;v++){
            for(auto u : adj[v]){
                if(roots[v]!=roots[u]){
                    adj_cond[roots[v]].pb(roots[u]);
                }
            }
        }
    }
};
// component stores in topologicial order
// adj_cond -> directed graph with cycle to DAG
