#include<bits/stdc++.h>
#define LL long long
#define SZ(x) ((LL)(x.size()))
#define all(x) (x).begin(),(x).end()
using namespace std;
inline LL read(){LL x=0;cin>>x;return x;}
void write(LL x){cout<<x;return ;}
inline void writeln(LL x){write(x);puts("");}
inline void writecs(LL x){write(x);putchar(' ');}

inline void dmin(LL &x,LL y){if(x>y)x=y;return ;}

const LL N = 10000+95 ;
LL n,w[N],dp[N][N],coef[N];

inline LL f(LL x){return ((!(x&1))?(0):((f((x+1)>>1)<<1)|1));}
int main(){
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  LL TC=read();
  while(TC--){
    n=read();for(LL t=1;t<=n;t++)w[t]=read();
    sort(w+1,w+n+1);
    for(LL t=1;t<=n;t++)w[t]+=w[t-1];

    for(LL t=2;t<=n;t++)coef[t]=f(t);
    for(LL t=0;t<=n;t++)for(LL i=0;i<=t;i++)dp[t][i]=(LL)(1e18);
    dp[0][0]=0;
    for(LL t=0;t<=n;t++){
      for(LL i=t;i>=0;i--){if(!(i&1)){dmin(dp[t][(i>>1)],dp[t][i]+w[t]);}}
      for(LL i=0;i<=t;i++){if(t+1<=n){dmin(dp[t+1][i+1],dp[t][i]+coef[i+1]);}}
    }
    writeln(dp[n][1]);
  }
  return 0;
}
