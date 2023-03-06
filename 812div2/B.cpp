#include <algorithm>
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

using i64= long long;

void solve(){
  int n;
  i64 ans=0;
  vector<int> a(n);
  for(int i = 0;i<n;i++){
    cin >> a[i];
    ans+= max(0, a[i]-(i? a[i-1]:0));
  }
  if(ans== *max_element(a.begin(), a.end())){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
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
