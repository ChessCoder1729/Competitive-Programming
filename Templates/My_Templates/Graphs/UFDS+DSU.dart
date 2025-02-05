struct ufds{
    vector<int>par; 
    vector<int>sz; 
    ufds(int n){
        par.resize(n); 
        sz.resize(n);
        for(int i = 0;i<n;i++){
            par[i] = i; sz[i] = 1;
        }
    }
    int get(int u){
        if(u==par[u]) return u;
        return par[u] = get(par[u]);
    }
    void unite(int u, int v){
        //u--; v--;
        u = get(u); v = get(v);
        if(u!=v){
            if(sz[u]>sz[v]){
                swap(u,v);
            }
            par[u] = v;
            sz[v] += sz[u];
        }
    }
}; 