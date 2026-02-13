// Insert Kosaraju above
// https://youtu.be/Ku-jJ0G4tIc?t=863


/*
n is actually 2*number of nodes
1. We have used 1-based indexing for convinience
2. Node i represents:
    Case a) i <= n => i
    Case b) i > n => -
3. After breaking into SCC's and checking if node i, and i+n not in same component
We assign SCC's to be true unless, the verticea have already been assigned
*/

struct Two_SAT{
    vector<int>root;
    vector<vector<int>> components;
    int n;

    void init(int a, vector<int>&rt, vector<vector<int>>&comp){
        root = rt;
        n = a;
        components = comp;
    }
    bool check(){
        for(int i = 1;i<=n/2;i++){
            if(root[i]==root[i+n/2]){
                return false;
            }
        }
        return true;
    }

    vector<int> find(){
        if(!check()){
            return {};
        }
        auto conj = [&](int x){
            if(x<=n/2){
                return n/2 + x;
            }
            return x - n/2;
        };
        vector<int>val(n,0);
        for(int i = (int)(components.size()-1);i>=0;i--){
            for(auto x : components[i]){
                if(val[conj(x)]!=0){
                    val[x] = -val[conj(x)];
                }
                else{
                    val[x] = 1;
                }
            }
        }
        return val;
    }
};
