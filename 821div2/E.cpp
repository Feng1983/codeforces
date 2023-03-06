#include<bits/stdc++.h>
//#include"headerlist.cpp"

using namespace std;

using i64=long long;
i64 a[122][122];
i64 get(i64 t, int x, int y){
  memset(a, 0,sizeof(a));

  a[0][0] = max(t-(x+y)+1LL,0LL);
  for(int i  =0;i<=x;i++){
    for(int j  =0;j<=y;j++){
      a[i+1][j] += a[i][j]/2;
      a[i][j+1] += a[i][j]- a[i][j]/2;
    }
  }
  return  a[x][y];
}
void solve(){
  int  x, y;
  i64 t;

  cin >> t >> x >> y;
  if(get(t,x,y)-get(t-1,x,y)>0)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
