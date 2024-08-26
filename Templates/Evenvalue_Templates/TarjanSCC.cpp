struct Tarjan {
private:
  const int n;
  vector<vector<pair<int, int>>> g;
  vector<vector<int>> groups;
  vector<int> group;

  int dfs(const int x, vector<bool> &visit, vector<bool> &enter) {
    int idx = group[x] + 1;
    visit[x] = enter[x] = true;
    for (const auto [y, w] : g[x]) {
      if (visit[y] and not enter[y]) continue;
      if (not enter[y]) {
        group[y] = idx;
        idx = dfs(y, visit, enter);
      }
      group[x] = min(group[x], group[y]);
    }
    enter[x] = false;
    return idx;
  }

public:
  Tarjan(vector<vector<pair<int, int>>> &graph) : n(graph.size()), g(graph), group(n), groups(n) {
    vector<bool> visit(n);
    vector<bool> enter(n);
    for (int x = 0, idx = 0; x < n; x++) {
      if (visit[x]) continue;
      group[x] = idx;
      idx = dfs(x, visit, enter);
    }
    for (int x = 0; x < n; x++) {
      groups[group[x]].push_back(x);
    }
    groups.erase(remove_if(groups.begin(), groups.end(), [&](const vector<int> &grp) {
                   return grp.empty();
                 }), groups.end());
  }

  int size() const {
    return groups.size();
  }

  int find_group(const int x) {
    return group.at(x);
  }

  vector<int> operator[](const int x) {
    return groups.at(x);
  }
};