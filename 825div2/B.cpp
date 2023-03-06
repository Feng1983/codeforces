#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n ;
  cin >> n;
  vector<int>a(n);
  for(int i = 0;i<n;i++){
    cin >>a[i];
  }
  bool flag=true;
  for(int i=1;i<n-1;i++){
    int t = gcd(a[i-1],a[i+1]);
    if(a[i]%t) flag=false;
  }
  if(flag){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
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
