#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<vector<array<int, 2>>> adj(n);
  i64 sum=0;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    sum+=w;
  }
  vector<i64> ans(q);
  vector<vector<array<int, 3>>> qry(n);
  for (int i = 0; i < q; i++) {
    int s, k, t;
    cin >> s >> k >> t;
    s--, k--, t--;
    qry[s].push_back({k, t, i});
  }
  for (int s = 0; s < n; s++) {
    vector<int> in(n), out(n), parent(n, -1);
    vector<i64> dep(n);
    vector<i64> pre(n + 1), suf(n + 1);

    int cnt = 0;
    function<void(int)> dfs = [&](int x) {
      in[x] = cnt++;
      for (auto [y, w] : adj[x]) {
        if (y == parent[x]) {
          continue;
        }
        parent[y] = x;
        dep[y] = dep[x] + w;
        dfs(y);
      }
      out[x] = cnt;
    };
    dfs(s);
    for (int i = 0; i < n; i++) {
      pre[in[i] + 1] = dep[i];
      suf[in[i]] = dep[i];
    }
    for (int i = 1; i <= n; i++) {
      pre[i] = max(pre[i], pre[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = max(suf[i], suf[i + 1]);
    }
    auto anc = [&](int x, int y) { return in[x] <= in[y] && in[y] < out[x]; };
    for (auto [k, t, j] : qry[s]) {
      i64 res = 1E18;
      if (anc(t, k)) {
        ans[j] = -1;
        continue;
      }
      int L = in[k], R = in[k];
      int i;
      for (i = k;; i = parent[i]) {
        res = min(res, 2 * (sum + dep[i]) - max(pre[L], suf[R]));
        L = in[i];
        R = out[i];
        if (anc(i, t)) {
          break;
        }
      }
      res -= 2 * dep[i];
      ans[j] = res;
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i] < 0) {
      cout << "impossible" << endl;
    }
    cout << ans[i] << endl;
  }
  return 0;
}
