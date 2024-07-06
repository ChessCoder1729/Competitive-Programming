#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 2e5;
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
vector <ll> a(n);
 
struct node{
    //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
    long long sum;
};
vector <node> t(4*n);
#define lc (x<<1)
#define rc (x<<1) + 1
 
node unite(node a, node b){
    //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
 
void build(int x, int start, int end){
    if(start==end){
        // MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
        t[x].sum = a[start]; return;
    }
    int mid = (start+end)/2;
    build(lc,start,mid);
    build(rc,mid+1,end);
    t[x] = unite(t[lc],t[rc]);
    return;
}
 
void update(int x, int start, int end, int idx, int val){
    if(start==end){
        //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
        t[x].sum= val; return;
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
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
 
int main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    for(int i = 1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while(q--){
        int l,r; cin >> l >> r;
        cout << query(1,1,n,l,r).sum << endl;
    }   
}