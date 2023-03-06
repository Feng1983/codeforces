#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  n=n*2;
  string s;
  cin >> s;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]=='1')cnt++;
  }
  if(cnt&1){
    cout<<"-1\n";
    return;
  }
  int cur=0;
  vector<int> ms;
  for(int i = 0;i<n;i+=2){
    if(s[i]==s[i+1])continue;
    if(s[i]-'0'==cur){
      ms.push_back(i+1);
    }else{
      ms.push_back(i+2);
    }
    cur^=1;
  }
  if(ms.size()){
    cout<<ms.size()<<" ";
    for(int i =0;i<ms.size();i++){
      cout<<ms[i]<<" ";
    }
    cout<<endl;
  }else{
    cout<<ms.size()<<endl;
  }
  for(int i=1;i<=n;i+=2){
    cout<<i<<" ";
  }
  cout<<endl;
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
