#include<bits/stdc++.h>
//#include "headerlist.cpp"

using namespace std;

using i64 = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int>f(n, (1<<30)-1);
  vector<vector<array<int, 2>>>adj(n);
  for(int i=  0;i<q;i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--,b--;

    f[a]&=c;
    f[b]&=c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  for(int i = 0;i <n;i++){
    int t=0;
    for(auto [j,x]: adj[i]){
      t|= x&~f[j];
      if(j==i){
        t= x;
      }
    }
    f[i]  =t;
    cout<<f[i] <<" \n"[i==n-1];
  }
  return 0;
}
