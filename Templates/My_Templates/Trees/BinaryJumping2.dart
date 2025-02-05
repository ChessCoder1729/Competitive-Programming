struct bin_node {
	int vertex, jump, par, subSize;
    int depth = 0;
};

struct BinaryJump{
	vector<bin_node> info; int root;
 
	BinaryJump(const vector<vector<int>>& adj, int r) {
		info.resize(adj.size());
        root = r;
		build(root, root, adj);
	}
 
	void build(int node, int par, const vector<vector<int>>& adj) {
        if(node==root){
            info[root].vertex = root;
            info[root].depth = 0;
            info[root].par = info[root].jump = root;
            for(auto child : adj[node]) {
			    build(child, node, adj);
			    info[node].subSize += info[child].subSize;
		    }
            return;
        }
		info[node].vertex = node;
		info[node].depth = info[par].depth + 1;
        info[node].par = par;
        info[node].subSize = 1;
        
        int par2 = info[par].jump;
        if(info[par].depth - info[info[par].jump].depth==info[par2].depth - info[info[par2].jump].depth){
            info[node].jump = info[par2].jump;
        }
        else{
            info[node].jump = par;
        }
        
		for(auto child : adj[node]) {
            if(par==child){
                continue;
            }
			build(child, node, adj);
			info[node].subSize += info[child].subSize;
		}
	}
 
	int kthAncestor(int node, int k) const {
        int sum = 0; // of the dist
		while (true) {
            if(k==0 or node<0 or node==root){
                break;
            }
			if (info[node].depth - info[info[node].jump].depth <= k) {
				k -= info[node].depth - info[info[node].jump].depth;
				node = info[node].jump;
			} 
            else {
				k--;
				node = info[node].par;
			}
		}
		return node;
	}
	//
};