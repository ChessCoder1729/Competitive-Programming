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
    #endif
}
vector<vector<int>>adj; vector<bool>vis; vector<bool>on_stack;
bool yes = false; vector<int>ans;
int bad = -1; bool gotit = false;

void join(int u, int v){
    u--; v--; adj[u].pb(v);
}

bool dfs(int node){
    vis[node] = on_stack[node] = true;
    
    for(auto child : adj[node]){
        if(on_stack[child]){
            //on_stack[child] = true
            bad = child; yes = true;
            ans.pb(child); ans.pb(node);
            return true;
        }
        if(!vis[child]){
            if(dfs(child)){
                // child has cycle
                if(node==bad){
                    ans.pb(node); gotit = true;
                }
                else{
                    if(!gotit){
                        ans.pb(node);
                    }
                }
                return true;
            }
        }
    }

    on_stack[node] = false;
    return false;
}

// DO NOT FORGET to convert INT to LL before submitting
signed main(){
    fastio; judge();
    int n; cin >> n; 
    adj.resize(n); vis.resize(n); on_stack.resize(n);
    fill(vis.begin(),vis.end(),false); 
    fill(on_stack.begin(),on_stack.end(),false);
    int m; cin >> m; int u,v;
    while(m--){
        cin >> u >> v; join(u,v);
    }
    for(int i = 0;i<n;i++){
        if(!vis[i] and !yes){
            yes = dfs(i);
        }
    }
    if(!yes){
        cout << "IMPOSSIBLE"; return 0;
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x+1 << ' ';
    }
}