#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;

  if(s.find('1')==string::npos){
    cout<<0<<endl;
    return 0;
  }
  int a =s.find('1');
  if(s.substr(a).find('0') ==string::npos){
    cout<<s.substr(a)<<endl;
    return 0;
  }
  int b =a+s.substr(a).find('0');
  auto ans =s;
  for(int i = 0;i<=b-a;i++){
    auto res =s;
    for(int j =0;j+i<n;j++){
      res[j+i] |= s[j];
    }
    ans =max(ans, res);
  }
  ans =ans.substr(ans.find('1'));
  cout<<ans<<endl;
}
