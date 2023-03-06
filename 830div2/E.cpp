#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
template<typename hd, typename tl> void chkmin(hd&a, tl b){if(a>b)a=b;}
template<typename hd, typename tl> void chkmax(hd&a, tl b){if(a<b)a=b;}

using LL =long long;
using PI = pair<LL,LL>;
using VI = vector<LL>;

const LL N  =50005;
const LL INF = 1000000000000000LL;
LL n,q;
LL a[N],b[N];
LL c[N];
VI fac[N];
set<PI>S;

struct WinnerTree{
  VI p,v;
  LL n;
  void init(){
    p.clear(),v.clear();
    n=0;
  }
  void insert(LL a, LL b){
    p.push_back(a),v.push_back(b);
  }
  void build(){
    LL an= p.size(), i;
    for(n=1;n<an;n*=2);
    v.resize(n*2+2);
    for(i=0;i<an;i++)v[n+i] =v[i];
    for(i=an;i<n;i++)v[n+i]=v[0];
    for(i=n-1;i>0;i--)v[i] =min(v[i*2],v[i*2+1]);
  }
  LL get(LL st, LL en){
    LL rlt = N;
    st =lower_bound(p.begin(),p.end(),st)-p.begin();
    en= upper_bound(p.begin(),p.end(),en)-p.begin();
    st+=n, en+=n;
    while(st<en){
      if(st&1)rlt =min(rlt, v[st]);
      if(en&1)rlt= min(rlt,v[en-1]);
      st=(st+1)/2;
      en/=2;
    }
    return rlt;
  }
}WT[N];
struct SegmentTree{
  LL v[N*4], d[N*4];
  inline void add(LL u, LL dd){
    v[u]=d[u]=dd;
  }
  inline void down(LL u){
    LL & dd= d[u];
    if(dd==-1)return;
    add(u*2,dd);
    add(u*2+1,dd);
    dd=-1;
  }
  inline void up(LL u){
    v[u] = min(v[u*2],v[u*2+1]);
  }
  void build(LL u, LL st, LL en){
    d[u]=-1;
    if(st==en){
      v[u] = c[st];
      return;
    }
    LL md=(st+en)/2;
    build(u*2,st,md);
    build(u*2+1, md+1,en);
    up(u);
  }
  void update(LL u, LL st, LL en, LL l, LL r, LL dd){
    if(l<=st && en<=r){
      add(u,dd);
      return;
    }
    LL md =(st+en)/2;
    down(u);
    if(l<=md) update(u*2, st,md,l,r,dd);
    if(r>md) update(u*2+1,md+1,en,l,r,dd);
    up(u);
  }
  LL get(LL u, LL st, LL en, LL l, LL r){
    if(l<=st && en<=r)return v[u];
    LL md = (st+en)/2;
    down(u);
    LL rlt= INF;
    if(l<=md)rlt = min(rlt,get(u*2, st,md, l,r));
    if(r>md) rlt= min(rlt, get(u*2+1, md+1,en,l,r));
    up(u);
    return rlt;
  }
}Seg;

inline LL calc(LL a, LL b){
  LL c=gcd(a,b);
  return 1LL*a/c*b/c;
}
LL calc_b(LL i, LL l, LL r){
  LL mn=INF;
  for(LL u: fac[i]){
    LL val  =WT[u].get(l,r);
    if(val==N)continue;
    chkmin(mn, calc(i,val));
  }
  return mn;
}
void update(LL l, LL r, LL u){
  auto it=S.lower_bound(PI(l,N));it--;
  LL st= it->first;
  while(it->second <=r){
    it=S.erase(it);
    if(it==S.end())break;
  }
  if(it==S.end() ||it->first>r){
    if(st<l){
      S.insert(PI(st,l-1));
      Seg.update(1,0,n-1,st,l-1,calc_b(a[st],st,l-1));
    }
    S.insert(PI(l,r));
    a[l] = u;
    Seg.update(1,0,n-1,l,r,calc_b(u,l,r));
  }else{
    LL en = it->second, val = a[it->first];
    S.erase(it);
    if(st <l){
      S.insert(PI(st,l-1));
      Seg.update(1, 0, n - 1, st, l - 1, calc_b(a[st], st, l - 1));
    }
    S.insert(PI(l,r));
    a[l]=u;
    Seg.update(1,0,n-1,l,r,calc_b(u,l,r));
    S.insert(PI(r+1,en));
    a[r+1]=val;
    Seg.update(1,0,n-1,r+1,en,calc_b(val, r+1,en));
  }
}
LL query(LL l, LL r){
  auto it=S.lower_bound(PI(l,N));it--;
  if(it->second >=r)return calc_b(a[it->first],l,r);
  LL rlt= calc_b(a[it->first ],l,it->second);
  LL st=it->second+1;
  it = S.lower_bound(PI(r,N));it--;
  chkmin(rlt, calc_b(a[it->first],it->first,r));
  LL en =it->first -1;
  if(en>=st)chkmin(rlt, Seg.get(1,0,n-1,st,en));
  return rlt;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  LL i,j;
  cin >> n>> q;
  for(i=0;i<n;i++)cin >>a[i];
  for(i=0;i<n;i++)cin >> b[i];
  for(i=0;i<n;i++)c[i] = calc(a[i],b[i]);
  Seg.build(1,0,n-1);
  for(i=1;i<N;i++){
    for(j=i;j<N;j+=i)fac[j].push_back(i);
    WT[i].init();
  }
  for(i=0;i<n;i++){
    for(LL u: fac[b[i]]){
      WT[u].insert(i,b[i]);
    }
  }
  for(i=0;i<N;i++)WT[i].build();
  for(i=0;i<n;i++)S.insert(PI(i,i));
  while(q--){
    LL t, l, r, x;
    cin >> t;
    if(t==1){
      cin >> l >> r >>x;
      l--,r--;
      update(l,r,x);
    }else{
      cin >> l >> r;
      l--,r--;
      cout<<query(l,r)<<endl;
    }
  }

  return 0;
}
