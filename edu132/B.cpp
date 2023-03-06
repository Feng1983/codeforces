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

using ll  = long long;
const int N=100100;
int n; 
ll a[N];
ll pref[N], suf[N];


int main(){
  int q;
  cin >> n >>q;
  for(int i = 0;i<n;i++){
    scanf("lld",&a[i]);
  }
  pref[0] = 0;
  for(int i=1;i<n;i++)
  pref[i] = pref[i-1]+max(0LL, a[i-1]-a[i]);
  suf[n-1] =0;
  for(int i=n-2;i>=0;i--)
  suf[i] = suf[i+1]+max(0LL,a[i+1]-a[i]);

  while(q--){
    int v, u;
    scanf("%d%d", &v,&u);
    if(v<=u){
      printf("lld\n", pref[u]  -pref[v]);
    }else{
      printf("%lld", suf[u]-suf[v]);
    }
  }
  return 0;
  
}
