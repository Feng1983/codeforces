#include<bits/stdc++.h>
using namespace std;

const long long inf =1e18;
long long n,m,d,d2,d3, ttl=0,a[1000069],ca[1000069],wg[1000069],dp[21][1000069],tmp[1000069],z=inf;

bitset<1000069>vtd;
vector<long long>ex[1000069];

inline void cop(long long cdh){
  long long i;
  for(i=0;i<d3;i++){
    dp[cdh][i] = dp[cdh-1][i];
  }
}
inline void ad(long long cdh, long long x, long long y){
  long long i, w=wg[x*d3+y];
  for(i=0;i<d3;i++){
    tmp[(y+i)%d3] =min(tmp[(y+i)%d3],dp[cdh][i]+w);
  }
}
inline void ad2(long long cdh, long long x, long long y){
  ad(cdh,x,y%d3);
  ad(cdh,x, (y+m/2)%d3);
  ad(cdh,x, (y+(m+1)/2)%d3);
}
void dnc(long long cdh, long long lh, long long rh){
  if(lh==rh){
    long long i;
    for(i=0;i<d3;i++){
      z=min(z, dp[cdh][i]+wg[lh*d3+(ttl+d3-i)%d3]);
    }
  }else{
    long long i,j,k,sz, md=(lh+rh)/2;
    cop(cdh+1);
    for(i=md+1;i<=rh;i++){
      for(j=0;j<d3;j++){
        tmp[j]=inf;
      }
      sz =ex[i].size();
      for(j=0;j<sz;j++){
        k=ex[i][j];
        ad2(cdh+1,i,k);
      }
      for(j=0;j<d3;j++){
        dp[cdh+1][j]=tmp[j];
      }
    }
    dnc(cdh+1,lh,md);
    cop(cdh+1);
    for(i=lh;i<=md;i++){
      for(j=0;j<d3;j++){
        tmp[j]=inf;
      }
      sz= ex[i].size();
      for(j=0;j<sz;j++){
        k= ex[i][j];
        ad2(cdh+1,i,k);
      }
      for(j=0;j<d3;j++){
        dp[cdh+1][j]=tmp[j];
      }
    }
    dnc(cdh+1,md+1,rh);
  }
}



int main(){
  long long i,j,r,w,p,gd;
  scanf("%lld%lld%lld",&n,&m,&d);
  //cin>> n>>m>>d;
  d2=gcd(n,d);
  gd=gcd(m,d/d2);
  d3=m/gd;
  for(i=0;i<n;i++){
    scanf("%lld",a+i);
    //cin>> a[i];
  }
  for(i=0;i<d2;i++){
    w=0;
    for(j=0;j<m;j++){
      ca[j]=0;
    }
    for(p=i;!vtd[p];p=(p+d)%n){
      vtd[p]=1;
      ttl = (ttl+w*(p<d))%m;
      ex[i].push_back(w);
      for(j=0;j<m;j++){
        ca[j]+=min(abs(j-w),m-abs(j-w));
      }
      w=(w+a[(p+1)%n]+m-a[p])%m;
    }
    if(w){
      //cout<<-1<<endl;
      printf("-1\n");
      return 0;
    }
    for(j=0;j<d3;j++){
      wg[i*d3+j] = inf;
      for(r=j;r<m;r+=d3){
        wg[i*d3+j]=min(wg[i*d3+j],ca[r]);
      }
    }
  }
  ttl =(ttl+m-a[0])%m;
  if(ttl%gd){
    //cout<<-1<<endl;
    printf("-1\n");
    return 0;
  }
  ttl/=gd;
  for(i=0;i<d3;i++){
    if((i*(d/d2/gd))%d3==ttl){
      ttl= i;
      break;
    }
  }
  for(i=1;i<d3;i++){
    dp[0][i] = inf;
  }
  dnc(0,0,d2-1);
  //cout<<z<<endl;
  printf("%lld\n",z);
}
