#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2010;
int n, mod, a[N], C[N][N], fac[N], ban[N], f[N], g[N];
int p[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> mod;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  fac[0] = 1;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ban[0] = 1, ban[n + 1] = 1;
  a[0] = -1;
  for (int i = 1, cur = 0; i <= n; i++) {
    int x = 0, y = i;
    for (int j = 1; j <= n; j++)
      x += ban[j - 1] && !ban[j];
    auto solve = [&](vector<vector<int>> cnt) {
      for (int j = 0; j < n - y; j++) {
        p[cur][j] = (p[cur][j] +
                     1ll * C[n - x - y][j] * fac[n - y - j] % mod * cnt[0][1]) %
                    mod;
      }
      //[]1
      for (int j = 0; j < n - y; j++) {
        p[cur][j] = (p[cur][j] +
                     1ll * C[n - x - y][j] * fac[n - y - j] % mod * cnt[1][0]) %
                    mod;
        p[cur][j + 1] =
            (p[cur][j + 1] +
             1ll * C[n - x - y][j] * fac[n - y - j - 1] % mod * cnt[1][0]) %
            mod;
      }
      for (int j = 0; j < n - y; j++) {
        p[cur][j] = (p[cur][j] + 1ll * C[n - x - y - 1][j] * fac[n - y - j] %
                                     mod * cnt[0][0]) %
                    mod;

        p[cur][j + 1] =
            (p[cur][j + 1] +
             1ll * C[n - x - y - 1][j] * fac[n - y - j - 1] % mod * cnt[0][0]) %
            mod;
      }
      for (int j = 0; j < n - y; j++) {
        p[cur][j] = (p[cur][j] + 1ll * C[n - x - y + 1][j] * fac[n - y - j] %
                                     mod * cnt[1][1]) %
                    mod;
      }
    };
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int j = 1; j < a[i]; j++)
      if (j != a[i - 1] + 1 && !ban[j])
        cnt[ban[j - 1]][ban[j + 1]]++;
    solve(cnt);
    if (!ban[a[i - 1] + 1] && a[i - 1] + 1 < a[i]) {
      vector<vector<int>> cnt(2, vector<int>(2));
      cnt[1][ban[a[i - 1] + 2]] = 1, cur++;
      solve(cnt);
      cnt[1][ban[a[i - 1] + 2]] = 0, cur--;
    }
    ban[a[i]] = 1;
    if (i > 1)
      cur += a[i] == a[i - 1] + 1;
  }
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= 1; j--)
      f[j] = (f[j] + f[j - 1]) % mod;
    for (int j = 0; j <= n; j++)
      f[j] = (f[j] + p[i][j]) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (j - i & 1)
        g[i] = (g[i] - 1ll * C[j][i] * f[j] % mod + mod) % mod;
      else
        g[i] = (g[i] + 1ll * C[j][i] * f[j]) % mod;
    }
  }
  for (int i = n - 1; i >= 0; i--)
    cout << g[i] << " \n"[!i];
  return 0;
}
