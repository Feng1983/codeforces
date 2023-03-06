#include<bits/stdc++.h>
//#include "headerlist.cpp"

using namespace std;
void solve(){
  string s;
  cin >> s;
  const int n = s.size();
  char x= '9';
  array<int,10>cnt{};
  for(int i=n-1;i>=0;i--){
    if(s[i]<=x){
      cnt[s[i]-'0']++;
      x=s[i];
    }else{
      cnt[min(9,s[i]-'0'+1)]++;
    }
  }
  for(int i=0;i<10;i++){
    cout<<string(cnt[i],'0'+i);
  }
  cout<<endl;
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
