struct bin_node{
    int vertex;
    // The other stuff like max

    bool operator==(const bin_node &b){
        return vertex==b.vertex;
    }
};

bin_node unite(bin_node a, bin_node b){ // Order is very imp
    bin_node ans;
    ans.vertex = b.vertex;
    return ans;
}

// Root is 0
class BinaryJump{
    vector<vector<bin_node>>up; vector<int>depth; int n;
    vector<int>par;
    private:
        vector<vector<bin_node>>build(vector<int>&par){
            int n = par.size();
            int mx = log2(n) + 2;
            vector<vector<bin_node>>up(n,vector<bin_node>(mx));
            //Base Case : 
            for(int i = 0;i<mx;i++){
                up[0][i].vertex = -1;
            }
            for(int i = 1;i<n;i++){
                up[i][0].vertex = par[i];
            }
            // Jumps 
            for(int j = 1;j<mx;j++){
                for(int i = 1;i<n;i++){
                    bin_node parent = up[i][j-1];
                    if(parent.vertex==-1){
                        up[i][j].vertex = -1;
                    }
                    else{
                        up[i][j] = unite(parent,up[parent.vertex][j-1]);
                    }
                }
            }
            return up;
        }

        bin_node kth(int node, int k){
            if(k>n){
                bin_node ans; ans.vertex = -1;
                return ans;
            }
            bin_node ans; 
            ans.vertex = node;
            while(true){
                if(k==0 or ans.vertex==-1){
                    return ans;
                }
                int p = log2(k);
                ans = unite(ans,up[ans.vertex][p]);
                k -= (1<<p);
            }
        }

        void calc_depth(int node){
            if(depth[node]!=-1){
                return;
            }
            if(node==0){
                depth[node] = 0; return;
            }
            calc_depth(par[node]);
            depth[node] = depth[par[node]] + 1;
        }

        bin_node calc_lca(int a, int b){
            if(depth[a]>depth[b]){
                swap(a,b);
            }
            bin_node x,y;
            x = kth(a,0);
            y = kth(b,depth[b]-depth[a]);
            bin_node ans = x;
            ans = unite(ans,y);
            if(x==y){
                return y;
            }
            // Loop over the i
            for(int i = log2(n)+1;i>=0;i--){
                auto p = kth(x.vertex,(1<<i));
                auto q = kth(y.vertex,(1<<i));
                if(p==q){
                    continue;
                }
                else{
                    ans = unite(ans,p);
                    ans = unite(ans,q);
                    x = p; y = q;
                }
            }
            ans = unite(ans,kth(x.vertex,1));
            ans = unite(ans,kth(y.vertex,1));
            return ans;
        }

    public:
        BinaryJump(vector<int>&parent){
            par = parent;
            n = par.size();
            up = build(par);
            depth.resize(n,-1);
            for(int i = 0;i<n;i++){
                calc_depth(i);
            }
        }
        bin_node kthAncestor(int node, int k){
            return kth(node,k);
        }
        bin_node lca(int a, int b){
            return calc_lca(a,b);
        }
        int deep(int a){
            return depth[a];
        }
};