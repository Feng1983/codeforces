#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;


using i64= long long;

struct DSU{
  vector<int> f, g;
  DSU(int n ): f(n), g(n){std::iota(f.begin(), f.end(),0);}

  array<int ,2> leader(int x){

    if(f[x]==x){
      return {x,0};
    }
    auto [y,z] = leader(f[x]);
    f[x] = y;
    g[x] ^=z;
    return {f[x], g[x]};
  }
  bool merge(int a, int b, int  z){
    auto [x,u] =leader(a);
    auto [y,v] =leader(b);
    if(x==y){
      return (u^v^z)==0;
    }
    f[y] = x;
    g[y] =u^v^z;
    return true;
  }

};
void solve(){
  int n;
  vector<vector<int>> a(n, vector<int>(n));
  DSU dsu(n);
  for(int i =0 ;i<n;i++){
    for(int j = 0; j<n;j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      if(a[i][j] == a[j][i]){
        continue;
      }
      if(dsu.merge(i,j,a[i][j] >a[j][i]) ^ (a[i][j] <a[j][i])){
        swap(a[i][j], a[j][i]);
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout<<a[i][j] <<" \n"[j=n-1];
    }
  }
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
