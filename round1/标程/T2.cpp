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

const LL N = 500000+95 ;
LL n,m,T,a[N],b[N];

namespace seg{
  struct node{LL l,r,t,d;}s[N<<2];
  inline void up(LL &p){
    if(!s[p].l&&!s[p].r){p=0;return ;}
    s[p].d=s[s[p].l].d+s[s[p].r].d;return ;
  }
  inline void change(LL &p,LL x,LL l,LL r,LL q){
    if(!p){p=q;s[p].l=s[p].r=s[p].t=s[p].d=0;}
    s[p].d+=(r-l+1)*x;s[p].t+=x;return ;
  }
  inline void down(LL p,LL l,LL r,LL q){
    assert(p);if(!s[p].t)return ;
    LL mid=(l+r)>>1;
    change(s[p].l,s[p].t,l,mid,(q<<1));
    change(s[p].r,s[p].t,mid+1,r,((q<<1)|1));
    s[p].t=0;return ;
  }
  void update(LL &p,LL x,LL y,LL w,LL l=1,LL r=n,LL q=1){
    if(y<l || r<x || x>y)return ;
    if(!p){p=q;s[p].l=s[p].r=s[p].d=s[p].t=0;}
    if(x<=l&&r<=y){change(p,w,l,r,q);return ;}
    if(s[p].t)down(p,l,r,q);
    LL mid=(l+r)>>1;
    if(x<=mid)update(s[p].l,x,y,w,l,mid,(q<<1));
    if(mid<y)update(s[p].r,x,y,w,mid+1,r,((q<<1)|1));
    up(p);return ;
  }
  LL query(LL &p,LL x,LL y,LL l=1,LL r=n,LL q=1){
    if(y<l || r<x || x>y || !p)return 0;
    if(x<=l&&r<=y){LL k=s[p].d;p=0;return k;}
    if(s[p].t)down(p,l,r,q);
    LL mid=(l+r)>>1,res=0;
    if(x<=mid)res+=query(s[p].l,x,y,l,mid,(q<<1));
    if(mid<y)res+=query(s[p].r,x,y,mid+1,r,((q<<1)|1));
    up(p);return res;
  }
}
struct oper{LL opt,l,r,x;}q[N];

int main(){
  freopen("b.in","r",stdin);freopen("b.out","w",stdout);
  n=read();m=read();T=read();
  for(LL t=1;t<=n;t++)a[t]=read();
  for(LL t=1;t<=T;t++){LL opt=read(),l=read(),r=read(),x=read();q[t]=(oper){opt,l,r,x};}

  LL rt=0;
  for(LL t=T;t>=1;t--){
    LL opt=q[t].opt,l=q[t].l,r=q[t].r,x=q[t].x;
    if(opt==1){LL SUM=seg::query(rt,l,r);b[x]+=SUM;}
    else {seg::update(rt,l,r,x);}
  }
  for(LL t=1;t<=n;t++){b[a[t]]+=seg::query(rt,t,t);}
  for(LL t=1;t<=m;t++)writecs(b[t]);
  puts("");return 0;
}
/*
my test data:
input:
2 2 3
2 2 
2 1 2 1
1 1 2 1
2 1 1 1
output:
1 2
*/
