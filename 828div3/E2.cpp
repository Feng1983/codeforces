#include<bits/stdc++.h>
#include<numeric>
using namespace std;

using i64=long long;
map<int,int> fact(int x){
  map<int,int> ans;
  for(int i=2;i<=int(1e5);i++){
    int cur=0;
    while(x%i==0){
      x/=i;
      cur++;
    }
    if(cur){
      ans[i]=cur;
    }
  }
  if(x>1){
    ans[x]=1;
  }
  return ans;
}
template<typename T>
void dfs(int ind, i64 x, const vector<pair<int,int>>& arr, const T& t){
  if(ind==arr.size()){
    t(x);
    return;
  }
  dfs(ind+1, x, arr, t);
  auto& [k,v] = arr[ind];
  for(int i =0;i<v;i++){
    x*=k;
    dfs(ind+1, x,arr, t);
  }
}
void solve(){
  int a,b,c,d;
  cin >> a>> b>>c >>d;
  auto cfact= fact(a);
  for(auto& [k,v]:fact(b)){
    cfact[k]+=v;
  }
  vector<pair<int,int>> fact(begin(cfact),end(cfact));
  bool ans =false;
  auto smul=[&](long long x, long long ceil)->long long{

    return (ceil/x)*x;
  };
  dfs(0,1, fact,[&](i64 cx)->void{
        if(ans){
          return;
        }
        long long cy= i64(a)*b/cx;
        i64 x = smul(cx,c), y=smul(cy,d);
        if(x>a && b<y){
          cout<<x <<" "<<y<<endl;
          ans= true;
        }
      });
  if(!ans){
    cout<<-1<<" "<<-1<<endl;
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
  return 0;

}
