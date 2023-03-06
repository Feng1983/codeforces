#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  vector<i64> a(n);
  for(int i = 0;i<n;i++){
    cin >>a[i];
  }
  sort(a.begin(),a.end());
  i64 ans =1e9;
  for(int i = 2;i<n;i++){

    ans= min(ans, a[i]-a[i-2]);
  }
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
