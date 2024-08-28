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
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define pb push_back
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
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
vector<int>parent;
vector<ll> unweighted_djikstra(int src, vector<vector<pair<int,ll>>>&adj){
    vector<ll>dist(adj.size(),inf); parent.resize(adj.size());
    deque <int> q;
    dist[src] = 0;
    q.push_back(src);
    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto child : adj[v]){
            if (dist[child.first] > dist[v] + child.second){
                parent[child.first] = v;
                dist[child.first] = dist[v] + child.second;
                if (child.second == 0)
                    q.push_front(child.first);
                else
                    q.push_back(child.first);
            }
        }
    }
    return dist;
}
void add_Edge(int u, int v, ll wt, vector<vector<pair<int,ll>>>&adj){
    u--; v--;
    adj[u].pb({v,wt}); adj[v].pb({u,wt});
}

int main(){
    fastio; judge();    
    int n,m; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n*m); int u,v;
    char a[n][m]; int start =  0; int end = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='A'){
                start = m*i+j; a[i][j] = '.';
            }
            if(a[i][j]=='B'){
                end = m*i+j; a[i][j] = '.';
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j]=='.'){ // m*i + j + 1
                if((j+1 < m and a[i][j+1]=='.')){
                    add_Edge(m*i+j+1,m*i+j+2,1LL,adj);
                }
                if((i+1 < n and a[i+1][j]=='.')){
                    add_Edge(m*i+j+1,m*(i+1)+j+1,1LL,adj);
                }
            }
        }
    }
    vector<ll>dist = unweighted_djikstra(start,adj);
    if(dist[end]==inf){
        pn; return 0;
    }
    py;
    cout << dist[end] << endl;
    int curr = end;
    vector<char>ans;
    while(curr!=start){
        if(parent[curr]==curr+1){
            ans.pb('L');
        }
        else if(parent[curr]==curr-1){
            ans.pb('R');
        }
        else if(parent[curr]>curr){
            ans.pb('U');
        }
        else{
            ans.pb('D');
        }
        curr = parent[curr];
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0;i<ans.size();i++){
        cout << ans[i];
    }
}