#include<bits/stdc++.h>
using namespace std;

constexpr int P = 1e9+7;
using i64 = long long;
int norm(int x){
  if(x <0){
    x+=P;
  }
  if(x>=P){
    x-=P;
  }
  return x;
}
template<class T>
T power(T a, i64 b){
  T res =1;
  for(;b;b/=2, a*=a){
    if(b%2){
      res*=a;
    }
  }
  return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
void solve(){



}
int main(){
  int n,k;
  cin >> n>> k;

  vector<Z>fac(n+1), invfac(n+1);
  fac[0] =1;
  for(int i =1;i<=n;i++){

    fac[i] = fac[i-1]*i;
  }
  invfac[n]=fac[n].inv();
  for(int i = n;i;i--){
    invfac[i-1] = invfac[i]*i;
  }
  Z ans= 0;
  for(int i = 0;i<=min(n,k);i++){
    ans+= fac[n]*invfac[i]*invfac[n-i];
  }
  cout<<ans<<endl;

}
