#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
  int n,k;
  cin >> n >> k;
  k--;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  vector<array<i64,2>> l,r;
  for(int i=0;i<k;i++){
    l.push_back({min(a[i],0),a[i]});
    while(l.size() >1 && l.back()[1]<=0){
      auto [x,y] = l.back();
      l.pop_back();
      l.back()={min(x,y+l.back()[0]),y+l.back()[1]};
    }
  }
  for(int i=n-1;i>k;i--){
    r.push_back({min(a[i],0),a[i]});
    while(r.size()>1 && r.back()[1]<=0){
      auto [x,y]= r.back();
      r.pop_back();
      r.back()={min(x, y+r.back()[0]), y+r.back()[1]};
    }
  }
  i64 cur=a[k];
  while(!l.empty()&& !r.empty()){
    if(cur+l.back()[0] >=0){
      cur+=l.back()[1];
      l.pop_back();
    }else if(cur+r.back()[0] >=0){
      cur+=r.back()[1];
      r.pop_back();
    }else{
      cout<<"NO"<<endl;
      return ;
    }
  }
  cout<<"YES"<<endl;
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
