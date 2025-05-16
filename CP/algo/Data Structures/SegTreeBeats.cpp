struct SegmentTreeBeats {
  using i64 = long long;
  static constexpr i64 INF = numeric_limits<i64>::max() / 2.1;

  struct alignas(32) Node {
    i64 sum = 0, g1 = 0, l1 = 0;
    i64 g2 = -INF, gc = 1, l2 = INF, lc = 1, add = 0;
  };

  vector<Node> v;
  i64 n, log;

  AngelBeats() {}
  AngelBeats(int _n) : AngelBeats(vector<i64>(_n)) {}
  AngelBeats(const vector<i64>& vc) {
    n = 1, log = 0;
    while (n < (int)vc.size()) n <<= 1, log++;
    v.resize(2 * n);
    for (i64 i = 0; i < (int)vc.size(); ++i) {
      v[i + n].sum = v[i + n].g1 = v[i + n].l1 = vc[i];
    }
    for (i64 i = n - 1; i; --i) recalc(i);
  }

  void range_chmin(int l, int r, i64 x) { apply_range<1>(l, r + 1, x); }
  void range_chmax(int l, int r, i64 x) { apply_range<2>(l, r + 1, x); }
  void range_add(int l, int r, i64 x) { apply_range<3>(l, r + 1, x); }
  void range_update(int l, int r, i64 x) { apply_range<4>(l, r + 1, x); }
  i64 range_min(int l, int r) { return query_range<1>(l, r + 1); }
  i64 range_max(int l, int r) { return query_range<2>(l, r + 1); }
  i64 range_sum(int l, int r) { return query_range<3>(l, r + 1); }

 private:
  void recalc(int k) {
    Node& p = v[k];
    Node& l = v[k * 2 + 0];
    Node& r = v[k * 2 + 1];

    p.sum = l.sum + r.sum;

    if (l.g1 == r.g1) {
      p.g1 = l.g1;
      p.g2 = max(l.g2, r.g2);
      p.gc = l.gc + r.gc;
    } else {
      bool f = l.g1 > r.g1;
      p.g1 = f ? l.g1 : r.g1;
      p.gc = f ? l.gc : r.gc;
      p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);
    }

    if (l.l1 == r.l1) {
      p.l1 = l.l1;
      p.l2 = min(l.l2, r.l2);
      p.lc = l.lc + r.lc;
    } else {
      bool f = l.l1 < r.l1;
      p.l1 = f ? l.l1 : r.l1;
      p.lc = f ? l.lc : r.lc;
      p.l2 = min(f ? r.l1 : l.l1, f ? l.l2 : r.l2);
    }
  }

  void apply_add_lazy(int k, i64 x) {
    Node& p = v[k];
    p.sum += x << (log + __builtin_clz(k) - 31);
    p.g1 += x;
    p.l1 += x;
    if (p.g2 != -INF) p.g2 += x;
    if (p.l2 != INF) p.l2 += x;
    p.add += x;
  }

  void apply_chmin_lazy(int k, i64 x) {
    Node& p = v[k];
    p.sum += (x - p.g1) * p.gc;
    if (p.l1 == p.g1) p.l1 = x;
    if (p.l2 == p.g1) p.l2 = x;
    p.g1 = x;
  }

  void apply_chmax_lazy(int k, i64 x) {
    Node& p = v[k];
    p.sum += (x - p.l1) * p.lc;
    if (p.g1 == p.l1) p.g1 = x;
    if (p.g2 == p.l1) p.g2 = x;
    p.l1 = x;
  }

  void push(int k) {
    Node& p = v[k];
    if (p.add != 0) {
      apply_add_lazy(k * 2 + 0, p.add);
      apply_add_lazy(k * 2 + 1, p.add);
      p.add = 0;
    }
    if (p.g1 < v[k * 2 + 0].g1) apply_chmin_lazy(k * 2 + 0, p.g1);
    if (p.l1 > v[k * 2 + 0].l1) apply_chmax_lazy(k * 2 + 0, p.l1);
    if (p.g1 < v[k * 2 + 1].g1) apply_chmin_lazy(k * 2 + 1, p.g1);
    if (p.l1 > v[k * 2 + 1].l1) apply_chmax_lazy(k * 2 + 1, p.l1);
  }

  void apply_chmin_subtree(int k, i64 x) {
    if (v[k].g1 <= x) return;
    if (v[k].g2 < x) {
      apply_chmin_lazy(k, x);
      return;
    }
    push(k);
    apply_chmin_subtree(k * 2 + 0, x);
    apply_chmin_subtree(k * 2 + 1, x);
    recalc(k);
  }

  void apply_chmax_subtree(int k, i64 x) {
    if (x <= v[k].l1) return;
    if (x < v[k].l2) {
      apply_chmax_lazy(k, x);
      return;
    }
    push(k);
    apply_chmax_subtree(k * 2 + 0, x);
    apply_chmax_subtree(k * 2 + 1, x);
    recalc(k);
  }

  template <int cmd>
  inline void apply_to_node(int k, i64 x) {
    if constexpr (cmd == 1) apply_chmin_subtree(k, x);
    if constexpr (cmd == 2) apply_chmax_subtree(k, x);
    if constexpr (cmd == 3) apply_add_lazy(k, x);
    if constexpr (cmd == 4) apply_chmin_subtree(k, x), apply_chmax_subtree(k, x);
  }

  template <int cmd>
  void apply_range(int l, int r, i64 x) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    {
      int l0 = l, r0 = r;
      while (l < r) {
        if (l & 1) apply_to_node<cmd>(l++, x);
        if (r & 1) apply_to_node<cmd>(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l0;
      r = r0;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) recalc(l >> i);
      if (((r >> i) << i) != r) recalc((r - 1) >> i);
    }
  }

  template <int cmd>
  inline i64 identity() {
    if constexpr (cmd == 1) return INF;
    if constexpr (cmd == 2) return -INF;
    return 0;
  }

  template <int cmd>
  inline void combine(i64& a, const Node& b) {
    if constexpr (cmd == 1) a = min(a, b.l1);
    if constexpr (cmd == 2) a = max(a, b.g1);
    if constexpr (cmd == 3) a += b.sum;
  }

  template <int cmd>
  i64 query_range(int l, int r) {
    if (l == r) return identity<cmd>();
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    i64 left = identity<cmd>(), right = identity<cmd>();
    while (l < r) {
      if (l & 1) combine<cmd>(left, v[l++]);
      if (r & 1) combine<cmd>(right, v[--r]);
      l >>= 1;
      r >>= 1;
    }
    if constexpr (cmd == 1) left = min(left, right);
    if constexpr (cmd == 2) left = max(left, right);
    if constexpr (cmd == 3) left += right;
    return left;
  }
};
