#include<bits/stdc++.h>
#define LL int
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
LL n,TC,a[N],b[N],tmp[N];

inline LL mabs(LL x){return ((x<0)?(-x):(x));}

struct item{LL l,r;}vc[N];LL m,rep[N],jmp[N],dep[N];
inline void make(LL t,LL x){
  if(!rep[t])rep[t]=x;
  if(vc[x].r<vc[rep[t]].r)rep[t]=x;
  return ;
}

LL fa[N];
LL find(LL x){return (fa[x]==x?x:(fa[x]=find(fa[x])));}
inline LL merge(LL x,LL y){
  x=find(x);y=find(y);if(x==y)return 0;
  fa[x]=y;return 1;
}

#define PL pair<LL,LL>
#define mp make_pair
#define fir first
#define sec second
vector<PL>q[N];LL ans[N];

int main(){
  freopen("b.in","r",stdin);freopen("b.out","w",stdout);
  n=read();TC=read();for(LL t=1;t<=n;t++)a[t]=read();

  
  for(LL t=1;t<=n;t++){
    b[t]=tmp[a[t]];tmp[a[t]]=t;
    if(b[t]){vc[++m]=(item){b[t],t};make(b[t],m);}
  }
  for(LL t=n;t>=1;t--)if(rep[t+1])make(t,rep[t+1]);

  for(LL t=1;t<=m;t++)jmp[t]=rep[vc[t].r];
  for(LL t=m;t>=1;t--)dep[t]=dep[jmp[t]]+1;
  
  for(LL t=1;t<=TC;t++){
    LL l=read(),r=read();if(l>r)swap(l,r);
    q[r].pb(mp(t,l));ans[t]=((r-l)<<1);
  }

  for(LL t=0;t<=m;t++)fa[t]=t;
  for(LL t=1;t<=n;t++)
    for(auto u:q[t]){
      LL idx=u.fir,x=u.sec;x=rep[x];if(!x||t<vc[x].r)continue;
      LL X=x;x=find(x);while(jmp[x]&&vc[jmp[x]].r<=t){merge(x,jmp[x]);x=find(x);}
      ans[idx]-=(dep[X]-dep[x]+1);
    }
  for(LL t=1;t<=TC;t++)writeln(ans[t]);
  return 0;
}
