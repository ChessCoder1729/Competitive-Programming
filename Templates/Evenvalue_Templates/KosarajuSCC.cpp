class SCC {
  const int n;
  const vector<vector<int>> g;
  vector<vector<int>> gr;

  void build_gr() {
    for (int x = 0; x < n; x++) {
      for (const int y : g[x]) {
        gr[y].push_back(x);
      }
    }
  }

  void build_order(const int x, vector<bool> &visit, vector<int> &order) {
    visit[x] = true;
    for (const int y : g[x]) {
      if (visit[y]) continue;
      build_order(y, visit, order);
    }
    order.push_back(x);
  }

  void build_comp(const int x, const int c) {
    comp[x] = c;
    for (const int y : gr[x]) {
      if (comp[y] != -1) continue;
      build_comp(y, c);
    }
  }

  void kosaraju() {
    vector<int> order;
    order.reserve(n);
    vector<bool> visit(n, false);
    for (int x = 0; x < n; x++) {
      if (visit[x]) continue;
      build_order(x, visit, order);
    }
    int c = 0;
    while (not order.empty()) {
      const int x = order.back();
      order.pop_back();
      if (comp[x] != -1) continue;
      build_comp(x, c++);
    }
  }

public:
  vector<int> comp;

  explicit SCC(const vector<vector<int>> &g) : g(g), n(g.size()), gr(g.size()), comp(g.size(), -1) {
    build_gr();
    kosaraju();
  }
};
