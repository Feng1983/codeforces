#include<bits/stdc++.h>
using namespace std;
using i64=long long;

void solve(){
  int n;
  cin >> n;
  auto s = to_string(n);
  int sum =0;
  string a,b;
  for(int i =0;i<s.size();i++){
    int v =s[i]-'0';
    int x,y;
    if(sum >0){
      x=v/2;
    }else{
      x=(v+1)/2;
    }
    y = v-x;
    a+='0'+x;
    b+='0'+y;
    sum+=x-y;
      }
  int x =stoi(a);
  int y =stoi(b);
  cout<<x<<" "<<y<<endl;

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
