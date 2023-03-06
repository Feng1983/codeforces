#include<bits/stdc++.h>

using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(auto &x: a){
    cin >>x;
  }
  vector<int> idx(n);
  for(int i=0;i<n;i++){
      idx[a[i]]=i;
  }
  i64 ans= 0;
  int l  =idx[0],r= idx[0];
  for(int i = 0;i+1<n;i++){
    l= min(l, idx[i]);
    r =max(r, idx[i]);
    int nxt= idx[i+1];
    if(l<=nxt && nxt<=r){
      continue;
    }
    int clen  =2*(i+1);
    if(nxt<l){
      for(int j =nxt+1;j<=l;j++){
        ans+=max(0,min(n,j+clen)-r);
      }
    }else if(nxt>r){
      for(int j =r;j<nxt;j++){
        ans+=max(0,l-max(-1,j-clen));
      }
    }
  }
  ans++;
  cout<<ans<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >>t;
  while(t--){
    solve();
  }
  return 0;
}
