class mo_s {
  struct query {
    int l, r, v, t;
    int ans;

    query(const int l, const int r, const int v, const int t) : l(l), r(r), v(v), t(t), ans(0) {}
  };

  const int kBlockSize = 500;

  const int n;
  const vector<int> a;
  vector<query> queries;

  [[nodiscard]] int block_of(const int i) const {
    return i / kBlockSize;
  }

public:
  explicit mo_s(const vector<int> &a) : n(a.size()), a(a) {}

  void add_query(const int l, const int r, const int v, const int t) {
    queries.emplace_back(l, r, v, t);
  }

  vector<int> solve() {
    sort(queries.begin(), queries.end(), [&](const query &q1, const query &q2) {
      if (block_of(q1.l) != block_of(q2.l)) {
        return (q1.l < q2.l);
      }
      return (block_of(q1.l) & 1 ? q1.r < q2.r : q1.r > q2.r);
    });

    //todo data structure

    auto add = [&](const int i) {
      //todo
    };

    auto rem = [&](const int i) {
      //todo
    };

    for (int i = 0, l = 0, r = -1; i < queries.size(); i++) {
      while (l > queries[i].l) add(--l);
      while (r < queries[i].r) add(++r);
      while (l < queries[i].l) rem(l++);
      while (r > queries[i].r) rem(r--);
      queries[i].ans = 0; //todo
    }

    sort(queries.begin(), queries.end(), [](const query &q1, const query &q2) {
      return q1.t < q2.t;
    });

    vector<int> ans(queries.size());
    for (int i = 0; const query &q : queries) {
      ans[i++] = q.ans;
    }
    return ans;
  }
};
