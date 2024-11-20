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

const LL inf = (LL)(1e16) ;
template<LL N,LL M>struct mcmf{
  struct edge{LL to,nxt,w,c;}e[M<<1];LL head[N],cur[N],tot=1,n,S,T;
  inline void init(LL _n,LL _S,LL _T){n=_n;S=_S;T=_T;tot=1;for(LL t=1;t<=n;t++)head[t]=0;return ;}
  inline void _add_e(LL u,LL v,LL w,LL c){e[++tot].to=v;e[tot].nxt=head[u];e[tot].w=w;e[tot].c=c;head[u]=tot;return ;}
  inline void add_e(LL u,LL v,LL w,LL c){_add_e(u,v,w,c);_add_e(v,u,0,-c);}
  LL dis[N];bool vis[N];
  inline bool spfa(){
    for(LL t=1;t<=n;t++){dis[t]=-inf;cur[t]=head[t];}
    queue<LL>q;q.push(S);dis[S]=0;vis[S]=1;
    while(SZ(q)){
      LL x=q.front();q.pop();vis[x]=0;
      for(LL i=head[x];i;i=e[i].nxt){
	LL y=e[i].to,w=e[i].w,c=e[i].c;
	if(w&&dis[y]<dis[x]+c){dis[y]=dis[x]+c;if(!vis[y]){q.push(y);vis[y]=1;}}
      }
    }
    return (dis[T]!=-inf);
  }
  bool inq[N];
  LL dfs(LL x,LL flow){
    if(x==T)return flow;
    inq[x]=1;LL lastflow=flow;
    for(LL i=cur[x];i&&flow;i=e[cur[x]].nxt){
      cur[x]=i;
      LL y=e[i].to,w=e[i].w,c=e[i].c;
      if(!inq[y]&&w&&dis[y]==dis[x]+c){LL d=dfs(y,min(flow,w));if(d){e[i].w-=d;e[i^1].w+=d;flow-=d;}}
    }
    inq[x]=0;if(lastflow==flow)dis[x]=inf;
    return lastflow-flow;
  }
  inline LL doit(){
    LL maxflow=0,mincost=0;
    while(spfa()){
      if(dis[T]<0)return mincost;
      LL flow=dfs(S,inf);
      maxflow+=flow;mincost+=flow*dis[T];
    }
    return mincost;
  }
};

const LL N = 60+5 ;
LL n;struct Edge{LL to,nxt;}e[N<<1];LL head[N],tot=1;
inline void add_e(LL u,LL v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;return ;}

bool vis[N];void dfs(LL x,LL fa){vis[x]=1;for(LL i=head[x];i;i=e[i].nxt){if(e[i].to!=fa){dfs(e[i].to,x);}}return ;}

vector<LL>st;vector<LL>son[N];
void DFS(LL x,LL fa,LL I){
  st.pb(x);son[x].clear();
  for(LL i=head[x];i;i=e[i].nxt){
    LL y=e[i].to;if(y==fa||y==I)continue;
    DFS(y,x,I);son[x].pb(y);
  }
  return ;
}
vector<LL>vcA,vcB;LL dp[N][N],idx[N];mcmf<N,N*(N+2)>T;

int main(){
  freopen("d.in","r",stdin);freopen("d.out","w",stdout);
  n=read();
  for(LL t=1;t<n;t++){LL u=read(),v=read();add_e(u,v);add_e(v,u);}

  LL ans=0;
  for(LL A=1;A<=n;A++){
    for(LL i=head[A];i;i=e[i].nxt){
      for(LL x=1;x<=n;x++)vis[x]=0;
      LL C=e[i].to;dfs(C,A);
      for(LL B=1;B<=n;B++)
	if(vis[B]){// A 和 B 以断开边 (A,C) 为主体
	  st.clear();DFS(A,0,C);vcA=st;reverse(all(vcA));
	  st.clear();DFS(B,0,A);vcB=st;reverse(all(vcB));
	  for(auto x:vcA)
	    for(auto y:vcB){
	      dp[x][y]=1;LL Id=0;idx[x]=++Id;idx[y]=++Id;
	      for(auto a:son[x])idx[a]=++Id;
	      for(auto b:son[y])idx[b]=++Id;
	      LL _S=++Id,_T=++Id;T.init(Id,_S,_T);
	      for(auto a:son[x])
		for(auto b:son[y])T.add_e(idx[a],idx[b],1,dp[a][b]);
	      for(auto a:son[x])T.add_e(_S,idx[a],1,0);
	      for(auto b:son[y])T.add_e(idx[b],_T,1,0);
	      dp[x][y]=1+T.doit();
	    }
	  dmax(ans,dp[A][B]);
	}
    }
  }
  writeln(ans);
  return 0;
}
