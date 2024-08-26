template<typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
  const int n;
  vector<vector<T>> table;
  const F unite;

public:
  explicit SparseTable(const vector<T> &a, const F &f) : n(static_cast<int>(a.size())), unite(f) {
    int log = 32 - __builtin_clz(n);
    table.resize(log);
    table[0] = a;
    for (int j = 1; j < log; j++) {
      table[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        table[j][i] = unite(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(const int l, const int r) const {
    assert(0 <= l && l <= r && r <= n - 1);
    const int log = 32 - __builtin_clz(r - l + 1) - 1;
    return unite(table[log][l], table[log][r - (1 << log) + 1]);
  }
};