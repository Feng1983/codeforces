#include<bits/stdc++.h>
//#include "headerlist.cpp"
using namespace std;

void solve(){
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  map<pair<char,char>, int> cnt;
  for(int i = 0;i<n;i++){
    cnt[minmax(s1[i],s2[n-1-i])]++;
  }
  int odd= 0;
  for(auto[v,x]:cnt){
    if(x%2==1 && v.first!=v.second){
      cout<<"NO\n";
      return ;
    }
    odd+=x%2;
  }
  if(odd<=1){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<std::fixed;
  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
