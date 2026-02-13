struct CentroidDecomposition {
    int n;
    vector<vector<int>> adj;
    vector<int> subtreeSize, parent; // parent denotes parent in centroid tree
    vector<bool> removed;

    void init(vector<vector<int>>&vec){
        adj = vec;
        n = (int)(adj.size());
        subtreeSize.resize(n);
        parent.assign(n, -1);
        removed.assign(n, false);
    }

    int dfsSize(int u, int p) {
        subtreeSize[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !removed[v]) {
                subtreeSize[u] += dfsSize(v, u);
            }
        }
        return subtreeSize[u];
    }

    int dfsCentroid(int u, int p, int total) {
        for (int v : adj[u]) {
            if (v != p && !removed[v] && subtreeSize[v] > total / 2) {
                return dfsCentroid(v, u, total);
            }
        }
        return u;
    }

    void build(int entry, int par) {
        int total = dfsSize(entry, -1);
        int c = dfsCentroid(entry, -1, total);

        parent[c] = par;
        removed[c] = true;

        for (int v : adj[c]) {
            if (!removed[v]) {
                build(v, c);
            }
        }
    }
};