#include<bits/stdc++.h>
//#include "headerlist.cpp"
using namespace std;

using i64 = long long;
constexpr i64 inf =1e18;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m,k;
  cin >> n >> m >> k;
  vector<vector<array<int,2>>>adj(n);

  for(int i = 0;i<m;i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  vector<i64>dis(n,inf);
  dis[0] = 0;
  auto dijisktra=[&](){
    priority_queue<pair<i64, int>, vector<pair<i64,int>>, greater<>> h;
    for(int i = 0;i<n;i++){
      h.emplace(dis[i], i);
    }
    while(!h.empty()){
      auto [d, x] = h.top();
      h.pop();
      if(d> dis[x]){
        continue;
      }
      for(auto[y,w]: adj[x]){
        if(d+w <dis[y]){
          dis[y]  =d+w;
          h.emplace(dis[y], y);
        }
      }
    }
  };
  dijisktra();

  for(int i =0;i<k;i++){
    vector<i64> f(n,inf);
    function<void(int ,int ,int, int)>solve= [&](int l, int r, int L, int R){
      if(l>r){
        return ;
      }
      int m  =(l+r)/2;
      int k  =-1;
      i64 v= inf;
      for(int i= L; i<=R; i++){
        i64 x = dis[i] +1LL*(i-m)*(i-m);
        if(x<v){
          v=x;
          k=i;
        }
      }
      f[m] =v;
      solve(l, m-1,L,k);
      solve(m+1, r, k, R);
    };
    solve(0,n-1,0,n-1);
    swap(f, dis);
    dijisktra();
  }
  for(int i = 0;i<n;i++){
    cout<<dis[i] <<" \n"[i==n-1];
  }
  return 0;
}
