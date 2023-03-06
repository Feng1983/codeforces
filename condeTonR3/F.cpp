#include<bits/stdc++.h>

using namespace std;

using i64=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  vector f(n+1, vector<int>(n+1));
  f[1][1]=1;
  vector<int>s(2*n+1);
  s[2]=1;
  int p =1;
  for(int i=2;i<=n;i++){
    if(i>2){
      p= 2*p%m;
    }
    int v= p;
    auto sum =s;
    for(int j =1;j<=2*n;j++){
      sum[j] = (sum[j]+sum[j-1])%m;
    }
    for(int j=1;j<i;j++){
      f[i][j] = 1LL *sum[max(0,i-2*j-1)]*f[j][j]%m;
      v=(v-f[i][j]+m)%m;
      s[i+j] = (s[i+j]+f[i][j])%m;
    }
    f[i][i] =v;
    s[i+i]=(s[i+i]+f[i][i])%m;
  }
  cout<<f[n][n]<<endl;
  return 0;
}
