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
    int left,right,maxi,len;
};

class SegTree{
    #define lc x+1
    #define rc 2*(mid-start+1) + x
    
    int n; vector<node>t; vector<int>a;

    node unite(node a, node b){ // Make changes here    
        node ans;
        ans.left = a.left; ans.right = b.right;
        if(a.len==a.left){
            ans.left = a.left + b.left;
        }
        if(b.len==b.right){
            ans.right = b.right + a.right;
        }
        ans.len = a.len + b.len;
        ans.maxi = max({a.maxi,b.maxi,a.right+b.left});
        return ans;
    }

    private:
        void build(int x, int start, int end){ // Make changes here
            if(start==end){
                t[x].left = t[x].right = t[x].maxi = a[start];
                t[x].len = 1;
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
                a[start] = val;
                t[x].left = t[x].right = t[x].maxi = a[start];
                t[x].len = 1;
                return;
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

        void update(int pos, int val){ // Make changes here
            update(0, 0, n - 1, pos, val);
        }
};



signed main(){
    fastio; judge();
    string s; cin >> s;
    int n = s.size();
    vector<int>a(n),b(n);
    for(int i = 0;i<n;i++){
        a[i] = (s[i]-'0');
        b[i] = ('1'-s[i]);
    }

    SegTree seg1(a),seg2(b);

    int q; cin >> q;
    while(q--){
        int idx; cin >> idx; idx--;
        a[idx] = 1 - a[idx];
        b[idx] = 1 - b[idx];
        seg1.update(idx,a[idx]);
        seg2.update(idx,b[idx]);
        cout << max(seg1.query(0,n-1).maxi,seg2.query(0,n-1).maxi) << ' ';
    }
}