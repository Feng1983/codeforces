#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  if(count(a.begin(),a.end(), a[0])==n){
    cout<<0<<endl;
    return;
  }
  if(count(a.begin(),a.end(),1) >0){
    cout<<-1<<endl;
    return;
  }
  vector<pair<int,int>> ans;
  while(count(a.begin(), a.end(),a[0])<n && count(a.begin(),a.end(),2)==0){
    int i=1;
    while(a[0] ==a[i]){
      i++;
    }
    if(a[0] >a[i]){
      ans.emplace_back(1,i+1);
      a[0] = (a[0]+a[i]-1)/a[i];
    }else{
      ans.emplace_back(i+1,1);
      a[i] =(a[i]+a[0]-1)/a[0];
    }
  }
  if(count(a.begin(),a.end(),a[0]) <n){
    int i = find(a.begin(),a.end(),2)-a.begin();
    for(int j=0;j<n;j++){
      while(a[j]!=2){
        ans.emplace_back(j+1,i+1);
        a[j] = (a[j]+1)/2;
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto [x,y] : ans){
    cout<<x <<" "<<y<<endl;
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
