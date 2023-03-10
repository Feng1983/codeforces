#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){
  int n,m;
  cin >> n >> m;
  vector<string>s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  vector<int> minr(n,m), maxr(n,-1),minc(m,n),maxc(m,-1);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='#'){
        minr[i] = std::min(minr[i],j);
        maxr[i] = std::max(maxr[i],j);
        minc[j] = std::min(minc[j], i);
        maxc[j] = std::max(maxc[j],i);
      }
    }
  }

  function<void(int,int)> work=[&](int x, int y)->void{
    s[x][y] ='#';
    minr[x] = min(minr[x], y);
    maxr[x] = max(maxr[x],y);
    minc[y] = min(minc[y],x);
    maxc[y] = max(maxc[y],x);

    for(int j=minr[x];j<=maxr[x];j++){
      if(s[x][j] =='.'){
        work(x,j);
      }
    }
    for(int i=minc[y];i<=maxc[y];i++){
      if(s[i][y]=='.'){
        work(i,y);
      }
    }

  };
  for(int i=0;i<n;i++){
    for(int j=minr[i];j<=maxr[i];j++){
      if(s[i][j]=='.'){
        work(i,j);
      }
    }
  }
  for(int j=0;j<m;j++){
    for(int i=minc[j];i<=maxc[j];i++){
      if(s[i][j]=='.'){
        work(i,j);
      }
    }
  }
  int u1=0;
  while(minr[u1]>maxr[u1]){
    u1++;
  }
  int d1=u1;
  while(d1+1<n&& minr[d1+1]<=maxr[d1]&& maxr[d1+1]>=minr[d1]){
    d1++;
  }
  int u2=d1+1;
  while(u2<n && minr[u2]>maxr[u2]){
    u2++;
  }
  if(u2<n){
    int d2=u2;
    while(d2+1<n && minr[d2+1] <=maxr[d2] && maxr[d2+1] >=minr[d2]){
      d2++;
    }
    int r1=-1, l2=m;
    int r2=-1, l1=m;
    for(int i=u1;i<=d1;i++){
      r1=std::max(r1, maxr[i]);
      l1=std::min(l1, minr[i]);
    }
    for(int i =u2;i<=d2;i++)
      {
        r2= max(r2,maxr[i]);
        l2= min(l2, minr[i]);
      }
    if(r1<l2){
      work(d1,r1);
      work(u2, l2);
      for(int i=d1+1;i<=u2;i++){
        work(i, r1);
      }
    }else{
      work(d1, l1);
      work(u2, r2);
      for(int i=d1+1; i<=u2;i++){
        work(i,l1);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<s[i]<<endl;
  }
  cout<<endl;

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
