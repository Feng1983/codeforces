#include<bits/stdc++.h>

using namespace std;
using i64=long long;

void solve(){
  int n ;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  i64 ans=0;
  for(int i = 0,j=0;i<n;i++){
    while(j<n && a[j]-(j-i)-1>=0)j++;
    ans+=(j-i);
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
