// For finding the Minimum Spanning Tree

struct ufds{
    vector<ll>par; 
    vector<ll>sz; 
    void build(ll n){
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

void kruskal(int n, vector<pair<ll,pair<int,int>>>&edges){ // {weight,{u,v}}
    
    int mstweight = 0; // Weight of mst
    vector<pair<int,int>>mst; // Edges in mst

    sort(edges.begin(),edges.end());

    ufds p; p.build(n);

    for(auto edge : edges){
        ll weight = edge.first;
        int u = edge.second.first; int v = edge.second.second;

        if(p.get(u)!=p.get(v)){
            mstweight += weight;
            mst.pb({u,v});
            p.unite(u,v);
        }
    }
}