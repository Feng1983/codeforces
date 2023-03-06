#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){

  int n,b,k1,k2;
  cin >> n >> b >> k1 >> k2;
  i64 sum = 0;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  i64 ans=0;
  sort(a.begin(),a.end(),greater());
  vector f(k1+1, vector<i64> (k2+1));
  int mid =0;
  while(mid< n && a[mid]>=b){
    mid++;
  }
  i64 res= 0;
  for(int i=0;i<=k1;i++){
    if(i>0 && i<=mid){
      res+= a[i-1]/2;
    }
    int t=min(i,mid);
    i64 v= res;
    for(int j=0;j<=k2;j++){
      if(j>0){
        if(t+j<=mid){
          v+=b;
        }else if(j<=mid){
          v+=min(b, (a[t+j-mid-1]+1)/2);
        }
      }
      f[i][j]=v;
    }
  }
  res=0;
  for(int i= 0;i<=min(k2, n-mid);i++){
    if(i>0){
      res+= a[mid+i-1];
    }
    i64 v=res;
    for(int j=0;j<=min(k1,n-i-mid);j++){
      if(j>0){
        v+=a[mid+i+j-1]/2;
      }
      ans =max(ans, v+f[k1-j][k2-i]);
    }
  }
  ans = sum-ans;
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
