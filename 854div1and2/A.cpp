#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){
  int n,m;
  cin >> n >> m;
  vector<int>p(n);
  vector<int>cnt(m);
  vector<int> ans(n,-1);
  int x =n-1;
  for(int i=0;i<m;i++){
    cin >> p[i];
    p[i]--;
    if(cnt[p[i]-n]++==0){
      if(x>=0){
        ans[x] =i+1;
      }
      x--;
    }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" \n"[i==n-1];
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
