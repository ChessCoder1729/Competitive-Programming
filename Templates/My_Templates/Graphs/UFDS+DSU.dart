struct ufds{
    vector<ll>par; 
    vector<ll>sz; 
    ufds(ll n){
        par.resize(n); 
        sz.resize(n);
        for(ll i = 0;i<n;i++){
            par[i] = i; sz[i] = 1;
        }
    }
    ll get(ll u){
        if(u==par[u]) return u;
        return par[u] = get(par[u]);
    }
    void unite(ll u, ll v){
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