#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  vector<int>g;
  for(int j=0;j<n*2;j++){
    if(s[j%n]=='g'){
      g.push_back(j);
    }
  }
  int ans =0;
  for(int j =0;j<n;j++){
    if(s[j]==c){
      ans =max(ans, *lower_bound(g.begin(),g.end(),j)-j);
    }
  }
  cout<<ans<<endl;
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
