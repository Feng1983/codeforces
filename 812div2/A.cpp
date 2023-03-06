#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

using i64= long long;

void solve(){
  int n;
   cin >> n;
  int xl=0, xr=0, yl=0,yr=0;
  for(int i = 0;i<n;i++){
    int x, y;
    cin >> x >> y;
    if(x==0){
      yl = min(yl, y);
      yr= max(yr, y);
    }
    if(y==0){
      xl= min(xl, x);
      xr = max(xr, x);
    }
    cout<< 2*(xr-xl+yr-yl)<<"\n";
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
