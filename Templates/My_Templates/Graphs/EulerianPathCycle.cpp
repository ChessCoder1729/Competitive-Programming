vector<vector<int>>build(vector<vector<int>>&adj){// returns {indegree, outdegree}
    int n = adj.size();
    vector<int>in(n,0);
    vector<int>out(n,0);

     for(int node = 0;node<n;node++){
        for(auto child : adj[node]){
            out[node]++; in[child]++;
        }
    }

    return {in,out};

}

void dfs(int node, vector<vector<int>>&adj, vector<int>&in, vector<int>&out, vector<int>&path,map<pair<int,int>,bool>&visited){
    while(out[node]!=0){
        int child = adj[node][out[node]-1];
        out[node]--;
        
        if(!visited[{node,child}]){
            visited[{node,child}] = true;
            // visited[{child,node}] = true; // If it is directed
            dfs(child,adj,in,out,path,visited);
        }
    }
    path.pb(node);
}

int eulerian_check(vector<vector<int>>&adj, vector<int>&in, vector<int>&out){
    int n = adj.size();

    int start = -1; 
    int tmp = -1; // If eulerian cycle i.e. in[i] = out[i] for all
    
    int start_nodes = 0, end_nodes = 0; int cnt_bad = 0;
    for(int i = 0;i<n;i++){
        if(in[i]%2==1){
            cnt_bad++;
        }
        if(in[i]-out[i]==1){
            end_nodes++; 
        }
        if(out[i]-in[i]==1){
            start_nodes++; start = i;
        }
        if(out[i]>0){
            tmp = i;
        }
        if(abs(out[i]-in[i])>1){
            return -1;
        }
    }
    // If you want to choose a specific starting element just make changes here

    // if(cnt_bad>0){ // For cycle
    //     return -1;
    // }
    if((end_nodes==0 and start_nodes==0)){// If you want cycle only this
        return tmp; // If you want specifc start just check if out[start]>0 
    }
    if(end_nodes==1 and start_nodes==1){ 
        return start; // 
    }
    
    return -1;

}

vector<int> eulerian_path(vector<vector<int>>&adj, int num_edges){
    vector<vector<int>>v = build(adj);
    vector<int>in = v[0]; vector<int>out = v[1]; 

    int start_node = eulerian_check(adj,in,out);
    if(start_node==-1){
        return {-1};
    }
    vector<int>path; 
    map<pair<int,int>,bool>visited;
    
    dfs(start_node,adj,in,out,path,visited);

    if(path.size()==num_edges+1){
        reverse(path.begin(),path.end());
        return path;
    }
    return {-1};
}