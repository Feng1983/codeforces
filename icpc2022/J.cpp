#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, q;
  cin >> m >> n >> q;
  vector<string> type(n);
  vector<int> x(n), y(n), z(n);
  int mx = 1;
  for (int i = 0; i < n; i++) {
    cin >> type[i] >> x[i] >> y[i] >> z[i];
    mx = max(mx, max(x[i], max(y[i], z[i])));
  }
  mx += 1;
  vector<vector<int>> gr(mx);
  vector<int> when(mx, -1);
  vector<int> deg(mx);
  for (int i = 0; i < n; i++) {
    if (type[i] == "S") {
      gr[x[i]].push_back(y[i]);
      gr[x[i]].push_back(z[i]);
      deg[y[i]] += 1;
      deg[z[i]] += 1;
      when[y[i]] = i;
      when[z[i]] = i;
    } else {
      gr[x[i]].push_back(z[i]);
      gr[y[i]].push_back(z[i]);
      deg[z[i]] += 2;
      when[z[i]] = i;
    }
  }
  vector<int> que;
  for (int i = 0; i < mx; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < int(que.size()); b++) {
    for (int u : gr[que[b]]) {
      if (--deg[u] == 0) {
        que.push_back(u);
      }
    }
  }
  vector<int> sz(mx);
  for (int i : que) {
    if (i == 1) {
      sz[i] = m;
    } else {
      int id = when[i];
      if (id != -1) {
        if (type[id] == "S") {
          if (i == y[id]) {
            sz[i] = (sz[x[id]] + 1) / 2;
          } else {
            sz[i] = sz[x[id]] / 2;
          }
        } else {
          sz[i] = sz[x[id]] + sz[y[id]];
        }
      }
    }
  }
  while (q--) {
    int i, k;
    cin >> i >> k;
    if (k > sz[i]) {
      cout << "none" << endl;
      continue;
    }
    while (i != 1) {
      int id = when[i];
      // int a= mp[x].first;
      if (type[id] != "S") {
        int a = x[id];
        int b = y[id];
        int sa = sz[a];
        int sb = sz[b];
        if (k <= min(sa, sb) * 2) {
          if (k % 2 == 1) {
            i = a;
            k = (k + 1) / 2;
          } else {
            i = b;
            k = k / 2;
          }
        } else {
          if (sa > sb) {
            i = a;
            k -= sb;
          } else {
            i = b;
            k -= sa;
          }
        }
      } else {
        if (i == y[id]) {
          k = 2 * k - 1;
        } else {
          k = 2 * k;
        }
        i = x[id];
      }
    }
    cout << k << endl;
  }
}
