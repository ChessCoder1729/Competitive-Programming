// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
typedef long double lld;
#define double lld
typedef long long ll;
typedef unsigned long long ull;
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
 
struct node {
    int sum;  // The sum of the range (used for sum queries)
    node(int x = 0){
        sum = x;
    }
};
 
struct lazyNode {
    bool is_set = false;  // Flag for set operation
    int set_val = inf;  // Value for the set operation
    int add_val = 0;  // Value for the add operation
};
 
class LazySegmentTree {
private:
    vector<node> t;
    vector<lazyNode> lazy;
    int n;
    vector<int>a;
    
    #define mid (start+end)/2
    #define lc x + 1 
    #define rc 2*(mid-start+1)+x 
 
    node unite(node a, node b) {
        return node(a.sum+b.sum);
    }
 
    void build(int x, int start, int end) {
        if (start == end) {
            t[x]= node(a[start]); 
            return; 
        } 
        build(lc, start, mid);  
        build(rc, mid + 1, end); 
        t[x] = unite(t[lc], t[rc]);  
    }
 
    void push(int x, int start, int end) {
        if (lazy[x].is_set) {  
 
            t[x].sum = (end - start + 1) * lazy[x].set_val;
 
            if (start != end) {  
                lazy[lc].is_set = true;
                lazy[rc].is_set = true;
                lazy[lc].set_val = lazy[rc].set_val = lazy[x].set_val;
                lazy[lc].add_val = lazy[rc].add_val = 0;
            }
 
            lazy[x].is_set = false;  
        } 
        t[x].sum += (end - start + 1) * lazy[x].add_val;
 
        if (start != end) { 
            lazy[lc].add_val += lazy[x].add_val;
            lazy[rc].add_val += lazy[x].add_val;
        }
 
        lazy[x].add_val = 0; 
    }
 
    void update(int x, int start, int end, int l, int r, int add_value) {
        push(x, start, end); 
 
        if (l <= start && end <= r) {
            if (add_value != 0) { 
                lazy[x].add_val += add_value;
            }
            push(x, start, end);  
            return;
        }
        if(r<=mid){
            push(rc,mid+1,end);
            update(lc,start,mid,l,r,add_value);
        }
        else if(mid<l){
            push(lc,start,mid);
            update(rc,mid+1,end,l,r,add_value);
        }
        else{
            update(lc,start,mid,l,mid,add_value);
            update(rc,mid+1,end,mid+1,r,add_value);
        }
        
        t[x] = unite(t[lc], t[rc]);  // Update current node using unite
    }
 
    void set(int x, int start, int end, int l, int r, int set_value) {
        push(x, start, end); 
 
        if (l <= start && end <=r) {
            lazy[x].is_set = true;
            lazy[x].set_val = set_value;
            lazy[x].add_val = 0;  
            push(x, start, end);  
            return;
        }
 
        if(r<=mid){
            push(rc,mid+1,end);
            set(lc,start,mid,l,r,set_value);
        }
        else if(mid<l){
            push(lc,start,mid);
            set(rc,mid+1,end,l,r,set_value);
        }
        else{
            set(lc,start,mid,l,mid,set_value);
            set(rc,mid+1,end,mid+1,r,set_value);
        }
        t[x] = unite(t[lc], t[rc]); 
    } 
 
    node query(int x, int start, int end, int l, int r) {
        push(x, start, end);  
 
        if (l <= start && end<=r) {
            return t[x];  
        }
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
    LazySegmentTree(vector<int>&tmp) {
        n = tmp.size();
        a = tmp;
        t.resize(2 * n);
        lazy.resize(2 * n);
        build(0, 0, n - 1);  // Build the t using the input array
    }
 
    void update(int l, int r, int add_value) {
        update(0, 0, n - 1, l, r, add_value);
    }
 
    void set(int l, int r, int set_value) {
        set(0, 0, n - 1, l, r, set_value);
    }
 
    node query(int l, int r) {
        node result = query(0, 0, n - 1, l, r);
        return result;  // Return only the sum from the queried node
    }
};
 
signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<int>a(n);
    for(auto &x : a)cin >> x;
    LazySegmentTree seg(a);
 
    while(q--){
        int type; cin >> type;
        if(type==1){
            int l,r,x; cin >> l >> r >> x; l--; r--;
            seg.update(l,r,x);
        }
        else if(type==2){
            int l,r,x; cin >> l >> r >> x; l--; r--;
            seg.set(l,r,x);
        }
        else{
            int l,r; cin >> l >> r; l--; r--;
            cout << seg.query(l,r).sum << endl;
        }
    }
}