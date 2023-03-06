#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  i64 ans=0;
  vector<bool>vis(n);
  for(int i =1;i<=n;i++){
    for(int j=i;j<=n&&t[j-1]=='0';j+=i){
      if(!vis[j-1]){
        vis[j-1]=true;
        ans+=i;
      }
    }
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
