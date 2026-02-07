// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e18;
const ll mod = 1e9+7;

//#define LOCAL // Comment this line before submitting

#ifdef LOCAL
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifdef LOCAL
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif
}
/*
Works by uniting the answers for [l,l+power of 2] and [r-power of 2, r] such that the 2 intersect
So it works for all functions, such that repeatedly doing function doesnt change value
*/

struct SparseTable{

    int unite(int a, int b){
        return min(a,b);
    }

    int n;
    int m;
    vector<int>a;
    vector<int>log_2;
    vector<vector<int>>table;

    void init(int N){
        n = N;
        log_2.resize(n+1);
        log_2[0] = log_2[1] = 0;
        for(int i = 2;i<=n;i++){
            log_2[i] = log_2[i/2] + 1;
        }
        m = log_2[n]+1;
        table.resize(n,vector<int>(m,-1));
    }
    void build(vector<int>&vec){
        a = vec;
        pre();
    }

    void pre(){
        for(int i = 0;i<n;i++){
            table[i][0] = a[i];
        }
        for(int j = 1;j<m;j++){
            for(int i = 0;i<n;i++){
                if((i+(1<<(j)))-1>=n){
                    break;
                }
                table[i][j] = unite(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    void print_all(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << table[i][j] << ' ';
            }
            cout << endl;
        }
    }

    int query(int l, int r){
        if (l > r){
            swap(l, r);
        }
        l = max(l,0LL);
        int d = r - l + 1;
        int p = log_2[d];
        return unite(table[l][p],table[r-(1<<p)+1][p]);
    }
};


signed main(){
    fastio; judge();
    int n,a,b; cin >> n >> a >> b;
    vector<int>vec(n);
    for(auto &x : vec) cin >> x;
    vector<int>pref(n+1);
    pref[0] = 0;
    for(int i = 0;i<n;i++){
       pref[i+1] = pref[i] + vec[i];
    }
    SparseTable st;
    st.init(n);
    st.build(pref);
    int ans = pref[a];
    for(int i = a+1;i<=n;i++){
        int p = st.query(i-b,i-a);
        ans = max(ans,pref[i]-p);
    }
    cout << ans;
}
