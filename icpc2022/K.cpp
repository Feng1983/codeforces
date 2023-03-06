#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Point {
  i64 x, y;
  Point(i64 x = 0, i64 y = 0) : x(x), y(y) {}
};
const double Pi = std::acos(-1.);

bool operator==(const Point &a, const Point &b) {
  return a.x == b.x && a.y == b.y;
}

Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
i64 dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
i64 cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

void norm(vector<Point> &h) {
  int i = 0;
  for (int j = 0; j < int(h.size()); j++) {
    if (h[j].y < h[i].y || (h[j].y == h[i].y && h[j].x < h[i].x)) {
      i = j;
    }
  }
  rotate(h.begin(), h.begin() + i, h.end());
}
int sgn(const Point &a) { return a.y > 0 || (a.y == 0 && a.x > 0) ? 0 : 1; }

vector<Point> getHull(vector<Point> p) {
  vector<Point> h, l;
  sort(p.begin(), p.end(), [&](auto a, auto b) {
    if (a.x != b.x) {
      return a.x < b.x;
    } else {
      return a.y < b.y;
    }
  });

  p.erase(std::unique(p.begin(), p.end()), p.end());

  if (p.size() <= 1) {
    return p;
  }

  for (auto a : p) {
    while (h.size() > 1 && cross(a - h.back(), a - h[h.size() - 2]) <= 0) {
      h.pop_back();
    }
    while (l.size() > 1 && cross(a - l.back(), a - l[l.size() - 2]) >= 0) {
      l.pop_back();
    }
    l.push_back(a);
    h.push_back(a);
  }
  l.pop_back();
  reverse(h.begin(), h.end());
  h.pop_back();
  l.insert(l.end(), h.begin(), h.end());
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  vector<Point> p(n);
  vector<vector<Point>> h(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k) {
      while (k--) {
        int x;
        cin >> x;
        x--;
        adj[i].push_back(x);
      }
    } else {
      int x, y;
      cin >> x >> y;
      p[i] = Point(x, y);
    }
  }
  function<void(int)> dfs = [&](int x) {
    if (adj[x].empty()) {
      h[x] = {p[x]};
    } else {
      vector<Point> p;
      for (auto y : adj[x]) {
        dfs(y);
      }
      for (auto z : adj[x]) {
        Point a = 0;
        vector<Point> d;
        for (auto y : adj[x]) {
          if (y != z) {
            for (auto &q : h[y]) {
              q = 0 - q;
            }
          }
          norm(h[y]);
          if (h[y].size() > 1) {
            for (int j = 0; j < int(h[y].size()); j++) {
              d.push_back(h[y][(j + 1) % h[y].size()] - h[y][j]);
            }
          }
          a = a + h[y][0];
          if (y != z) {
            for (auto &q : h[y]) {
              q = 0 - q;
            }
          }
        }
        sort(d.begin(), d.end(), [&](auto a, auto b) {
          if (sgn(a) != sgn(b)) {
            return sgn(a) < sgn(b);
          }
          return cross(a, b) > 0;
        });
        if (d.empty()) {
          p.push_back(a);
        }
        for (auto q : d) {
          p.push_back(a);
          a = a + q;
        }
      }
      h[x] = getHull(p);
    }

  };

  dfs(0);
  i64 ans = 0;
  for (auto p : h[0]) {
    ans = max(ans, dot(p, p));
  }
  cout<<ans<<endl;
  return 0;
}
