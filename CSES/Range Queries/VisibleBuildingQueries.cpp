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
        return max(a,b);
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
        int d = r - l + 1;
        int p = log_2[d];
        return unite(table[l][p],table[r-(1<<p)+1][p]);
    }
};

struct FenwickTree {
       int sz;
       vector<int> tree;

       void build(int n) {
         sz = n + 3;
         tree.assign(sz, 0);
       }

       // Returns prefix sum [0, idx]
       int prefix_sum(int idx) const {
         if (idx < 0) return 0;
         int total = 0;
         for (++idx; idx > 0; idx -= idx & -idx) {
           total += tree[idx];
         }
         return total;
       }

       // Returns range sum [left, right]
       int range_sum(int left, int right) const {
         return prefix_sum(right) - prefix_sum(left - 1);
       }

       // Returns value at position pos
       int get(int pos) const {
         return prefix_sum(pos) - prefix_sum(pos - 1);
       }

       // Increments position pos by value
       void increment(int pos, int value) {
         for (++pos; pos < sz; pos += pos & -pos) {
           tree[pos] += value;
         }
       }

       // Applies range update: add value to interval [l, r]
       void apply_range(int l, int r, int value) {
         increment(l, value);
         increment(r + 1, -value);
       }

       // Smallest index i such that prefix_sum(i) >= target
       int find_lower_bound(int target) {
         if (target <= 0) return 0;
         int idx = 0;
         for (int step = 1 << (31 - __builtin_clz(sz)); step > 0; step >>= 1) {
           if (idx + step < sz && tree[idx + step] < target) {
             target -= tree[idx + step];
             idx += step;
           }
         }
         return idx;
       }

       // Smallest index i such that prefix_sum(i) > target
       int find_upper_bound(int target) {
         if (target < 0) return 0;
         int idx = 0;
         for (int step = 1 << (31 - __builtin_clz(sz)); step > 0; step >>= 1) {
           if (idx + step < sz && tree[idx + step] <= target) {
             target -= tree[idx + step];
             idx += step;
           }
         }
         return idx;
       }
     };



signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    vector<int>maxi(n);
    maxi[0] = a[0];
    for(int i = 1;i<n;i++) maxi[i] = max(maxi[i-1],a[i]);
    SparseTable st;
    st.init(n); st.build(a);
    vector<int>prev(n);
    for(int i = 0;i<n;i++){
        int low = 0, high = i-1;
        prev[i] = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(st.query(mid,high)>=a[i]){
                low = mid+1; prev[i] = mid;
            }
            else{
                high = mid-1;
            }
        }
    }
    FenwickTree ft;
    ft.build(n);
    vector<pair<pair<int,int>,int>>queries(q);
    for(int i = 0;i<q;i++){
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
        queries[i].first.first--; queries[i].first.second--;
    }
    auto cmp = [](pair<pair<int,int>,int>p, pair<pair<int,int>,int>q) {
        return p.first.second < q.first.second;
    };
    sort(all(queries),cmp);
    vector<int>answer(q);
    int last = -1;
    for(int i = 0;i<q;i++){
        while(true){
            if(last==queries[i].first.second){
                break;
            }
            last++;
            ft.apply_range(prev[last]+1,last,1);
        }
        answer[queries[i].second] = ft.prefix_sum(queries[i].first.first);
    }
    for(auto x : answer){
        cout << x << endl;
    }
}
