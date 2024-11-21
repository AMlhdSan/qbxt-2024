#include<bits/stdc++.h>
#define LL long long
#define SZ(x) ((LL)(x.size()))
#define all(x) (x).begin(),(x).end()
using namespace std;
inline LL read(){
  LL q=0,w=1;char ch=getchar();
  while(ch>'9' || ch<'0'){if(ch=='-')w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){q=q*10+(ch-'0');ch=getchar();}
  return q*w;
}
void write(LL x){
  if(x<0){putchar('-');x=(-x);}
  if(x>9)write(x/10);
  putchar('0'+x%10);
}
inline void writeln(LL x){write(x);puts("");}
inline void writecs(LL x){write(x);putchar(' ');}

inline void dmin(LL &x,LL y){if(x>y)x=y;return ;}
inline void dmax(LL &x,LL y){if(x<y)x=y;return ;}

#define cout cerr
#define pb push_back

inline LL qpow(LL a,LL b,LL p){LL ans=1;while(b){if(b&1)ans=(ans*a)%p;b>>=1;a=(a*a)%p;}return ans;}
const LL mod = 1000000007 ;
inline void amod(LL &x,LL y){x+=y;if(x>=mod)x-=mod;}
inline void smod(LL &x,LL y){x-=y;if(x<0)x+=mod;}
inline LL dmod(LL x){if(x<0)x+=mod;if(x>=mod)x-=mod;return x;}
inline LL inv(LL x){return qpow(x,mod-2,mod);}

const LL SIZE = 10000000+95 , lim = 10000001;
LL Fac[SIZE],Inv[SIZE];
inline LL C(LL n,LL k){
  if(n<0||k<0||n<k)return 0;
  return (Fac[n]*Inv[k]%mod*Inv[n-k]%mod);
}

const LL N = 1500+95 , M = 500+95 , B = 40 ;
LL n,m,a[N*M],f[N],dp0[N][N],dp1[N][N],coef[N];

int main(){
  freopen("d.in","r",stdin);freopen("d.out","w",stdout);
  Fac[0]=1;for(LL i=1;i<=lim;i++)Fac[i]=(Fac[i-1]*i)%mod;
  Inv[lim]=inv(Fac[lim]);for(LL i=lim-1;i>=0;i--)Inv[i]=(Inv[i+1]*(i+1))%mod;

  n=read();m=read();for(LL t=1;t<=n*m;t++)a[t]=read();

  f[0]=1;
  for(LL t=1;t<=n*m;t++)
    for(LL i=n;i>=1;i--)amod(f[i],f[i-1]*a[t]%mod);

  //对元素数量 <= B*m 的组进行 dp
  dp0[0][0]=1;
  for(LL t=0;t<=n;t++)
    for(LL i=t;i<=n;i++)
      for(LL k=0;i+k<=n&&k<=B;k++)amod(dp0[t+1][i+k],dp0[t][i]*Inv[(k*m-1)]%mod);

  //对元素数量 > B*m 的组进行 dp
  dp1[0][0]=1;
  for(LL t=0;t<=(n/B);t++)
    for(LL i=t;i<=n;i++)
      for(LL k=B+1;i+k<=n;k++)amod(dp1[t+1][i+k],dp1[t][i]*Inv[(k*m-1)]%mod);

  for(LL t0=0;t0<=n;t0++)
    for(LL t1=0;t0+t1<=n&&t1<=(n/B);t1++)
      for(LL i=t0;i<=n;i++)amod(coef[t0+t1],dp0[t0][i]*dp1[t1][n-i]%mod*C(t0+t1,t0)%mod);

  LL ans=0;
  for(LL t=1;t<=n;t++)amod(ans,coef[t]*f[t]%mod*Fac[(n*m-t)]%mod);
  writeln(ans);
  return 0;
}
