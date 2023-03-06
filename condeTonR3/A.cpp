#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin >>n;
  vector<int> a(n);
  for(int i =0;i<n;i++){
    cin >>a[i];
  }
  cout<<(a[0]==1?"YES":"NO")<<endl;
  
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
