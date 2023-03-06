#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 998244353
#define b(x) (1 << ((x)-1))

int i, j, k, m, n, t, num;
ll f[300500][20];
char s[10050];

ll su(ll a, ll b) {
  a += b;
  return (a >= M) ? a - M : a;
}
ll ksm(ll a, ll p){
  ll res = 1ll;
  while (p) {
    if (p & 1) {
      res = res * a % m;
    }
    a = a * a % M;
    p >>= 1;
  }
  return res;
}

void chk(int l, int r, int t){
  int msk=0, t1=num;
  ll sb=1;
  while( l>=1 && r<=n){
    if(s[l] == '?' && s[r]=='?'){
      sb= sb*t%M; t1-=1+(l!=r);
    }
    if(s[l]=='?'&& s[r]!='?'){
      msk|= b(s[r]-'a'+1);t1-=1;
    }
    if(s[l]!='?' && s[r]=='?'){
      msk|=b(s[l]-'a'+1);t1-=1;
    }
    if(s[l]!='?'&& s[r]!='?'){
      if(s[l]!=s[r])break;
    }
    f[msk][t] = su(f[msk][t], sb*ksm(t,t1)%M);
    l--;r++;
  }
}
int main(){
  cin >> n >>s+1;
  for(i=1;i<=n;i++)num+=(s[i]=='?');
  for(i=1;i<=n;i++){
    for(j=1;j<=17;j++){
      chk(i,i,j);
      if(i<n) chk(i,i+1,j);
    }
  }
  for(t=1;t<=17;t++){
    for(i=1;i<=17;i++){
      for(j=1;j<b(18);j++){
        if(j&b(i)){
          f[j][t]= su(f[j][t], f[j^b(i)][t]);
        }
      }
    }
  }
  cin >>t;
  while(t--){
    int msk=0;
    string s;
    cin >>s;
    for(auto i:s){
      i-='a'-1; msk|=b(i);
    }
    cout <<f[msk][s.size()]<<endl;
  }
}
