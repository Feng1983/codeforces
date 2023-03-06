#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){
  int n,k;
  cin >> n >>k;
  bool fl=false, fr=false;
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    if(l==k){
      fl=true;
    }
    if(r==k){
      fr =true;
    }
  }
  if(fl&& fr){
    cout<<"YES\n";
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
