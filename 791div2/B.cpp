#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 500005;
int n, m, T, stp;
int a[maxn], vis[maxn];

long long ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  int lst = 0;
  while (m--) {
    int t, x, y;
    cin >> t >> x;
    if (t == 1) {
      cin >> y ;
      if(vis[x]!=stp){
        ans+= y-lst;
      }else ans+= y-a[x];
      vis[x] = stp,a[x]=y;
    }
    if(t==2)stp++, ans=1ll*x*n, lst=x;
  }
}
