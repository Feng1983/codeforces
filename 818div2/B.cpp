#include<bits/stdc++.h>
using namespace std;


void solve(){
  int n,k, r,c;
  cin >> n >> k >> r>>c;
  for(int i=0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout<<".X"[((i-j)%k+k)%k==((r-c)%k+k)%k];

    }
    cout<<endl;
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
