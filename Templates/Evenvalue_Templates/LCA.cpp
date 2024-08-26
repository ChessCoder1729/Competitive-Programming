class TreeAnc {
  const int n;
  const vector<vector<int>> g;

  vector<vector<int>> st;
  vector<int> tin;
  vector<int> tout;

  int lg;

  int dfs(const int x, const int p = -1, int time = 0) {
    tin[x] = time++;
    st[x][0] = p;
    for (const int y : g[x]) {
      if (y == p) continue;
      time = dfs(y, x, time);
    }
    tout[x] = time++;
    return time;
  }

public:
  explicit TreeAnc(const vector<vector<int>> &g, const int root = 0) : g(g), n(g.size()), tin(n), tout(n), lg(ceil(log2(n))) {
    st.assign(n, vector<int>(lg + 1));
    dfs(root);
    for (int j = 1; j <= lg; j++) {
      for (int i = 0; i < n; i++) {
        const int anc = st[i][j - 1];
        st[i][j] = anc == -1 ? -1 : st[anc][j - 1];
      }
    }
  }

  bool is_anc(const int x, const int y) {
    return (tin[x] <= tin[y]) and (tout[x] >= tout[y]);
  }

  int lca(int x, const int y) {
    if (is_anc(x, y)) return x;
    if (is_anc(y, x)) return y;
    for (int j = lg; j >= 0; j--) {
      const int anc = st[x][j];
      if (anc != -1 and not is_anc(anc, y)) {
        x = anc;
      }
    }
    return st[x][0];
  }
};
A.cpp
2 KB