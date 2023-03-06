//#include<bits/stdc++.h>
#include "headerlist.cpp"

using namespace std;

void solve(){
  int n;
  cin >>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  vector<array<int,2>> ans;
  if(n>1 && a[n-1] %2==a[0]%2){
    ans.push_back({0,n-1});
    a[0] =a[n-1];
  }
  for(int i=1;i<n;i++){
    if(a[i] %2!=a[0]%2){
      ans.push_back({0,i});
      a[i] = a[0];
    }
  }
  for(int i = n-2;i>=0;i--){
    if(a[i]!=a[n-1]){
      ans.push_back({i,n-1});
      a[i] =a[n-1];
    }
  }
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
