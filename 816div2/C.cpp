#include<bits/stdc++.h>
//#include "headerlist.cpp"
using namespace std;

using i64=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n , m;
  cin >> n >> m;

  vector<int> a(n);
  for(int i = 0 ;i<n;i++){
    cin >> a[i];
  }
  i64  ans= 1LL* n*(n+1)/2;
  for(int i  =1;i<n;i++){
    ans += 1LL * (a[i-1]!=a[i])*i*(n-i);
  }
  for(int i =0;i<m;i++)
    {

      int p, x;
      cin >> p>> x;
      p--;

      if(p)
      {
        ans+=1LL * ((a[p-1]!=x)-(a[p-1]!=a[p]))*p*(n-p);
      }
      if(p<n-1){
        ans+= 1LL *((a[p+1]!=x)-(a[p+1]!=a[p]))*(p+1)*(n-p-1);
      }
      a[p] =x;
      cout<<ans <<endl;
    }
  return 0;
}

