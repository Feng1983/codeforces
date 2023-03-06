#include <iostream>
#include <vector>
using namespace std;
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

using ll = long long;
// all methods 0-indexed , intervals are [l,r]
struct Tree {
  using T = long long;
  const T NONE = 0; // default
  vector<T> tree;
  int B = 0;
  T comb(T a, T b) { return min(a, b); }
  void init(int n) {
    B = 1;
    while (B < n)
      B *= 2;
    tree.assign(2 * B, NONE);
  }
  void init(vector<T> a) {
    int n = a.size();
    init(n);
    for (int i = 0; i < n; i++)
      tree[i + B] = a[i];
    for (int i = B - 1; i > 0; i--)
      tree[i] = comb(tree[2 * i], tree[2 * i + 1]);
  }
  void upd(int i, T x) {
    assert(B);
    tree[i += B] += x;
    for (i /= 2; i > 0; i /= 2)
      tree[i] = comb(tree[2 * i], tree[2 * i + 1]);
  }
  T qry(int l, int r) {
    assert(B);
    T resl = 100000, resr = 10000;
    for (l += B, r += B; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1)
        resl = comb(resl, tree[l++]);
      if (r % 2 == 0)
        resr = comb(tree[r--], resr);
    }
    return comb(resl, resr);
  }
};
const int MX = 2e5 + 10;
int n, q;
Tree row, col;
void qry() {
  int t;
  cin >> t;
  if (t == 1) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    row.upd(x, 1);
    col.upd(y, 1);
    return;
  }
  if (t == 2) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    row.upd(x, -1);
    col.upd(y, -1);
    return;
  }
  int x[2], y[2];
  for (int i = 0; i < 2; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < 2; i++) {
    --x[i], --y[i];
  }
  if (row.qry(x[0], x[1]) == 0 && col.qry(y[0], y[1]) == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
void solve() {
  cin >> n >> q;
  row.init(n);
  col.init(n);
  while (q--) {
    qry();
  }
}
