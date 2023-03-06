#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  for(int i=0;i<n;i++){
    if(a[i]^b[i]^a[0]^b[0]){
      cout<<"NO"<<endl;
      return ;
    }
  }
  cout<<"YES"<<endl;
  vector<array<int ,2>>ans;
  for(int i=0;i<n;i++){
    if(a[i]=='1'){
      ans.push_back({i,i+1});
    }
  }
  if(a[0]^b[0]^(ans.size()&1)){
    ans.push_back({0,1});
    ans.push_back({1,n});
    ans.push_back({0,n});
  }
  cout<<ans.size()<<endl;
  for(auto[l,r]: ans){
    cout<<l+1<<" "<<r<<endl;
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
