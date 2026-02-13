/// Refer to : https://www.geeksforgeeks.org/dsa/bellman-ford-algorithm-dp-23/

vector<int>parent; // If we need to retrace path just backtrack

// Time Complexity : O(v*e).
// Space : O(v)

// For distance between a given node and any other node(Weights be negative)
// edge_list[i] = {u_i, v_i, w_i}
vector<int> bellman_ford(vector<vector<int>>&edge_list, int src) {
    int n = edge_list.size();
    int upper_limit = 1e9; // this may have to be changed!
    vector<int>dist(n,upper_limit);
    dist[src] = 0;
    for(int i = 0;i<n-1;i++){
        for(auto e : edge_list){
            int u = e[0]; int v = e[1]; int w = e[2];
            if(dist[u]!=upper_limit and dist[v]>dist[u]+w){
                //parent[v] = u;
                dist[v] = dist[u]+w;
            }
        }
    }
    for(auto e :edge_list){
        int u = e[0]; int v = e[1]; int w = e[2];
        if(dist[u]!=upper_limit and dist[v]>dist[u]+w){
            return {-1}; // Negative cycle
        }
    }
    return dist;
}
