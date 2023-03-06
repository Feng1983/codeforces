#include<bits/stdc++.h>
//#include "headerlist.cpp"
//#include <numeric>
using namespace std;
void solve(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i= k;i<n;i++){
    a[i%k] =max(a[i], a[i%k]);
  }
  
  long long ans =accumulate(a.begin(),a.begin()+k, 0LL);
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
