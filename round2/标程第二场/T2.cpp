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
#define ll long long
void write(ll x){
  if(x<0){putchar('-');x=(-x);}
  if(x>9)write(x/10);
  putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writecs(ll x){write(x);putchar(' ');}

#define pb push_back
#define cout cerr

inline void dmin(LL &x,LL y){if(x>y)x=y;return ;}
inline void dmax(LL &x,LL y){if(x<y)x=y;return ;}

const LL N = 500+95 , inf = (LL)(1e18) ;
LL n,m,S,T,e[N][N],dp[N][N];bool vis[N][N];

#define PL pair<LL,LL>
#define mp make_pair
#define fir first
#define sec second
queue<PL>que[N];
int main(){
  freopen("b.in","r",stdin);freopen("b.out","w",stdout);
  LL TC=read();
  while(TC--){
    n=read();m=read();S=read();T=read();
    for(LL x=1;x<=n;x++)for(LL y=1;y<=n;y++){e[x][y]=inf;dp[x][y]=inf;vis[x][y]=0;}
    for(LL t=1;t<=m;t++){LL u=read(),v=read();dmin(e[u][v],1);}
    for(LL k=1;k<=n;k++)for(LL i=1;i<=n;i++)for(LL j=1;j<=n;j++)dmin(e[i][j],e[i][k]+e[k][j]);
    for(LL t=0;t<=n;t++){while(SZ(que[t]))que[t].pop();}
    dp[T][T]=1;que[1].push(mp(T,T));
    for(LL t=1;t<=n;t++)
      while(SZ(que[t])){
	auto u=que[t].front();que[t].pop();LL x=u.fir,y=u.sec;if(vis[x][y])continue;
	vis[x][y]=1;
	for(LL z=1;z<=n;z++){
	  LL w=dp[x][y]+e[z][x];
	  if(w<=n&&w<dp[z][y]){dp[z][y]=w;que[w].push(mp(z,y));}
	}
	for(LL z=1;z<=n;z++){
	  LL w=dp[x][y]+e[y][z];
	  if(w<=n&&w<dp[x][z]){dp[x][z]=w;que[w].push(mp(x,z));}
	}
	if(x!=y){
	  LL w=dp[x][y]+(e[y][x]-1);
	  if(w<=n&&w<dp[y][x]){dp[y][x]=w;que[w].push(mp(y,x));}
	  if(w<=n&&w<dp[x][x]){dp[x][x]=w;que[w].push(mp(x,x));}
	  if(w<=n&&w<dp[y][y]){dp[y][y]=w;que[w].push(mp(y,y));}
	}
      }
    LL ans=dp[S][S];
    if(ans==inf){puts("-1");continue;}
    writeln(ans);
  }
  return 0;
}
