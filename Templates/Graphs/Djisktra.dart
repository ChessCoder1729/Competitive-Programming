vector<int>parent; // If we need to retrace path just backtrack

// Time Complexity : O(E + V logV)

// For distance between a given node and any other node, edges>=0
vector <int> dijkstra(vector<vector<pair<int,int>>>&adj, vector<int>&src){
    int n = adj.size();
    vector<int>dist(n,inf);
    priority_queue<pair<int,int>>pq;
    for(auto source : src){
        dist[source] = 0;
        pq.push({0,source});
    }
    
    while(!pq.empty()){
        auto x = pq.top();
        int d = -1*x.first; int node = x.second;
        pq.pop();
        
        if(d!=dist[node]){ // VERY IMPORTANT (PREVENTS TLE)
            continue;
        }
        for(auto child : adj[node]){
            int v = child.first; int w = child.second;
            if((d+w)<dist[v]){
                // parent[v]  = node;
                dist[v] = d+w;
                pq.push({-1*(d+w),v});
            }
            else if((d+w)==dist[v]){
                // In many problems you will have to do something here
            }
        }
    }
    return dist;
}