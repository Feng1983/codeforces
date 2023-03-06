#include<bits/stdc++.h>
//#include "headerlist.cpp"
using namespace std;
constexpr int inf =1e9;
void solve(){
  int n;
  cin >> n;
  vector<int>X(n), T(n);
  int mi =inf, mx=-inf;
  for(int i = 0;i<n;i++){
    cin >>X[i];
  }
  for(int i=0;i<n;i++){
    cin >>T[i];
    mi  =min(mi, X[i]-T[i]);
    mx = max(mx, X[i]+T[i]);
  }
  cout<<0.5*(mi+mx)<<endl;

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<std::fixed;
  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
