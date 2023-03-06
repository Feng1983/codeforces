#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
template <class T> struct Flow {
  static constexpr int INF = 1e9;
  int n;
  struct Edge {
    int to;
    T cap;
    Edge(int to, T cap) : to(to), cap(cap) {}
  };
  std::vector<Edge> e;
  std::vector<std::vector<int>> g;
  std::vector<int> cur, h;
  Flow(int n) : n(n), g(n) {}
  bool bfs(int s, int t) {
    h.assign(n, -1);
    std::queue<int> que;
    h[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i : g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          if (v == t)
            return true;
          que.push(v);
        }
      }
    }
    return false;
  }
  int dfs(int u, int t, T f) {
    if (u == t)
      return f;
    auto r = f;
    double res = 0;
    for (int &i = cur[u]; i < int(g[u].size()); ++i) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        auto a = dfs(v, t, std::min(r, c));
        res += a;
        e[j].cap -= a;
        e[j ^ 1].cap += a;
        r -= a;
        if (r == 0)
          return f;
      }
    }
    return res;
    //return f - r;
  }
  void addEdge(int u, int v, T c) {
    g[u].push_back(e.size());
    e.emplace_back(v, c);
    g[v].push_back(e.size());
    e.emplace_back(u, 0);
  }
  T maxFlow(int s, int t) {
    T ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, 1E100);
    }
    return ans;
  }
};
// Flow flow(n*n+n+3);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, m;
  cin >> k >> m;

  vector<int> a(m);
  int n=0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    n+=a[i];
  }
  map<vector<int>, int> id;
  int cnt = 0;
  vector<vector<int>> A;
  vector<double> w, wB;
  vector<vector<int>> adj;
  vector<int> c(m);
  double fac = 1;
  for (int i = 1; i < k; i++) {
    fac *= i;
  }
  function<void(int, int, int, double)> dfs1 = [&](int x, int s, int choose,
                                                   double ways) {
    if (x == m) {
      if (s != k || !choose) {
        return;
      }
      id[c] = cnt++;
      wB.push_back(ways);
      return;
    }
    for (int i = 0; i + s <= k && i <= a[x]; i++) {
      if (i) {
        if (!choose) {
          c[x] = -1;
          dfs1(x + 1, s + i, 1, ways);
        }
        ways = ways * (a[x] - i +1)/i;
      }
      c[x] = i;
      dfs1(x + 1, s + i, choose, ways);
    }
  };

  dfs1(0, 0, 0, fac);

  function<void(int, int, double)> dfs = [&](int x, int s, double ways) {
    if (x == m) {
      if (s != k) {
        return;
      }
      A.push_back(c);
      adj.push_back({});
      w.push_back(ways);
      for (int i = 0; i < m; i++) {
        if (c[i]) {
          int x = c[i];
          c[i] = -1;
          adj.back().push_back(id[c]);
          c[i] = x;
        }
      }
      return;
    }
    for (int i = 0; i + s <= k && i <= a[x]; i++) {
      if (i) {
        ways = ways * (a[x] - i + 1) / i;
      }
      c[x] = i;
      dfs(x + 1, s + i, ways);
    }
  };
  dfs(0, 0, 1);
  Flow<double> flow(A.size() + cnt + 2);
  int s = A.size() + cnt;
  int t = s + 1;
  for (int i = 0; i < int(A.size()); i++) {
    flow.addEdge(s, i, w[i]);
    for (auto j : adj[i]) {
      flow.addEdge(i, j + A.size(), 1E100);
    }
  }
  for (int i = 0; i < cnt; i++) {
    flow.addEdge(i + A.size(), t, wB[i]);
  }
  auto ans = flow.maxFlow(s, t);
  for(int i=1;i<=k;i++){
    ans =ans/(n-i+1)*i;
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}
