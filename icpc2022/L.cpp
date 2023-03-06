#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<array<int, 2>> token;

  for (int j = m - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == 'X') {
        token.push_back({i, j});
      }
    }
  }
  vector<tuple<vector<int>, int, int>> pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<int> t;
      for (auto [x, y] : token) {
        int v = 0;
        if (x == i && y == j) {
          v = 0;
        } else {
          int r = max(abs(x - i), abs(y - j));
          v = (2 * r - 1) * (2 * r - 1);
          if (y == j + r && x != i - r) {
            v += x - (i - r + 1);
          } else if (x == i + r) {
            v += (2 * r - 1) + (j + r) - y;
          } else if (y == j - r) {
            v += (4 * r - 1) + (i + r) - x;
          } else {
            v += (6 * r - 1) + y - (j - r);
          }
        }
        t.push_back(v);
      }
      sort(t.begin(), t.end());
      pos.push_back({t, i, j});
    }
  }
  sort(pos.begin(), pos.end());
  vector<int> ans(n * m);
  for (int i = 0; i < n * m - 1; i++) {
    auto [a, x1, y1] = pos[i];
    auto [b, x2, y2] = pos[i + 1];
    int k = 0;
    while (k < int(a.size()) && a[k] == b[k]) {
      k++;
    }
    int lcp = min(a[k], b[k]);
    int p1 = x1 * m + y1;
    int p2 = x2 * m + y2;
    ans[p1] = max(ans[p1], lcp);
    ans[p2] = max(ans[p2], lcp);
    int sum = accumulate(ans.begin(), ans.end(), 0);
    int max = *max_element(ans.begin(), ans.end());
    cout << fixed << setprecision(10);
    cout << 1. * sum / n / m << endl;
    cout << max << endl;
    for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
        if(ans[i*m+j]==max){
          cout<< "("<<i+1<<","<<j+1<<") ";
        }
      }
    }
    cout<<endl;
  }
}
