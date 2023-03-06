#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i  =0;i<n;i++){
    cin >>a[i];
  }
  vector<int>b(n),c(n);
  for(int j =0;j<n;j++){
    b[j] =__builtin_ctz(a[j]);
    c[j] =__builtin_ctz(j+1);
  }
  sort(c.begin(),c.end(),greater<int>());
  int cnt=0;
  for(int i = 0;i<n;i++){
    cnt+=b[i];
  }
  int ans=0;
  for(int j=0;j<n;j++){
    if(cnt<n){
      cnt+=c[j];
      ans++;
    }
  }
  if(cnt<n){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
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
