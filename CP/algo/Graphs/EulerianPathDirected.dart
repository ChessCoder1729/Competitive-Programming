/*
1. check_if_euler : Atmost one has indegree - outdegree = 1 and atmost one has indegree-outdegree = -1
rest have indegree = outdegree
2. find_euler_path : Dfs to a node where outdegree = 0 and from there we backtrack
*/

// Watch out for m = 0 (number of edges)
struct EulerainPathDirected{
    vector<vector<int>>adj;
    vector<int>indeg,outdeg,path;
    int edges_count;
    int n;

    void pre_calc(){
        indeg.resize(n,0);
        outdeg.resize(n,0);
        edges_count = 0;
        for(int u = 0;u<n;u++){
            for(auto v : adj[u]){
                edges_count++;
                indeg[v]++;
                outdeg[u]++;
            }
        }
    }

    bool check_if_euler(){
        int start_nodes = 0, end_nodes = 0;
        for(int i = 0;i<n;i++){
            if(abs(indeg[i]-outdeg[i])>1){
                return false;
            }
            start_nodes += (outdeg[i]-indeg[i]==1);
            end_nodes += (indeg[i]-outdeg[i]==1);
        }
        return (start_nodes==end_nodes and end_nodes<=1);
    }

    int find_start_node(){
        for(int i = 0;i<n;i++){
            if(outdeg[i]-indeg[i]==1){
                return i;
            }
        }
        for(int i = 0;i<n;i++){
            if(outdeg[i]>0){
                return i;
            }
        }
    }

    vector<int>query(vector<vector<int>>&vec){
        adj = vec;
        n = (int)(adj.size());
        pre_calc();
        if(!check_if_euler()){
            return {};
        }
        // CRUX OF THE ALGO :
        auto dfs = [&](auto &&self, int node) ->void{
            while((int)(adj[node].size())!=0){
                int child = adj[node].back();
                adj[node].pop_back();
                self(self,child);
            }
            path.pb(node);
        };
        //
        int start = find_start_node();
        dfs(dfs,start);
        reverse(all(path));
        if((int)(path.size())==edges_count+1){ // check if all edges are part of the path
            return path;
        }
        return {};
    }
};
