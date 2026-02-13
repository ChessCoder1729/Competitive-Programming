struct CoordinateCompression{
    vector<int>d;
    vector<int>a;
    void compress(vector<int>&vec){
        a = vec;
        d = a;
        sort(all(d));
        d.resize(unique(all(d)) - d.begin());
        for(auto &x : a){
            x = lower_bound(all(d),x) - d.begin();
        }
    }
    vector<int>query(){
        return d;
    }
    int initial_val(int idx){
        assert(idx<(int)(d.size()));
        return d[idx];
    }
}
