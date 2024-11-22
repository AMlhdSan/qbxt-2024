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

#define pb push_back
#define cout cerr

inline LL mabs(LL x){return ((x<0)?(-x):(x));}

const LL N = 5000+95 , inf = (LL)(1e18) ;
LL n,C;char ch[N];vector<LL>S,T[2],P[2];LL dp[N][N];
int main(){
  n=read();C=read();
  scanf("%s",ch+1);for(LL i=1;i<=n;i++)if(ch[i]=='2')S.pb(i);
  scanf("%s",ch+1);for(LL i=1;i<=n;i++)if(ch[i]=='2')T[(i&1)].pb(i);
  assert(SZ(S)==SZ(T[0])+SZ(T[1]));
  if(!SZ(S)){puts("0");return 0;}

  P[0].resize(SZ(T[0]));
  for(LL t=0,top=-1;t<SZ(T[0]);t++){
    while(top+1<SZ(T[1])&&T[0][t]>T[1][top+1])top++;
    P[0][t]=top;
  }
  P[1].resize(SZ(T[1]));
  for(LL t=0,top=-1;t<SZ(T[1]);t++){
    while(top+1<SZ(T[0])&&T[1][t]>T[0][top+1])top++;
    P[1][t]=top;
  }
  
  for(LL i=0;i<=SZ(T[0]);i++)
    for(LL j=0;j<=SZ(T[1]);j++)dp[i][j]=inf;
  auto c0=[&](LL s,LL i,LL j){//s -> T[0][i]
	    LL t=T[0][i];LL d=mabs(s-t);
	    return (d>>1)*(C+4)+(d&1)*(C+3)+(max(P[0][i]-(j-1),0ll));
	  };
  auto c1=[&](LL s,LL i,LL j){//s -> T[1][i]
	    LL t=T[1][i];LL d=mabs(s-t);
	    return (d>>1)*(C+4)+(d&1)*(C+3)+(max(P[1][i]-(j-1),0ll));
	  };
  dp[0][0]=0;
  for(LL t=0;t<SZ(S);t++){
    LL s=S[t];
    for(LL i=0;i<=SZ(T[0])&&i<=t;i++){
      LL j=t-i;if(j<0||j>SZ(T[1]))continue;
      if(i<SZ(T[0]))dmin(dp[i+1][j],dp[i][j]+c0(s,i,j));
      if(j<SZ(T[1]))dmin(dp[i][j+1],dp[i][j]+c1(s,j,i));
    }
  }
  writeln(dp[SZ(T[0])][SZ(T[1])]);
  return 0;
}
