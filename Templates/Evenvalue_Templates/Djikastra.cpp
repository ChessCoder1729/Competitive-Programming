#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kInf = 1e9 + 10;
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;


pair<vector<ll>, vector<int>> dijkstra(const vector<vector<pair<int, ll>>> &g, const vector<int> &s) {
  const int n = (int) g.size();

  vector<ll> d(n, kInf);
  vector<int> p(n, -1);
  min_heap<pair<ll, int>> q;

  for (const int x : s) {
    d[x] = 0;
    q.emplace(0, x);
  }

  while (not q.empty()) {
    const auto [dist, x] = q.top();
    q.pop();
    if (d[x] < dist) continue;
    for (const auto &[y, w] : g[x]) {
      if (d[y] <= d[x] + w) continue;
      d[y] = d[x] + w;
      p[y] = x;
      q.emplace(d[y], y);
    }
  }

  return {d,p};
}