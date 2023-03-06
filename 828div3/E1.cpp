#include<bits/stdc++.h>
#include<numeric>
using namespace std;

using i64=long long;
void solve(){
  i64 a,b,c,d;
  cin >>a >>b >>c >>d;
  
  i64 val = a*b;
  for(int i=a+1;i<c+1;i++){
    i64 cur = val/gcd(val,(i64)i);
    i64 nxt=  b+1;
    if(nxt %cur!=0){
      nxt+=cur-(nxt%cur);
    }
    if(nxt<=d){
      cout<<i<<" "<<nxt<<endl;
      return;
    }
  }
  cout<<"-1 -1"<<endl;
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
