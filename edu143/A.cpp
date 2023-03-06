#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){

  int n,m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  reverse(b.begin(),b.end());
  a+=b;
  int cnt;
  for(int i =0;i<a.size()-1;i++){
    if(a[i]==a[i+1]){
      cnt++;
    }
  }
  if(cnt<=1){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO\n";
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
