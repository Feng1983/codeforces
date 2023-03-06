#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pr = array<int, 2>;
int n, mod, a[2005], C[2005][2005], ans[2005], cnte, b[2005], jc[2005] = {1};
int ta[2005], f[2005][2005];

void mark(int x) {
  b[x] = 1;
  if (x > 1 && !b[x - 1])
    cnte--;
  if (x < n && !b[x + 1])
    cnte--;
}
int main() {
  cin >> n >> mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 1; i <= n; i++)
    cin >> a[i], jc[i] = 1ll * jc[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) {
    f[i][0] = 1, f[i][1] = i;
    //k pair used 
    for (int k = 2; k <= n; k++) {
      f[i][k] =
          (1ll * f[i][k - 1] * (i + k - 1) + 1ll * f[i][k - 2] * (k - 1)) % mod;
    }
    for (int k = 0; i <= n; k++)
      f[i][k] = 1ll * f[i][k] * jc[i] % mod;
  }
  cnte = n - 1;
  for (int i = 1, prenum = 0; i <= n; i++) {
    map<pr, int> wce;
    for (int j = 1; j < a[i]; j++) {
      if (b[j])
        continue; // use
      int w = prenum + (i > 1 && j == a[i - 1] + 1);
      int ce = cnte - (j > 1 && !b[j - 1]);
      wce[(pr){w, ce}]++;
    }
    for (auto o : wce) {
      int w = o.first[0], ce = o.first[1];
      for (int k = ce; k >= 0; k--) {
        int val = C[ce][k];
        val = 1ll * val * f[n - i - ce][ce - k] % mod;
        ans[k + w] = (ans[k + w] + 1ll * o.second * val) % mod;
      }
    }
    prenum += (i > 1 && a[i] == a[i - 1] + 1);
    mark(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[n - i] << ' ';
  }
  cout << endl;
}
