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
LL n;vector<LL>E[N];LL m;

LL fa[N],dfn[N],low[N],tim,seq[N],sz[N];
void dfs(LL x){
  dfn[x]=++tim;seq[tim]=x;sz[x]=1;
  for(auto y:E[x])
    if(y!=fa[x]){fa[y]=x;dfs(y);sz[x]+=sz[y];}
  low[x]=tim;return ;
}
LL col[N],dat[N];set<LL>Id;

namespace seg{
  struct node{LL l,r,d;}s[N<<2];
  void build(LL p,LL l,LL r){
    s[p].l=l;s[p].r=r;s[p].d=0;if(l==r)return ;
    LL mid=(l+r)>>1;
    build(p*2,l,mid);build(p*2+1,mid+1,r);
    return ;
  }
  inline void down(LL p){if(s[p].d){s[p*2].d=s[p].d;s[p*2+1].d=s[p].d;s[p].d=0;}return ;}
  void update(LL p,LL l,LL r,LL x){
    if(r<s[p].l || s[p].r<l || l>r)return ;
    if(l<=s[p].l&&s[p].r<=r){s[p].d=x;return ;}
    if(s[p].d)down(p);
    LL mid=(s[p].l+s[p].r)>>1;
    if(l<=mid)update(p*2,l,r,x);
    if(mid<r)update(p*2+1,l,r,x);
    return ;
  }
  LL ask(LL p,LL x){
    if(s[p].d)return s[p].d;
    LL mid=(s[p].l+s[p].r)>>1;
    if(x<=mid)return ask(p*2,x);
    else return ask(p*2+1,x);
  }
}
inline LL GET(LL x){return seg::ask(1,dfn[x]);}//找到点 x 对应的标志点

int main(){
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  n=read();for(LL t=1;t<n;t++){LL u=read(),v=read();E[u].pb(v);E[v].pb(u);}
  n++;E[n].pb(1);E[1].pb(n);dfs(n);

  assert((dfn[n]==1)&&(dfn[1]==2));
  Id.insert(0);Id.insert(n+1);seg::build(1,1,n);
  Id.insert(1);col[n]=(LL)(1e6)+1;dat[n]=1;seg::update(1,1,1,n);//加入点 n (占位符,避免分类讨论)
  Id.insert(2);col[1]=1;dat[1]=(n-1);seg::update(1,2,n,1);//加入点 1
  m=read();
  for(LL t=1;t<=m;t++){
    LL opt=read();
    if(opt==1){
      LL x=read(),_c_=read(),SUM=0;
      while(true){
	auto it=Id.lower_bound(dfn[x]+1);if(low[x]<(*it))break;
	LL z=seq[(*it)];SUM+=dat[z];col[z]=dat[z]=0;Id.erase(it);
      }
      LL X=GET(x);
      if(x==X){//原来点 x 是标志点
	LL Y=GET(fa[x]);
	if(_c_!=col[Y]){//现在点 x 还是标志点
	  col[x]=_c_;dat[x]+=SUM;
	  seg::update(1,dfn[x],low[x],x);
	}
	else {//现在点 x 不再是标志点
	  dat[Y]+=sz[x];Id.erase(Id.find(dfn[x]));col[x]=dat[x]=0;
	  seg::update(1,dfn[x],low[x],Y);
	}
      }
      else {//原来点 x 不是标志点
	if(_c_==col[X]){//现在点 x 仍然不是标志点
	  dat[X]+=SUM;
	  seg::update(1,dfn[x],low[x],X);
	}
	else {//现在开始点 x 变成了标志点
	  dat[X]-=(sz[x]-SUM);
	  dat[x]=sz[x];col[x]=_c_;Id.insert(dfn[x]);
	  seg::update(1,dfn[x],low[x],x);
	}
      }
    }
    else {
      LL x=read();LL X=GET(x);
      writeln(dat[X]);
    }
  }
  return 0;
}
