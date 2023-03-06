#include <algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

using i64= long long;
int query(int a, int b){
  cout<<"? "<<a+1 <<" "<<b+1<<endl;
  int res;
  cin >> res;
  return res;
}

void solve(){
  int n;
  cin >> n;
  vector<int> a(1<<n);
  iota(a.begin(), a.end(),0);
  while(a.size()>=4){
    vector<int> b;
    for(int i = 0;i<int(a.size()); i+=4){
      int x = query(a[i], a[i+2]);
      if(x==0){
        if(query(a[i+1], a[i+3])==1){
          b.push_back(a[i+1]);
        }else{
          b.push_back(a[i+3]);
        }
      }else if(x==1){
        if(query(a[i],a[i+3])==1){
          b.push_back(a[i]);
        }else{
          b.push_back(a[i+3]);
        }
      }else {
        if(query(a[i+2],a[i+1])==1){
          b.push_back(a[i+2]);
        }else{
          b.push_back(a[i+1]);
        }
      }
    }
    a=b;
  }
  if(a.size()==2){
    if(query(a[0],a[1]==1)){
      a={a[0]};
    }else{
      a={a[1]};
    }
  }
  cout<<"! "<<a[0]+1<<endl;

}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
