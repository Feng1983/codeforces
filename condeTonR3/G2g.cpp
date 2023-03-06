#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
using ll = long long;
int n, mod, a[N], vis[N], p[N];
ll fac[N], comb[N][N], ans1[N], ans2[N], tmp[N], dfac[N][N];

int main() {
  cin >> n >> mod;
  fac[0] = comb[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      if (i == 0)
        dfac[0][j] = fac[j]; // i paires  j!
      else {
        dfac[i][j] = (dfac[i - 1][j + 1] - dfac[i - 1][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int pe1 = 0, pe2 = 0;
    for (int c = 1; c < i - 1; c++)
      if (p[c] + 1 == p[c + 1])
        pe1++;
    for (int c = 1; c < n; c++)
      if (!vis[c] && !vis[c + 1])
        pe2++;
    map<pair<int, int>, int> cnt;
    for (int j = 1; j < a[i]; j++)
      if (!vis[j]) {
        vis[j] = 1;
        int e1 = pe1 + (i > 1 && p[i - 1] + 1 == j), e2 = pe1;
        if (j - 1 >= 1 && !vis[j - 1])
          e2--;
        vis[j] = 0;
        cnt[make_pair(e1, e2)]++;
      }
    for (auto [e, cc] : cnt) {
      auto [e1, e2] = e;
      auto gettmp = [&](int e2, int q) {
        vector<ll> a(e2 + 1, 0);
        for (int p2 = 0; p2 <= e2; p2++)
          a[p2] = (comb[e2][p2] * dfac[e2 - p2][q - e2]) % mod;
        return a;
      };
      auto v1 = gettmp(e2, n - i);
      for (int p2 = 0; p2 <= e2; p2++) {
        ans2[e1 + e2] += v1[p2] * cc % mod;
      }
    }
    p[i] = a[i];
    vis[a[i]] = 1;
  }
  for(int i=0;i<n;i++){
     ans2[i] %=mod;
     if(ans2[i]<0)ans2[i] +=mod;
  }
  for(int i=0;i<n;i++){
  cout<<ans2[n-i-1]<<" \n"[i==n-1];
  }
}
