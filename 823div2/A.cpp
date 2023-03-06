#include<bits/stdc++.h>
//#include "headerlist.cpp"
using namespace std;

void solve(){
  int n,c;
  cin >> n >> c;

  vector<int>A(102);
  for(int i =0;i<n;i++){
    int x;
    cin >> x;
    A[x]++;
  }
  int ans =0;
  for(int i=0;i<101;i++){
    ans+=min(A[i], c);
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
