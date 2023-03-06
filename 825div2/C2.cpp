#include<bits/stdc++.h>

using namespace std;
using i64=long long;
const int N = 2e5+5;

i64 a[N],pref[N], sref[N], f[N],s[N];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i<=n;i++){
    cin >>a[i];
  }
  int j = 1, k=1;
  for(int i=1;i<=n;i++){
    while(j<=n && a[j]>=j-i+1)f[j++]=i;
    k = min(max(k, j+1),n+1);
    while(k<=n && a[k]>=k-i+1){
      k++;
    }
    if(s[j]==0)s[j]=i;
    pref[i] = pref[i-1]+(j-i);
    sref[i] = sref[i-1]+(k-i);
  }
  int q,p,x;
  cin >> q;
  while(q--){
    cin >> p >>x;
    i64 ans = pref[n];
    if(x<a[p] && f[p]<=p-x){
      ans-= pref[p-x]-pref[f[p]-1];
      ans+=(p-x-f[p]+1)*(p-f[p]+x)/2;
    }else if(x >a[p] && s[p]){
      ans-=pref[f[p]-1]- pref[max(p-i64(x),s[p]-1)];
      ans+=sref[f[p]-1]- sref[max(p-i64(x),s[p]-1)];
    }
    cout<<ans<<endl;
  }

}
 int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  //cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
