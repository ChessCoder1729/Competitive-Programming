#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// Check for queue, priorioty_queue, stack, ordered_set solutions
// stack => LIFO (whatever goes in last comes out last)
// queue => FIFO (whatever goes in first comes out first)
// priority_queue => Dynamic queries of minimum/maximum
// ordered_set => set in vector form
//[order_of_key(k) gives number of elements less than k, while find_by_order(i) gives i^th element]

// To comment multiple lines : ctrl + /
// To find and replace : ctrl+H

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    freopen("Error.txt", "w", stderr);
    #define debug(x...) cerr << #x <<" = "; _print(x); cerr << endl;
    #else
    #define debug(x...)
    #endif
}

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

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
            int mx = log2(n) + 1;
            vector<vector<bin_node>>up(n,vector<bin_node>(mx));
            //Base Case : 
            for(int i = 0;i<mx;i++){
                up[0][i].vertex = -1;
            }
            for(int i = 1;i<n;i++){
                up[i][0].vertex = par[i];
            }
            // Jumps 
            for(int i = 1;i<n;i++){
                for(int j = 1;j<mx;j++){
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

        int calc_depth(int node){
            if(depth[node]!=-1){
                return depth[node];
            }
            if(node==0){
                depth[node] = 0; return 0;
            }
            depth[node] = calc_depth(par[node]) + 1;
            return depth[node];
        }

        bin_node calc_lca(int a, int b){
            if(depth[a]>depth[b]){
                swap(a,b);
            }
            bin_node x,y;
            x = kthAncestor(a,depth[b]-depth[a]);
            y = kthAncestor(b,0);
            int low = 0, high = n; bin_node ans;
            while(low<=high){
                int mid = (low+high)/2;
                bin_node p = kthAncestor(x.vertex,mid);
                bin_node q = kthAncestor(y.vertex,mid);
                if(p==q){
                    ans = p;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }   
            return ans;
        }

    public:
        BinaryJump(vector<int>&parent, int r=0){
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
};


signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<int>par(n);
    for(int i = 1,u;i<n;i++){
        cin >> u; par[i] = u-1;
    }

    BinaryJump binjump(par);

    while(q--){
        int u,k; cin >> u >> k; u--;
        int x = binjump.kthAncestor(u,k).vertex;
        if(x==-1){
            cout << -1 << endl;
        }
        else{
            cout << x+1 << endl;
        }
    }
}