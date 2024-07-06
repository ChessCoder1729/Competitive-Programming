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
    long long mini;
};
vector <node> t(2*n);
 
node unite(node a, node b){
    //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
    node ans;
    ans.mini = min(a.mini,b.mini);
    return ans;
}
 
void build(int x, int start, int end){
    if(start==end){
        // MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
        t[x].mini = a[start]; return;
    }
    int mid = (start+end)/2;
    int y = 2*(mid-start+1) + x;
    build(x+1,start,mid);
    build(y,mid+1,end);
    t[x] = unite(t[x+1],t[y]);
    return;
}
 
void update(int x, int start, int end, int idx, int val){
    if(start==end){
        //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
        t[x].mini= val; return;
    }
    int mid = (start+end)/2; int y = 2*(mid-start+1) + x;
    if(idx<=mid){
        update(x+1,start,mid,idx,val);
    }
    else{
        update(y,mid+1,end,idx,val);
    }
    t[x] = unite(t[x+1],t[y]); return;
}
 
node query(int x, int start, int end, int l, int r){
    if(l<=start and end<=r){
        return t[x];
    }
    int mid = (start+end)/2;
    int y = 2*(mid-start+1) + x;
    if(r<=mid){
        return query(x+1,start,mid,l,r);
    }
    else if(mid<l){
        return query(y,mid+1,end,l,r);
    }
    else{
        return unite(query(x+1,start,mid,l,r),query(y,mid+1,end,l,r));
    }
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
 
int main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    for(int i = 0;i<n;i++) cin >> a[i];
    build(0,0,n-1);
    while(q--){
        int p; cin >> p;
        if(p==2){
            int l,r; cin >> l >> r;
            cout << query(0,0,n-1,l-1,r-1).mini << endl;
        }
        else{
            int k,u; cin >> k >> u;
            update(0,0,n-1,k-1,u);
        }
    }   
}