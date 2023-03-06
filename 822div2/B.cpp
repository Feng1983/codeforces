#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  for(int i =0;i<n;i++){
    for(int j =0;j<=i;j++){
      if(j==i || j==0){
        cout<<"1 ";
      }else{
        cout<<"0 ";
      }
    }
    cout<<endl;
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
