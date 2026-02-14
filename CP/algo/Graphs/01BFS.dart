vector<int>parent; // If we need to retrace path just backtrack

// Time Complexity : O(v+e)

// If weights = 0,1 [If weights = 1 then just bfs]

vector<int>bfs_0_1(int src, vector<vector<pair<int,int>>>&adj){
    vector<int>dist(adj.size(),inf); parent.resize(adj.size());
    deque <int> q;
    dist[src] = 0;
    q.push_back(src);
    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto child : adj[v]){
            if (dist[child.first] > dist[v] + child.second){
                parent[child.first] = v;
                dist[child.first] = dist[v] + child.second;
                if (child.second == 0)
                    q.push_front(child.first);
                else
                    q.push_back(child.first);
            }
        }
    }
    return dist;
}
