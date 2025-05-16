class TarjanSCC {
    int V, curr_time;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;

    void dfs(int u, vector<vector<int>>& sccs) {
        disc[u] = low[u] = curr_time++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v, sccs);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            vector<int> scc;
            int v;
            do {
                v = st.top();
                st.pop();
                inStack[v] = false;
                scc.push_back(v);
            } while (v != u);
            sccs.push_back(scc);
        }
    }

public:
    TarjanSCC(int V) : V(V), curr_curr_time(0), adj(V), disc(V, -1), low(V, -1), inStack(V, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        vector<vector<int>> sccs;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i, sccs);
            }
        }
        return sccs;
        // Print all SCCs
        // cout << "Strongly Connected Components:\n";
        // for (const auto& scc : sccs) {
        //     for (int node : scc) {
        //         cout << node << " ";
        //     }
        //     cout << "\n";
        // }
    }
};
