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
LL n,a[N],b[N];vector<LL>vc;

inline LL max(LL x,LL y){return ((x>y)?(x):(y));}

/*namespace seg{
  struct node{LL l,r,d;}s[(N<<1)<<2];LL tot;
  inline void up(LL p){s[p].d=max(s[p*2].d,s[p*2+1].d);}
  void build(LL p,LL l,LL r){
    s[p].l=l;s[p].r=r;s[p].d=0;if(l==r)return ;
    LL mid=(l+r)>>1;
    build(p*2,l,mid);build(p*2+1,mid+1,r);
    return ;
  }
  void update(LL p,LL x,LL y){
    if(s[p].l==s[p].r){dmax(s[p].d,y);return ;}
    LL mid=(s[p].l+s[p].r)>>1;
    if(x<=mid)update(p*2,x,y);
    else update(p*2+1,x,y);
    up(p);return ;
  }
  LL query(LL p,LL x){//[l,x]
    if(x<s[p].l || !p)return 0;
    if(s[p].r<=x)return s[p].d;
    LL mid=(s[p].l+s[p].r)>>1;
    if(x<=mid)return query(p*2,x);
    return max(s[p*2].d,query(p*2+1,x));
  }
}*/
#define lowbit(x) (x&(-x))
namespace BIT{
  LL c[(N<<1)];
  inline void make(LL x,LL y){x++;for(;x<=SZ(vc);x+=lowbit(x))dmax(c[x],y);}
  inline LL ask(LL x){x++;LL ans=0;for(;x;x-=lowbit(x))dmax(ans,c[x]);return ans;}
}
LL find(vector<LL>&vc,LL x){return (lower_bound(all(vc),x)-vc.begin());}

LL f[N],g[N];

int main(){
  freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  n=read();
  for(LL t=1;t<=n;t++){a[t]=read();vc.pb(a[t]);}
  for(LL t=1;t<=n;t++){b[t]=read();vc.pb(b[t]);}
  sort(all(vc));vc.erase(unique(all(vc)),vc.end());
  //  seg::build(1,0,SZ(vc)-1);

  LL ans=0;
  for(LL t=1;t<=n;t++){
    LL A=find(vc,a[t]),B=find(vc,b[t]);
    //    f[t]=seg::query(1,A-1)+1;g[t]=seg::query(1,B-1)+1;
    f[t]=BIT::ask(A-1)+1;g[t]=BIT::ask(B-1)+1;
    //    seg::update(1,A,f[t]);seg::update(1,B,g[t]);
    BIT::make(A,f[t]);BIT::make(B,g[t]);
    dmax(ans,f[t]);dmax(ans,g[t]);
  }
  writeln(ans);
  return 0;
}
