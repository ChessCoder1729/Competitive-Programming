vector<int> build_topo(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>indeg(n);
    for(int i = 0;i<n;i++){
        for(auto v : adj[i]){
            indeg[v]++;
        }
    }
    queue<int>q; // Sometimes even priority queue if you want lexicographically minimum topo
    for(int i = 0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front(); q.pop();
        topo.pb(node);
        for(auto child : adj[node]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    if(topo.size()<n){
        return {-1};
    }
    return topo;
}
