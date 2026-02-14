/*
1. clean(): Creates seperate for self loops & puts an index for every edge & if (u-v) is the i^th edge
we create new adjcancy list s.t. adj[u].pb(i), adj[v].pb(i)
2. pre_calc(): Calculate degree of every vertex, and add phantom edge b/w v1, v2
3. find_start() : We find any possible start, because since we now have an eulerian cycle, then no matter what node
we take in the cycle, it should work

*/

// Watch out for m = 0(number of edges)
struct EulerainPathUndirected{
    vector<vector<int>>adj;
    vector<int>self_edges_count;
    vector<int>deg;
    vector<bool>visited_edge;
    vector<pair<int,int>>edges;
    int edges_count;
    int n;
    int v1 = -1, v2 = -1; // edge be/w odd degree vertices

    void clean(){
        vector<vector<int>>vec(n);
        self_edges_count.resize(n,0);
        int idx = 0;
        for(int u = 0;u<n;u++){
            for(auto v : adj[u]){
                if(u==v){
                    self_edges_count[u]++;
                }
                else if(u<v){
                    vec[u].pb(idx);
                    vec[v].pb(idx);
                    idx++;
                    edges.pb({u,v});
                }
            }
            self_edges_count[u] /= 2;
        }
        adj = vec;
    }


    bool pre_calc(){
        deg.resize(n, 0);

        for(int i = 0;i<n;i++){
            deg[i] = (int)(adj[i].size());
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt += (deg[i]%2);
            if(deg[i]%2==1){
                if(v1==-1){v1 = i;}
                else{v2 = i;}
            }
        }
        if(v1!=-1){
            deg[v1]++;
            deg[v2]++;
            adj[v1].pb((int)(edges.size()));
            adj[v2].pb((int)(edges.size()));
            edges.pb({v1,v2});
        }
        edges_count = (int)(edges.size());
        edges_count += accumulate(all(self_edges_count), 0LL);

        return (cnt==0 or cnt==2);
    }

    int find_start(){
        for(int i = 0;i<n;i++){
            if(deg[i]>0 or self_edges_count[i]>0){
                return i;
            }
        }
    }

    vector<int>query(vector<vector<int>>&vec){
        adj = vec;
        n = (int)(adj.size());
        clean();
        if(!pre_calc()){
            return {};
        }

        visited_edge.resize((int)(edges.size()), false);
        int start = find_start();


        // CRUX of the algo
        vector<int> path;
        auto dfs = [&](auto &&self, int node) ->void{
            while((int)(adj[node].size())!=0){
                int idx = adj[node].back();
                if(visited_edge[idx]){
                    adj[node].pop_back();
                    continue;
                }
                visited_edge[idx] = true;
                int child = edges[idx].first + edges[idx].second - node;
                self(self,child);
            }
            path.pb(node);
            for(int i = 1;i<=self_edges_count[node];i++){
                path.pb(node);
            }
            self_edges_count[node]=0;
        }
        //
        dfs(dfs,start);
        
        // If there is no v1, v2
        if(v1==-1){
            if((int)(path.size())==edges_count+1){
                return path;
            }
            return {};
        }

        // Remove the edge b/w v1 and v2
        for(int i = 0;i<(int)(path.size())-1;i++){
            if((path[i]==v1 and path[i+1]==v2) or (path[i]==v2 and path[i+1]==v1)){
                vector<int>ans;
                for(int j = i+1;j<(int)(path.size());j++){
                    ans.pb(path[j]);
                }
                for(int j = 1;j<=i;j++){
                    ans.pb(path[j]);
                }
                ans.back() = v1 + v2 - ans[0];
                path = ans;
                break;
            }
        }
        edges_count--; // to remove the phantom edge added b/w v1, v2

        if((int)(path.size())==edges_count+1){
            return path;
        }
        return {};
    }
};
