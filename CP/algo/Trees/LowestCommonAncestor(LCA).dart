/*
Modified SparseTable to return index of RMQ
*/

struct SparseTable{
    pair<int, int> unite(pair<int,int> a, pair<int,int> b){
        if(a.first < b.first){
            return a;
        }
        return b;
    }

    int n;
    int m;
    vector<int>a;
    vector<int>log_2;
    vector<vector<pair<int,int>>>table;

    void init(int N){
        n = N;
        log_2.resize(n+1);
        log_2[0] = log_2[1] = 0;
        for(int i = 2;i<=n;i++){
            log_2[i] = log_2[i/2] + 1;
        }
        m = log_2[n]+1;
        table.resize(n,vector<pair<int,int>>(m));
    }
    void build(vector<int>&vec){
        a = vec;
        pre();
    }

    void pre(){
        for(int i = 0;i<n;i++){
            table[i][0] = {a[i],i};
        }
        for(int j = 1;j<m;j++){
            for(int i = 0;i<n;i++){
                if((i+(1<<j))-1>=n){
                    break;
                }
                table[i][j] = unite(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    int query(int l, int r){
        if(l > r){swap(l,r);}
        int d = r - l + 1;
        int p = log_2[d];
        return unite(table[l][p],table[r-(1<<p)+1][p]).second; // returns the index of the minima
    }
};

/*
LCA in O(1)
*/

struct LCA{
    int n;
    vector<vector<int>>adj;
    vector<int>flatten;
    vector<int>flatten_height; // for every node in euler tour, replace it with its height
    vector<int>first; // first occurence of node u in the euler tour
    vector<int>height; // height of node u
    SparseTable st;


    void euler_tour(int node, int par){
        flatten.pb(node);
        for(auto child : adj[node]){
            if(child==par){
                continue;
            }
            height[child] = height[node]+1;
            euler_tour(child,node);
            flatten.pb(node);
        }
    }


    void init(vector<vector<int>>&vec, int root = 0){
        adj = vec;
        n = (int)(adj.size());
        height.resize(n);
        first.resize(n,-1);

        height[root] = 0;
        euler_tour(root,-1);
        for(int i = 0;i<(int)(flatten.size());i++){
            if(first[flatten[i]]==-1){
                first[flatten[i]] = i;
            }
        }

        for(auto u : flatten){
            flatten_height.pb(height[u]);
        }

        st.init((int)(flatten.size()));
        st.build(flatten_height);
    }

    int query(int u, int v){
        // find index of RMQ in b/w first[u], first[v] in flatten_height
        // This is true, because every node b/w u and v lies b/w first[u], first[v] in euler tour
        int idx = st.query(first[u],first[v]);
        return flatten[idx];
    }
};
