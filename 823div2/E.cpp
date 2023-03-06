#include<bits/stdc++.h>
//#include "headerlist.cpp"
#include <algorithm>
using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }
  int m = *max_element(a.begin(),a.end());
  vector<vector<int>>p(m+1);
  for(int i =0;i<n;i++){
    p[a[i]].push_back(i);
  }
  vector<int>s;
  vector<int>la(n),lb(n), ra(n),rb(n);
  for(int i = 0 ;i<n;i++){
    while(!s.empty()&& a[i] >=a[s.back()])
      {
        s.pop_back();
      }
    la[i] =s.empty()?-1:s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i = 0;i<n;i++){
    while(!s.empty()&& a[i]<=a[s.back()])
      {
        s.pop_back();
      }
    lb[i] =s.empty()?-1: s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i= n-1;i>=0;i--){
    while(!s.empty()&& a[i] >=a[s.back()]){
      s.pop_back();
    }
    ra[i] =s.empty()?n: s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i = n-1;i>=0;i--){
    while(!s.empty()&& a[i] <=a[s.back()]){
      s.pop_back();
    }
    rb[i] = s.empty()?n:s.back();
    s.push_back(i);
  }
  i64 ans= 0;
  for(int i=1;i<=m;i++){
    if(p[i].empty()){
      continue;
    }
    for(int j = 2*i;j<=m;j+=i){
      if(p[j].empty()){
        continue;
      }
      const int ni=p[i].size(),nj= p[j].size();
      int x=0, y=0;
      int last=-1;
      while(x<ni&&y<nj){
        if(p[i][x] <p[j][y]){
          int nx  =lower_bound(p[i].begin(),p[i].end(),p[j][y])-p[i].begin();
          int a=p[i][nx-1];
          int b =p[j][y];
          int L = max({lb[a],la[b],last});
          int R =min(rb[a],ra[b]);
          if(L< a && R>b){
            ans+=1LL*(a-L)*(R-b);
          }
          x= nx;
          last=a;
        }else{
          int ny=lower_bound(p[j].begin(),p[j].end(),p[i][x])-p[j].begin();
          int a= p[i][x];
          int b =p[j][ny-1];
          int L=max({lb[a],la[b],last});
          int R= min(rb[a],ra[b]);
          if(L<b&& R>a){
            ans+=1LL*(b-L)*(R-a);
          }
          y=ny;
          last=b;
        }
      }
    }
  }

  for(int i=0,j=0;i<n;i=j){
    j=i;
    while(j<n&& a[i]==a[j]){
      j++;
    }
    ans+=1LL*(j-i)*(j-i+1)/2;
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
