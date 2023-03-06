#include <algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

using i64= long long;

void solve(){
  int n;
  cin >> n;
  vector<int> p(n);
  int r= n, x= 2*sqrt(n);
  while(r>0){
    while(x*x > 2*r -2){
      x--;
    }
    int v= x*x;
    for(int i=v-r+1;i<r; i++){
      p[i] = v-i;
    }
    r= v-r+1;
  }
  for(int i=0;i<n;i++)
    cout<<p[i] <<" \n"[i==n-1];

}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
