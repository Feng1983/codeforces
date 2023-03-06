#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <array>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int>p(n);
  vector<vector<int>> adj(n);

  p[0]=-1;
  for(int i  =1;i<n;i++){
    cin >> p[i];
    p[i]--;
    adj[p[i]].push_back(i);
    adj[i].push_back(p[i]);
  }
  vector<int>d(n,-1);
  queue<array<int,2>> que;

  for(int i = 0;i<n;i++){
    if(adj[i].size()==1){
      que.push({i,0});
    }
  }
  while(!que.empty()){
    auto[ x,v] = que.front();
    que.pop();

    if(d[x]!=-1){
      continue;
    }
    d[x] =v;
    for(auto y: adj[x]){
      que.push({y, v+1});
    }
  }

  vector<int> euler(n);
  int cur= 0;
  const int log = __lg(2*n-1)+1;
  vector<vector<int>> st(2*n-1, vector<int>(log+1));
  vector<int> dep(n);

  function<void(int)> dfs=[&](int x){
    st[cur][0] =x;
    euler[x] =cur++;
    for(auto y: adj[x]){
      if(y==p[x]){
        continue;
      }
      dep[y] =dep[x]+1;
      dfs(y);
      st[cur++][0] =x;
    }
  };
  dfs(0);
  for(int j = 0; j< log;j++){
    for(int i =0 ;i+(2<<j)<=2*n-1;i++){
      st[i][j+1] = dep[st[i][j]]< dep[st[i+(1<<j)][j]]? st[i][j]:st[i+(1<<j)][j];
    }
  }
  auto lca= [&](int x, int y){
    x = euler[x];
    y = euler[y];
    if(x > y){
      swap(x, y);
    }
    int k  = __lg(y-x+1);
  return st[x][k] < st[y+1-(1<<k)][k]? st[x][k] :st[y+1-(1<<k)][k];
  };

  auto dist= [&](int x, int y){
    return dep[x]+dep[y] -2*dep[lca(x,y)];
  };

  const int maxd = *max_element(d.begin(), d.end());
  vector<array<int,3 >> a(maxd+1, {-1,-1,-1});
  auto merge= [&](auto a, auto b){
    if(a[0]==-1){
      return b;
    }
    if(b[0]==-1){
      return a;
    }
    auto c = max(a,b);
    for(auto x: {a[1],a[2]}){
      for(auto y : {b[1],b[2]}){
        c =max(c, array{dist(x,y), x,y});
      }
    }
    return c;
  }
  for(int i = 0;i<n;i++){
    a[d[i]]=merge(a[d[i]], array{0,i,i});

  }
  auto suf= a;
  for(int i =maxd-1;i>=0;i--){
    suf[i] = merge(suf[i], suf[i+1]);
  }
  auto check=[&](int ans, int i, int x){
    int j  =max(0, ans-i-x);
    if(j> maxd){
      return false;
    }
    
    for(auto x: {a[i][1], a[i][2]}){
      for( auto y: {suf[j][1], suf[j][2]}){
        if(dist(x,y) >=ans){
          return true;
        }
      }
    }
    return false;
  };
    
  int q;
  cin >> q;
  for(int  t=0; t<q; t++){
    int x;
    cin >> x;
    int ans=0;
    for(int i=0;i<=maxd; i++){
      while(check(ans+1, i, x)){
        ans++;
      }
    }
    cout<<ans<<" \n"[i==q-1];

  }
  return 0;
}
