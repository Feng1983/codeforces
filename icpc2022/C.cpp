#include <bits/stdc++.h>
#include <utility>
using namespace std;
using i64 =long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m; i64 n;
  cin >> n >> m;
  if(n>100){
    cout<<"impossile"<<endl;
    return 0;
  }
  for(i64 q=2;q<=4000; q++){
    for(i64 p=1;p<q;p++){
      if(gcd(p,q)!=1){
        continue;
      }
      double x = (pow(q,n)-pow(q-p,n))/p;
      if(!(x<2*m)){
        continue;
      }
      __int128 p1=1,p2=1;
      for(int i=0;i<n;i++){
        p1*=q;
        p2*=q-p;
      }
      i64 y = (p1-p2)/p;
      if(m%y==0){
        cout<<p<<" "<<q<<endl;
        return 0;
      }
    }
  }
  return 0;
}
