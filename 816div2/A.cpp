//#include "headerlist.cpp"
#include<bits/stdc++.h>


using namespace std;

void solve(){
  int n,m;
  cin >> n >> m;
  cout<<n-1+m-1+ min(min(1,n-1)+m-1, min(1,m-1)+n-1)<<endl;
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
