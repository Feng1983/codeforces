#include<bits/stdc++.h>
using namespace std;

using i64=long long;
constexpr i64 inf= 1e18;
void solve(){
  int n,k;
  cin >> n >>k;
  vector<int>a(n);

  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  vector<int>cold(k+1),hot(k+1), profit(k+1);
  i64 sum = 0;
  for(int i=1;i<=k;i++){
    cin >> cold[i];
  }
  for(int i=1;i<=k;i++){
    cin >>hot[i];
    profit[i] = cold[i]-hot[i];
  }
  for(int i=0;i<n;i++){
    sum+=cold[a[i]];
  }
  vector<i64> dp(k+1, -inf);
  dp[0] =0;
  i64 max= 0;
  i64 add=0;
  for(int i=1;i<n;i++){
    i64 val  =std::max(max, dp[a[i]]+add+profit[a[i]]);
    if(a[i]==a[i-1]){
      max+=profit[a[i]];
      add+=profit[a[i]];
    }
    dp[a[i-1]] =std::max(dp[a[i-1]],val-add);
    max=std::max(max, val);
  }
  i64 ans =sum-max;
  cout<<ans<<endl;

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
