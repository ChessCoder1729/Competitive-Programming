#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
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
vector <ll> a(N);
// 1 BASED INDEXING, build(1,1,n) 
struct node{
    //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
    long long val;
};
vector <node> t(4*N);
#define lc (x<<1)
#define rc (x<<1) + 1
 
node unite(node a, node b){
    //MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
    node ans;
    if(a.val>b.val){
        ans.val = a.val; 
    }
    else{
        ans.val = b.val;
    }
    return ans;
}
 
void build(int x, int start, int end){
    if(start==end){
        // MAKE CHANGES HERE FOR DIFFERENT THINGS IN NODE
        t[x].val = a[start]; return;
    }
    int mid = (start+end)/2;
    build(lc,start,mid);
    build(rc,mid+1,end);
    t[x] = unite(t[lc],t[rc]);
    return;
}
 
void update(int x, int start, int end, ll q){
    if(start==end and a[start]>=q){
        cout << start << ' ';
        a[start] -= q; t[x].val -= q;
        return;
    }
    int mid = (start+end)/2;
    if(t[lc].val>=q){
        update(lc,start,mid,q);
    }
    else if(t[rc].val>=q){
        update(rc,mid+1,end,q);
    }
    else{
        cout << 0 << ' ';
        return;
    }
    t[x] = unite(t[lc],t[rc]); return;
}

// to comment multiple lines at once ctrl+/
// Find     and replace Ctrl+H

int main(){
    fastio; judge();
    int n,m; cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    ll q;
    while(m--){
        cin >> q;
        update(1,1,n,q);
    }
}