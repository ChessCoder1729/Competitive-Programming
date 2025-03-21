// Insert seg on top
struct HLD {
    vector<int> parent, depth, heavyChild, head, newPos, size; // head denotes head of chain. newPos denotes the newvalue of node wrt dfs
    vector<int> values; // Original values at nodes
    SegTree* seg; 
    int n;

    // calculate subtree sizes and find heavy edges
    int dfs(int v, vector<vector<int>>& adj) {
        int max_size = 0, total_size = 1;
        for (auto child : adj[v]) {
            if (child == parent[v]){
                continue;
            }
            parent[child] = v;
            depth[child] = depth[v] + 1;
            int subtree_size = dfs(child, adj);
            total_size += subtree_size;
            
            if (subtree_size > max_size) {
                max_size = subtree_size;
                heavyChild[v] = child;
            }
        }
        return total_size;  
    }

    // Decompose into heavy paths and assign positions
    void decompose(int v, int h, vector<vector<int>>& adj, int &cur_pos) {
        head[v] = h;
        newPos[v] = cur_pos;
        cur_pos++;
        if(heavyChild[v]!=-1){
            decompose(heavyChild[v],h,adj,cur_pos);
        }
        for (auto child : adj[v]) {
            if (child != parent[v] && child != heavyChild[v]) {
                decompose(child, child, adj, cur_pos);
            }
        }
    }

    void build(int a, vector<vector<int>>& adj, vector<int>& vals){
        n = a;
        parent.resize(n, -1), depth.resize(n);
        heavyChild.resize(n, -1), head.resize(n), newPos.resize(n);
        size.resize(n), values = (vals); 
        dfs(0, adj);
        int tmp = 0;
        decompose(0, 0, adj,tmp);
        vector<int> chain_values(n);
        for (int i = 0; i < n; ++i) {
            chain_values[newPos[i]] = values[i];
        }
        seg = new SegTree;
        seg -> build(chain_values);
    }


    void set_path(int u, int v, int set_val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            seg->set(newPos[head[u]], newPos[u],set_val);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        seg->set(newPos[u], newPos[v],set_val);
    }   

    void set_full(int set_val){
        seg -> set(0,n-1,set_val);
    }

    int par(int vertex){
        return parent[vertex];
    }

    node query_path(int u, int v) {
        node ans; 
        ans.sum = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            ans = unite(ans,seg->query(newPos[head[u]], newPos[u]));
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        ans = unite(ans,seg->query(newPos[u], newPos[v]));
        return ans;
    }
};