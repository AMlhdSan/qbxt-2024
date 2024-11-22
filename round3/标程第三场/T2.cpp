#include<bits/stdc++.h>
#define LL long long
#define SZ(x) ((LL)(x.size()))
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
void writeln(LL x){write(x);puts("");}
void writecs(LL x){write(x);putchar(' ');}

inline void dmin(LL &x,LL y){if(x>y)x=y;return ;}

const LL N = 2000+95 , L = 30 , inf = (LL)(1e18) ;
LL n,X,a[N],b[N],tr[N][L+2],ord[N],dp[N][N];
int main(){
  freopen("b.in","r",stdin);freopen("b.out","w",stdout);
  n=read();X=read();LL _n=0,_X=0;
  for(LL i=1;i<=n;i++){
    LL A=read(),B=read();
    if(A==1){X-=B;_X+=B;continue;}
    _n++;a[_n]=A;b[_n]=B;
  }
  if(!_n){writecs(1);writeln(_X);return 0;}
  n=_n;
  for(LL t=1;t<=n;t++){
    LL k=1;
    while(t+k-1<=n&&k<=L){
      LL l=t,r=t+k-1;for(LL i=l;i<=r;i++)ord[i]=i;
      sort(ord+l,ord+r+1,[&](LL x,LL y){return (b[x]*(a[y]-1))<(b[y]*(a[x]-1));});
      LL x=0;for(LL i=l;i<=r;i++)x=(a[ord[i]]*x+b[ord[i]]);
      if(x>X)break;
      tr[t][k]=x;k++;
    }
    while(t+k-1<=n&&k<=L){tr[t][k]=X+1;k++;}
  }

  for(LL t=0;t<=n;t++)for(LL i=0;i<=n;i++)dp[t][i]=inf;
  
  dp[0][0]=0;
  for(LL l=1;l<=n;l++)
    for(LL r=l;r<=n&&(r-l+1)<=L;r++)
      for(LL i=0;i<=n;i++)if(dp[l-1][i]!=inf)dmin(dp[r][i+1],dp[l-1][i]+tr[l][(r-l+1)]);
  for(LL t=1;t<=n;t++)
    if(dp[n][t]<=X){writecs(t);writeln(dp[n][t]+_X);return 0;}
  assert(0);return 0;
}
