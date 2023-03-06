#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i =0;i<n;i++){
    cin >> a[i];
  }
  string s;
  cin >> s;
  bool ok=true;
  for(int j =0;j<n;j++){
    for(int k =j+1;k<n;k++){
      if(a[j]==a[k] && s[j]!=s[k]){
        ok=false;
      }
    }
  }
  if(ok){
    cout<<"YES"<<endl;

  }else{
    cout<<"NO"<<endl;
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
