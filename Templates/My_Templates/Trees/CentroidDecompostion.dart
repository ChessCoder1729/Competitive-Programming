struct CentroidDecomp{
    vector<vector<int>> adj;
    vector<vector<int>>centroid_adj;
    vector<int>new_par;
    vector<int> subtree_size;
    vector<bool> is_removed;
    vector<vector<pair<int, int>>> ancestors;
    int n,root;

    int get_subtree_size(int node, int parent = -1) {
    	subtree_size[node] = 1;
    	for (auto child : adj[node]) {
    		if (child == parent || is_removed[child]){ 
                continue; 
            }
    		subtree_size[node] += get_subtree_size(child, node);
    	}
    	return subtree_size[node];
    }

    int get_centroid(int node, int tree_size, int parent = -1) {
    	for (auto child : adj[node]) {
    		if (child == parent || is_removed[child]){ 
                continue; 
            }
    		if (subtree_size[child] * 2 > tree_size){
    			return get_centroid(child, tree_size, node);
    		}
    	}
    	return node;
    }
    // distance between node and its centroid
    void get_dists(int node, int centroid, int parent = -1, int curr_dist = 1) {
    	for (auto child : adj[node]) {
    		if (child == parent or is_removed[child]){ 
                continue;
            }
    		curr_dist++;
    		get_dists(child, centroid, node, curr_dist);
    		curr_dist--;
    	}
    	ancestors[node].push_back({centroid, curr_dist});
        if(node!=centroid){
            new_par[node] = centroid;
        }
    }

    void build(int node = 0){
    	int centroid = get_centroid(node, get_subtree_size(node));
        if(root==-1){
            root = centroid;
        }

    	for (auto child : adj[centroid]){
    		if (is_removed[child]) { 
                continue; 
            }
    		get_dists(child, centroid, centroid);
    	}

    	is_removed[centroid] = true;
    	for (auto child : adj[centroid]) {
    		if (is_removed[child]) { 
                continue; 
            }
    		build(child);
    	}
    }

    void init(int x, vector<vector<int>>&tmp){
        n = x;
        root = -1;
        adj = tmp;
        ancestors.resize(n);
        is_removed.assign(n,false);
        subtree_size.resize(n);
        new_par.assign(n,-1);
        build();
    }

    void build_adj(){
        centroid_adj.resize(n);
        for(int i = 0;i<n;i++){
            if(new_par[i]==-1){
                continue;
            }
            centroid_adj[new_par[i]].pb(i);
        }
    }
};