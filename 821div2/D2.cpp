#include<bits/stdc++.h>
//#include"headerlist.cpp"
//#include <numeric>

using namespace std;

using i64=long long;
constexpr i64 inf = 1e18;

void solve(){
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(int  i=0;i<n;i++){
    char ch;
    cin >> ch;
    a[i] ^= (ch-'0');
  }
  for(int i = 0;i<n;i++){
    char ch;
    cin >> ch;
    a[i]^=(ch-'0');
  }
  int cnt= accumulate(a.begin(),a.end(), 0);
  if(cnt%2){
    cout<<-1<<endl;
    return;
  }
  vector<int> pos;
  for(int i =0;i<n;i++){
    if(a[i]){
      pos.push_back(i);
    }
  }
  if(x>=y){
    if(cnt!=2 || pos[1] >pos[0] +1){
      cout<<1LL*(cnt/2)*y<<endl;
      return;
    }
    // cnt==2 ,pos[0] ==pos[1];
    int ans =x;
    if(pos[0] >1|| pos[1]<n-2){
      ans = min(ans, 2*y);
    }else if(n>=4){
      ans =min(1LL*ans, 3LL*y);
    }
    cout<<ans<<endl;
    return;
  }
  const int N=  pos.size();
  vector<i64>dp(N+1, inf);
  dp[0]  =0;
  for(int i =0;i<N;i++){
    i64 cur = 0;
    for(int j = i+2;j<=N;j+=2){
      if(j>= i+4){
        cur += 1LL*x*(pos[j-2]-pos[j-3]);
      }
      dp[j]  =min(dp[j], dp[i]+min(1LL*y, 1LL*x*(pos[j-1]-pos[i]))+cur);

    }
  }
  cout<<dp[N]<<endl;
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

