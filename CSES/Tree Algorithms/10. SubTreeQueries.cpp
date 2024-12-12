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

struct node{ // Make changes here
    int sum;
};

class SegTree{
    #define lc x+1
    #define rc 2*(mid-start+1) + x
    
    int n; vector<node>t; vector<int>a;

    node unite(node a, node b){ // Make changes here    
        node ans;
        ans.sum = a.sum + b.sum;
        return ans;
    }

    private:
        void build(int x, int start, int end){ // Make changes here
            if(start==end){
                t[x].sum = a[start];
                return;
            }
            int mid = (start+end)/2;
            build(lc,start,mid);
            build(rc,mid+1,end);
            t[x] = unite(t[lc],t[rc]);
            return;
        }

        void update(int x, int start, int end, int idx, int val){
            if(start==end){
                t[x].sum = val; return;
            }
            int mid = (start+end)/2; 
            if(idx<=mid){
                update(lc,start,mid,idx,val);
            }
            else{
                update(rc,mid+1,end,idx,val);
            }
            t[x] = unite(t[lc],t[rc]); return;
        }

        void update_range(int x, int start, int end, int l, int r){
            // if the number of times we update each number is constant
            if(start>r or end<l) return;
            if(start==end){
                //a[start] = 
                return;
            }
            int mid = (start+end)/2; 
            // Insert some if condition, s.t. if operation performed, then no change
            update_range(lc,start,mid,l,r);
            update_range(rc,mid+1,end,l,r);
            t[x] = unite(t[lc],t[rc]); return;
            // Refer to https://codeforces.com/contest/1797/submission/290285800
        }

        node query(int x, int start, int end, int l, int r){
            if(l<=start and end<=r){
                return t[x];
            }
            int mid = (start+end)/2;
            if(r<=mid){
                return query(lc,start,mid,l,r);
            }
            else if(mid<l){
                return query(rc,mid+1,end,l,r);
            }
            else{
                return unite(query(lc,start,mid,l,r),query(rc,mid+1,end,l,r));
            }
        }  
    
    public:
        SegTree(vector<int>& tmp){
            n = tmp.size();
            t.resize(2 * n);
            a = tmp;
            build(0, 0, n - 1);
        }

        node query(int l, int r){
            return query(0, 0, n - 1, l, r);
        }

        void update_range(int l, int r){ // Make changes here
            update_range(0, 0, n - 1, l, r);
        }

        void update(int pos, int val){ // Make changes here
            update(0, 0, n - 1, pos, val);
        }
};


// Flattening a Tree(Euler Tour): [SecondThread Youtube]
// The first time it comes means it is the first time we reached it from the root
// The last time it comes means it is done with it subtree
vector<int>arr = {0};
void dfs(int node, int par, vector<vector<int>>&adj){
    for(auto child : adj[node]){
        if(child==par){
            continue;
        }
        arr.pb(child); dfs(child,node,adj);
    }
    arr.pb(node);
}


signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<vector<int>>adj(n);
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    for(int i = 0,u,v;i<n-1;i++){
        cin >> u >> v; adj[v-1].pb(u-1); adj[u-1].pb(v-1);
    }
    dfs(0,-1,adj);

    vector<int>b(n); // Chaning wrt to ordering
    vector<int>val(n,-1); int curr = 0;
    for(auto x : arr){
        if(val[x]==-1){
            val[x] = curr; curr++;
        }
    }
    for(int i = 0;i<n;i++){
        b[val[i]] = a[i];
    }
    vector<int>end(n); vector<int>cnt(n,0);
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==arr[i-1]){
            end[val[arr[i]]] = val[arr[i]];
        }
        else{
            cnt[arr[i]]++;
            if(cnt[arr[i]]==2){
                end[val[arr[i]]] = end[val[arr[i-1]]];
            }
        }
    }

    SegTree seg(b);
    while(q--){
        int type; cin >> type;
        if(type==2){
            int node; cin >> node; node--;
            cout << seg.query(val[node],end[val[node]]).sum << endl;
        }
        else{
            int node,value; cin >> node >> value; node--;
            seg.update(val[node],value);
        }
    }

}