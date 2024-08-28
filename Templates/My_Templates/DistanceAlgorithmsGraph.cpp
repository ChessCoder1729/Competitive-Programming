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
                    parent[child.first] = child.second;
                    dist[child.first] = dist[x.second] + child.second;
                    s.insert({dist[child.first],child.first});
                }
            }
        }
        return dist;    
    } 
    // If weights = 0,1
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
};