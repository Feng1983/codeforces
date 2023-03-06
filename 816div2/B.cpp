#include<bits/stdc++.h>
//#include "headerlist.cpp"

using namespace std;

void solve(){
  int n,k,b;
  long long s;
  cin >> n >> k >> b >> s;
  long long cur =s/k;
  if(b>cur){
    cout<<"-1"<<endl;
    return;
  }
  vector<long long> a(n);
  a[0] = s;
  for(int i =1;i<n;i++){
    if(cur >b &&a[0 ]>=k){
      cur-= (a[0]%k!=k-1);
      a[0]-= (k-1);
      a[i]=k-1;
    }
  }
  if(cur!=b){
    cout<<"-1"<<endl;
    return;
  }
  for(int i =0;i<n;i++){
    cout<<a[i] <<" \n"[i==n-1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}

