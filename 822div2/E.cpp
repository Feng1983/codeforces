#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >>a[i];
    a[i]-=i*i;
    a[i]%=n;
    if(a[i] <0)a[i]+=n;
  }
  for(int i=0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout<<(i*j+a[i])%n<<" \n"[j==n-1];
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  //cin >> t;
  t=1;
  while(t--){
    solve();
  }
  return 0;
}
