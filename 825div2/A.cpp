#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >>b[i];
  }
  int mi  =0;
  for(int i =0;i<n;i++)mi+=(a[i]^b[i]);
  int c=count(a.begin(),a.end(),0);
  int d=count(b.begin(),b.end(),0);
  cout<<min(mi,abs(c-d)+1)<<endl;
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
