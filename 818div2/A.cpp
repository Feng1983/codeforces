#include<bits/stdc++.h>


using namespace std;


void solve(){
  int n;
  cin >> n;

  int ans=0;
  ans=n+(n/2)*2+(n/3)*2;
  cout<<ans<<endl;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
  
}
