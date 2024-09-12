#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

struct DistAlgGraphs{
    vector<int>parent; // If we need to retrace path just backtrack
    vector<ll>djikstra(int start, vector<vector<pair<int,ll>>>&adj){
        vector<ll>dist(adj.size(),inf); parent.resize(adj.size());
        dist[start] = 0;
        set<pair<ll,int>>s; // distance, vertex
        s.insert({0LL,start});
        while(!s.empty()){
            auto x = *s.begin(); s.erase(x);
            for(auto child : adj[x.second]){
                if(dist[child.first]>dist[x.second]+child.second){
                    s.erase({dist[child.first],child.first});
                    //parent[child.first] = child.second;
                    dist[child.first] = dist[x.second] + child.second;
                    s.insert({dist[child.first],child.first});
                }
            }
        }
        return dist;    
    } 
    vector<ll> bellman_ford(int n, vector<vector<ll>>& edges, int src) {
        vector<ll>dist(n,1e8);
        dist[src] = 0;
        for(int i = 0;i<n-1;i++){
            for(auto e : edges){
                int u = e[0]; int v = e[1]; ll w = e[2];
                if(dist[u]!=1e8 and dist[v]>dist[u]+w){
                    //parent[v] = u;
                    dist[v] = dist[u]+w;
                }
            }
        }
        for(auto e :edges){
            int u = e[0]; int v = e[1]; int w = e[2];
            if(dist[u]!=1e8 and dist[v]>dist[u]+w){
                return {-1}; // Negative cycle
            }
        }
        return dist;
    }

    vector<vector<ll>>flyod_warshal(int n, vector<vector<ll>>&edges){
        vector<vector<ll>>matrix(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                matrix[i].push_back(inf);
            }
            matrix[i][i] = 0;
        }
        for(auto e : edges){
            int u = e[0]; int v = e[1]; ll w = e[2];
            matrix[u][v] = min(matrix[u][v],w);
        }
        for (int k = 0; k < n; k++) {
            for (int start = 0; start<n; start++) {
                for (int end = 0; end < n; end++) {
                    if (matrix[start][k] < inf && matrix[k][end] < inf)
                        matrix[start][end] = min(matrix[start][end], matrix[start][k] + matrix[k][end]); 
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(matrix[i][i]<0){
                return {{-1}}; // not possible that is negative cycle
            }
        }
        return matrix;
    }
    // If weights = 0,1 [If weights = 1 then just bfs]
    vector<ll>bfs_0_1(int src, vector<vector<pair<int,ll>>>&adj){
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
};