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

#define pb push_back

const LL mod = 998244353;
inline void amod(LL &x,LL y){x+=y;if(x>=mod)x-=mod;}
inline void smod(LL &x,LL y){x-=y;if(x<0)x+=mod;}
inline LL dmod(LL x){if(x<0)x+=mod;if(x>=mod)x-=mod;return x;}

inline void EXIT(){puts("0");exit(0);}

const LL N = 5000+95;
LL n,p[N];char type[N];LL dp[N][N];

int main(){
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  n=read();
  for(LL i=1;i<=n;i++)p[i]=read();

  //type[x]='L': x 先于 x+1
  //type[x]='R': x 后于 x+1
  auto makeL=[&](LL x){
	       if(type[x]=='R')EXIT();
	       type[x]='L';return ;
	     };
  auto makeR=[&](LL x){
	       if(type[x]=='L')EXIT();
	       type[x]='R';return ;
	     };
  
  for(LL t=1;t<=n;t++){
    if(!p[t])continue;
    if(p[t]==t){
      cerr<<"!"<<endl;
      puts("0");return 0;
    }
    if(t<p[t]){//t -> p[t]
      if(t>1)makeR(t-1);
      for(LL i=t;i<p[t]-1;i++)makeL(i);
      if(p[t]-1<n-1)makeR(p[t]-1);
    }
    else {//p[t] <- t
      if(t<n)makeL(t-1);
      for(LL i=p[t];i<t-1;i++)makeR(i);
      if(p[t]-1>0)makeL(p[t]-1);
    }
  }
  dp[1][1]=1;
  for(LL t=2;t<=n-1;t++){
    if(type[t-1]=='L'){//t-1 先于 t
      for(LL i=1;i<=t-1;i++)amod(dp[t-1][i],dp[t-1][i-1]);
      for(LL i=1;i<=t-1;i++)dp[t][i+1]=dp[t-1][i];
    }
    else if(type[t-1]=='R'){//t-1 后于 t
      for(LL i=t-1;i>=1;i--)amod(dp[t-1][i],dp[t-1][i+1]);
      for(LL i=t-1;i>=1;i--)dp[t][i]=dp[t-1][i];
    }
    else {
      LL SUM=0;for(LL i=1;i<=t-1;i++)amod(SUM,dp[t-1][i]);
      for(LL i=1;i<=t;i++)dp[t][i]=SUM;
    }
  }
  LL ans=0;
  for(LL i=1;i<=n-1;i++)amod(ans,dp[n-1][i]);
  writeln(ans);
  return 0;
}
