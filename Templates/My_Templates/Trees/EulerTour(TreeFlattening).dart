// Flattening a Tree(Euler Tour): [SecondThread Youtube]
// The first time it comes means it is the first time we reached it from the root
// The last time it comes means it is done with it subtree
vector<int>arr = {0};
void dfs(int node, int par, vector<vector<int>>&adj){
    for(auto child : adj[node]){
        if(child==par){
            continue;
        }
        arr.pb(child); dfs(child,node,adj);
    }
    arr.pb(node);
}

// Special for exclusively subtree
int timer = 0;
void euler_tour(int node, int par) {
	start[node] = timer++;
	for (auto child : neighbors[node]) {
		if(child!=par){
            euler_tour(child,node);
        }
	}
	end[node] = timer;
    start[node]--; end[node]--; // for 0 based indexing
}
