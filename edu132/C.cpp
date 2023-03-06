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

  string S; cin >>S;
  int N = S.size();
  int remL = N/2,remR=N/2;
  for(auto a: S){
    if(a=='(')remL--;
    if(a==')')remR--;
  }
  vector<char> rem;
  if(remL <=0 || remR<=0){
    cout<<"YES"<<endl;
  }
  for(int i=0;i<remL;i++){
    rem.push_back('(');
  }
  for(int i = 0;i<remR;i++){
    rem.push_back(')');
  }
  swap(rem[remL],rem[remL-1]);
  int  p= 0;
  for(int i =0;i<N;i++){
    if(S[i] == '?'){
      S[i] = rem[p];p++;
    }
  }
  int cnt=0;
  for(int i = 0;i<N;i++){
        if(S[i] == '('){
          cnt++;
        }else{
      cnt--;
      if(cnt<0){
        cout<<"YES"<<endl;return;
      }
    }
      }

  cout<<"NO"<<endl;

}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
