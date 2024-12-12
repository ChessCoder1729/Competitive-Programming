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

class Mos {
private:
    vector<int> a;
    int n;
    int block_size;

    // Function to add an element to the current range
    void add(int idx, vector<int>& op, int& current_answer) {
        op[a[idx]]++;
        current_answer += (op[a[idx]]==1);
    }

    // Function to remove an element from the current range
    void remove(int idx, vector<int>& op, int& current_answer) {
        op[a[idx]]--;
        current_answer -= (op[a[idx]]==0);
    }

public:
    struct Query { // to create vector just do vector<Mos::Query>q
        int l, r, idx;  
        
        bool operator<(const Query& q) const {
            int block_size = sqrt(2e5); // Set block size to sqrt(2e5)
            if (l / block_size != q.l / block_size)
                return l / block_size < q.l / block_size;
            return r < q.r;
        }
    };

    // Constructor to initialize the array and precompute the block size
    Mos(const vector<int>& a) : a(a), n(a.size()) {
        block_size = (int)sqrt(2e5);  // Set block size to sqrt(2e5)
    }

    // Function to answer range queries without sorting
    vector<int> processQueries(vector<Query>& queries) {
        vector<int> result(queries.size());
        sort(queries.begin(),queries.end());
        
        vector<int> op(2e5 + 1, 0); // The operation on the element

        int left = 0, right = -1, current_answer = 0;

        // Process each query without sorting
        for (const auto& query : queries) {
            // Move the right pointer to the query's right boundary
            while (right < query.r) { add(++right, op, current_answer); }
            while (right > query.r) { remove(right--, op, current_answer); }

            // Move the left pointer to the query's left boundary
            while (left < query.l) { remove(left++, op, current_answer); }
            while (left > query.l) { add(--left, op, current_answer); }

            // Store the result for the current query
            result[query.idx] = current_answer;
        }

        return result;
    }
};


vector<int>compress(vector<int>&a){
    int cnt = 0; map<int,int>mp;
    for(auto &x : a){
        if(mp.count(x)>0){
            x = mp[x];
        }
        else{
            mp[x] = cnt;
            x = cnt;
            cnt++;
        }
    }
    return a;
}

signed main(){
    fastio; judge();
    int n,q; cin >> n >> q;
    vector<int>a(n); 
    for(auto &x : a) cin >> x;
    a = compress(a);

    Mos mo(a);
    vector<Mos::Query>queries(q);
    for(int i = 0;i<q;i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i; 
        queries[i].l--; queries[i].r--;
    }   

    vector<int>ans = mo.processQueries(queries);
    for(auto x : ans){
        cout << x << endl;
    }
}