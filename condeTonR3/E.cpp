#include<bits/stdc++.h>
using namespace std;

using i64=long long;
void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n+1);
  for(int i=0;i<n;i++){
    a[i+1]=a[i]+(s[i]=='('?1:-1);
  }
  auto b=a;
  sort(b.begin(),b.end());
  i64 ans= 0;
  for(int i=1;i<=n;i++){
    ans+=1LL*b[i]*i;
  }
  vector<int>l(n+1),r(n+1,n+1);
  vector<int>t;
  for(int i=0;i<=n;i++){
    while(!t.empty() && a[i] <a[t.back()]){
      r[t.back()]=i;
      t.pop_back();
    }
    l[i] =t.empty() ? -1:t.back();
    t.push_back(i);
  }
  for(int i=0;i<=n;i++){
    ans-= 1LL *a[i]*(i-l[i])*(r[i]-i);
    ans+=a[i];
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
