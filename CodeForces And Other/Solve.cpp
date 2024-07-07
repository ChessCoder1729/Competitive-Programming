#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "Yes" << endl;
#define pn cout << "No" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
vector<ll>a(N);
// 1 BASED INDEXING, build(1,1,n)
struct node {
    // MAKE CHANGES HERE
    ll val = N;
    // UNCHANGED
    ll lzAdd;
    ll lzSet;
    node(){};
};
vector<node>t(4*N);

node unite(node a, node b){
    // MAKE CHANGES HERE
    node ans; 
    ans.val = a.val + b.val;
    return ans;
}

#define lc (x<<1)
#define rc (x<<1)+1

inline void pushup(int x, int start, int end){
    // MAKE CHANGES HERE
    t[x].val = t[lc].val + t[rc].val;
    return;
}

void pushdown(int x, int start, int end) {
    int mid = (start+end)/2;
    // lazy: range fixval
    if (t[x].lzSet != 0) {
      t[lc].lzSet = t[rc].lzSet = t[x].lzSet;
      t[lc].val = (mid - start + 1) * t[x].lzSet;
      t[rc].val = (end - mid) * t[x].lzSet;
      t[lc].lzAdd = t[rc].lzAdd = 0;
      t[x].lzSet = 0;
    } 
       else if (t[x].lzAdd != 0) {  // lazy: range add
       if (t[lc].lzSet == 0) t[lc].lzAdd += t[x].lzAdd;
       else {
         t[lc].lzSet += t[x].lzAdd;
         t[lc].lzAdd = 0;
       }
       if (t[rc].lzSet == 0) t[rc].lzAdd += t[x].lzAdd;
       else {
         t[rc].lzSet += t[x].lzAdd;
         t[rc].lzAdd = 0;
       }
       t[lc].val += (mid - start + 1) * t[x].lzAdd;
       t[rc].val += (end - mid) * t[x].lzAdd;
       t[x].lzAdd = 0;
    }
    return;
}

void build(int x, int start, int end) {
    t[x].lzAdd = t[x].lzSet = 0;
    if (start == end) {
       t[x].val = a[start];
       return;
    }
    int mid = (start + end) >> 1;
    build(lc, start, mid);
    build(rc, mid + 1, end);
    pushup(x,start,end);
    return;
}

void add(int x, int start, int end, int l, int r, ll val) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
       t[x].val += (end - start + 1) * val;
       if (t[x].lzSet == 0) t[x].lzAdd += val;
       else t[x].lzSet += val;
       return;
    }
    int mid = (start + end) >> 1;
    pushdown(x, start, end);
    add(lc, start, mid, l, r, val);
    add(rc, mid + 1, end, l, r, val);
    pushup(x,start,end);
    return;
}

void fixval(int x, int start, int end, int l, int r, ll val) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
       t[x].val = (end - start + 1) * val;
       t[x].lzAdd = 0;
       t[x].lzSet = val;
       return;
    }
    int mid = (start + end) >> 1;
    pushdown(x, start, end);
    fixval(lc, start, mid, l, r, val);
    fixval(rc, mid + 1, end, l, r, val);
    pushup(x,start,end);
    return;
}

node query(int x, int start, int end, int l, int r) {
    if (l > end || r < start){
        // MAKE CHANGES HERE FOR BASED ON FUNCTION OF SEGMENT TREE
        node tmp; tmp.val = 0;
        return tmp;
    }
    if (l <= start && end <= r) return t[x];
    int mid = (start + end) >> 1;
    pushdown(x, start, end);
    return unite(query(lc, start, mid, l, r),query(rc, mid + 1, end, l, r));
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    
}