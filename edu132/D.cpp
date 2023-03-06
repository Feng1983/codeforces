#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;
using ll = long long;

ll SZ= 262144;
ll* seg = new ll[2*SZ];
ll combine(ll a, ll b){
  return max(a,b);
}

void build(){
  for(int i=SZ-1;i>=0;i--){
    seg[i] = combine(seg[2*i],seg[2*i+1]);
  }
}
void update(int p, ll value){
  for(seg[p+=SZ]=vale; p>1;p>>=1){
    seg[p>>1]=combine(seg[(p|1)^1],seg[p|1]);
  }
}
ll query(int l, int r){
  ll resL = 0, resR =0; r++;
  for(l+=SZ, r+=SZ; l<r; l>>=1,r>>=1){
    if(l&1){
       resL =combine(resL, seg[l++]);
       }
      if(r&1){
      resR = combine(seg[--r], resR);
    }
      }
}


void solve(){

  for(int i = 0;i<4;i++)cin >> a[i];
  int p  =0;
  for(int i = 0;i<3;i++){
    p= a[p];
    if(p==0){
      cout<<"NO"<<endl;
      return ;
    }
  }
  cout<<"YES"<<endl;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
