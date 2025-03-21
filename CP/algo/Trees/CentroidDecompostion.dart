struct CentroidDecomp{
    vector<vector<int>>adj;
    vector<int>sz;
    vector<bool>vis;
    vector<int>parent;
    vector<vector<pair<int,int>>>ancestors;
    int main_root;

    void dfs(int node, int par = -1){
        sz[node] = 1;
        for(auto child : adj[node]){
            if(child==par or vis[child]){
                continue;
            }
            dfs(child,node);
            sz[node] += sz[child];
        }
    }

    int get_centroid(int node, int root, int par){
        for(auto child : adj[node]){
            if(child==par or vis[child]){
                continue;
            }
            if(sz[child]*2>sz[root]){
                return get_centroid(child,root,node);
            }
        }
        return node;
    }

    void get_ancestors(int node, int par, int root, int curr_dist = 0){
        if(node!=root) ancestors[node].pb({root,curr_dist});
        for(auto child : adj[node]){
            if(!vis[child] and child!=par){
                get_ancestors(child,node,root,curr_dist+1);
            }
        }
    }

    void decompose(int root, int par = -1){
        dfs(root,par);
        int centroid = get_centroid(root,root,par);

        get_ancestors(centroid,centroid,centroid);
        vis[centroid] = true;

        for(auto child : adj[centroid]){
            if(!vis[child]){
                decompose(child,centroid);
            }
        }
    }

    void update(int node){ // Note that ancestors doesnt contain the node itself

        for(auto [u,d]:ancestors[node]){

        }
    }

    int query(int node){ // Note that ancestors doesnt contain the node itself

        for(auto [u,d]:ancestors[node]){

        }

    }

    void init(int n){
        sz.resize(n);
        vis.assign(n, false);
        ancestors.resize(n);
        parent.resize(n, -1);
    }

    void builder(vector<vector<int>>&tmp){
        adj = tmp;
        decompose(0);
    }
};
