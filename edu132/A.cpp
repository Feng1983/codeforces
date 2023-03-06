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

int a[5];

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
