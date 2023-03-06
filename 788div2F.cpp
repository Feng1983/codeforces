#include <vector>
#include<cassert>

using namespace std;
#define rep(i,a,n) for(int i=a; i<n;i++)
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int>BI;

typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1e9+7;
ll powmod(ll a, ll b){ll res=1; a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1) res=res*a%mod; a=a*a%mod;} return res;}
ll gcd(ll a, ll b){
  return b? gcd(b,a%b):a;
}
//head
template<int MOD, int RT> struct mint{
  static const int mod = MOD;
  static constexpr mint rt(){return RT;} //primitive root for fft
  int v; explicit operator int() const {return v;}
  mint():v(0){}
  mint(ll _v){v=int((-MOD <_v && _v<MOD)?_v:_v%MOD);
  if(v <0) v+=MOD;}

  bool operator ==(const mint& o) const{
    return v==o.v;
  }
  friend bool operator !=(const mint&a ,const mint& b){
    return !(a==b);
  }
  friend bool operator < (const mint& a, const mint& b){
    return a.v < b.v;
  }
  mint& operator +=(const mint& o){
    if((v+=o.v)>=MOD) v-=MOD;
    return *this;
  }
  mint& operator -=(const mint& o){
    if((v-=o.v)<0) v+=MOD;
    return *this;
  }
  mint& operator *=(const mint& o){
    v=int((ll) v*o.v%MOD);
    return *this;
  }
  mint& operator /=(const mint& o){
    return *this*inv(o);
  }
  friend mint pow(mint a, ll p){
    mint ans=1; assert(p>=0);
    for(;p;p/=2, a*=a)if(p&1) ans*=a;
    return ans;
  }
  friend mint inv(const mint& a){
    assert(a.v!=0);
    return pow(a, MOD-2);
  }
  mint operator-() const{return mint(-v);}
  mint operator++() const{return *this+=1;}
  mint operator--() const {return *this-=1;}
  friend mint operator+(mint a, const mint& b){return a+=b;}
  friend mint operator-(mint a, const mint& b){return a-=b;}
  friend mint operator*(mint a, const mint& b){return a*=b;}
  friend mint operator/(mint a, const mint& b){return a/=b;}

};
const int MOD=1e9+7;
using mi = mint<MOD, 5>;
namespace simp
{
vector<mi> fac, ifac, invn;
void check(int x){
  if(fac.empty()){
    fac={mi(1), mi(1)};
    ifac={mi(1), mi(1)};
    invn = {mi(0), mi(1)};
  }
  while(SZ(fac)<=x){
    int n = SZ(fac), m=SZ(fac)*2;
    fac.resize(m);
    ifac.resize(m);
    invn.resize(m);
    for(int i=n;i<m;i++){
      fac[i] = fac[i-1]*mi(i);
      invn[i] = mi(MOD-MOD/i)*invn[MOD%i];
      ifac[i] = ifac[i-1]*invn[i];
    }
  }
}
mi gfac(int x){
  check(x); return fac[x];
}
mi ginv(int x){
  check(x); return invn[x];

}
mi gifac(int x){
  check(x); return ifac[x];
}
mi binom(int n,int m){
  if(m<0|| m>n) return mi(0);
  return gfac(n)*gfac(m)*gifac(n-m);
}
}

