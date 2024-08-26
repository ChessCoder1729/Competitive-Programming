vector<int>djikstra(int start, vector<vector<pair<int,int>,int>>&adj){
    vector<int>dist;
    dist[start] = 0;
    set<pair<int,int>,int>s; // distance, vertex
    while(!s.empty()){
        auto x = *s.begin(); s.erase(x);
        for(auto child : adj[x.second]){
            if(dist[child.first]>dist[x.second]+child.second){
                s.erase({dist[child.first],child.first});
                dist[child.first] = dist[x.second] + child.second;
                s.insert({dist[child.first],child.first});
            }
        }
    }
    return dist;
}