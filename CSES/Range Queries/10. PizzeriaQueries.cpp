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
 
struct node{ // Make changes here
    int val;
};
 
class SegTree{
    #define lc x+1
    #define rc 2*(mid-start+1) + x
    
    int n; vector<node>t; vector<int>a;
 
    node unite(node a, node b){ // Make changes here    
        node ans;
        ans.val = min(a.val,b.val);
        return ans;
    }
 
    private:
        void build(int x, int start, int end){ // Make changes here
            if(start==end){
                t[x].val = a[start];
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
                t[x].val = val; return;
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
 
 
signed main(){
    fastio; judge();
    // cost of pk from pi = (pi - i) + k
    int n,q; cin >> n >> q;
 
    vector<int>a(n);
    for(auto &x : a) cin >> x;
 
    vector<int>x1(n),x2(n);
    for(int i = 0;i<n;i++){
        x1[i] = a[i] - i;
        x2[i] = a[i] + i;
    }
 
    SegTree seg1(x1), seg2(x2);
 
    while(q--){
        int type; cin >> type;
        if(type==1){
            int idx,v; cin >> idx >> v; idx--;
            a[idx] = v;
            x1[idx] = a[idx] - idx;
            x2[idx] = a[idx] + idx;
            seg1.update(idx,x1[idx]);
            seg2.update(idx,x2[idx]);
        }
        else{
            int k; cin >> k; k--;
            cout << min(k+seg1.query(0,k).val,-k + seg2.query(k,n-1).val) << endl;
        }
    }
 
}