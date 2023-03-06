#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using i64 = long long;
const double Pi = acos(-1.);

struct Point {
  double x;
  double y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<Point>> p(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    p[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> p[i][j].x >> p[i][j].y;
    }
  }
  vector<Point> a(m), b(m);
  vector<double> az(m), bz(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].x >> a[i].y >> az[i] >> b[i].x >> b[i].y >> bz[i];
  }
  double mx = 0;
  for (int i = 0; i < n; i++) {
    double ans = 1e9;
    for (int j = 0; j < m; j++) {
      double res = 0;
      double len = sqrt(dot(a[j] - b[j], a[j] - b[j]));
      for (auto u : p[i]) {
        if (dot(b[j] - a[j], u - a[j]) < 0 || dot(a[j] - b[j], u - b[j]) < 0) {
          res = 1e9;
          break;
        }
        double area = abs(cross(u - a[j], b[j] - a[j]));
        double dis = area / len;
        double d1 = dot(u - a[j], b[j] - a[j]);
        double r = d1 / dot(b[j] - a[j], b[j] - a[j]);
        double z = (az[j] * (1 - r) + bz[j] * r);
        res = max(res, dis / z);
      }
      ans = min(ans, res);
    }
    if (ans == 1e9) {
      cout << "impossible" << endl;
      return 0;
    }
    mx = max(mx, ans);
  }
  cout << fixed << setprecision(10);
  cout << atan(mx) * 180 / Pi << endl;
}
