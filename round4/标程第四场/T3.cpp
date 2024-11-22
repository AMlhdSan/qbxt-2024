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

const LL N = 1000000+95 ;
LL TC,n,a[N];vector<LL>E[N];

LL fa[N],dep[N],sz[N],son[N];
void dfs(LL x){
  dep[x]=dep[fa[x]]+1;sz[x]=1;son[x]=0;
  for(auto y:E[x])
    if(y!=fa[x]){
      fa[y]=x;dfs(y);sz[x]+=sz[y];
      if(sz[son[x]]<sz[y])son[x]=y;
    }
  return ;
}
LL dfn[N],low[N],tim,seq[N],pf[N];
void dfs2(LL x,LL ac){
  dfn[x]=++tim;seq[tim]=x;pf[x]=ac;
  if(son[x])dfs2(son[x],ac);
  for(auto y:E[x])
    if(y!=fa[x]&&y!=son[x])dfs2(y,y);
  low[x]=tim;return ;
}
inline LL get_lca(LL x,LL y){
  while(pf[x]!=pf[y]){
    if(dep[pf[x]]<dep[pf[y]])swap(x,y);
    x=fa[pf[x]];
  }
  if(dep[x]<dep[y])swap(x,y);
  return y;
}

vector<LL>vc[N];vector<LL>vp[N];bool vis[N],tag[N];
//vis[x] : 点 x 是否被删除掉了
//tag[x] : 颜色 x 是否被删除掉了
void down(LL x){
  tag[a[x]]=1;vis[x]=1;
  for(auto y:E[x])
    if(y!=fa[x]&&!vis[y])down(y);
  return ;
}
LL ans;
void solve(LL x){
  for(auto y:E[x])
    if(y!=fa[x])solve(y);
  for(auto c:vp[x])
    if(!tag[c]){down(x);ans++;}//可以用链表或并查集维护 dfs 序加速该过程
  return ;
}
int main(){
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  LL TC=read();
  while(TC--){
    n=read();for(LL t=1;t<=n;t++){a[t]=read();vc[a[t]].pb(t);}
    for(LL t=1;t<n;t++){LL u=read(),v=read();E[u].pb(v);E[v].pb(u);}
    dfs(1);dfs2(1,1);
    for(LL t=1;t<=n;t++){
      if(!SZ(vc[t]))continue;
      LL mn=n+1,mx=0;
      for(auto x:vc[t]){dmin(mn,dfn[x]);dmax(mx,dfn[x]);}
      mn=seq[mn];mx=seq[mx];vp[get_lca(mn,mx)].pb(t);
    }
    solve(1);writeln(ans);

    ans=tim=0;for(LL t=1;t<=n;t++){E[t].clear();vc[t].clear();vp[t].clear();vis[t]=tag[t]=0;}
  }
  return 0;
}
