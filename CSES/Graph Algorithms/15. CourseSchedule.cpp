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
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 1e5;
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
    #endif
}


// DO NOT FORGET to convert INT to LL before submitting
int main(){
    fastio; judge();
    int n; cin >> n;
    int m; cin >> m; int u,v;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    while(m--){
        cin >> u >> v; u--; v--; adj[u].pb(v); indeg[v]++;
    }

    queue<int>q;
    vector<int>topological_sort;
    for(int i = 0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topological_sort.pb(node);
        for(auto child : adj[node]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    
    if(topological_sort.size()!=n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto x : topological_sort){
            cout << x+1 << ' ';
        }
    }
}