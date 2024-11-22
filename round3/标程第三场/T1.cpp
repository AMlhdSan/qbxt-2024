#include<bits/stdc++.h>
#define LL int
#define SZ(x) ((LL)(x.size()))
using namespace std;

#define ll long long

namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;

#define ui unsigned int

const int N = 1000000+95 ; const unsigned int inf = (ui)(2e9)+1 ;
int T;struct oper{int opt,type,a,b;}q[N];ll vl[N];LL ord[N],tr[N];

inline ui min(LL x,LL y){return ((x<y)?(x):(y));}
inline ui max(LL x,LL y){return ((x>y)?(x):(y));}

namespace zkw{
  const int SIZE = ((1<<20)<<1)+5 ;
  ui L,data[SIZE][2],datb[SIZE][2],dat[SIZE];
  inline void init(ui len){
    L=1;while(L<=len+1)L<<=1;
    for(ui i=1;i<(L<<1);i++){
      for(ui op=0;op<=1;op++)data[i][op]=datb[i][op]=inf;
      dat[i]=inf;
    }
    return ;
  }
  inline void ins(ui op,ui p,ui a,ui b){
    p+=L;data[p][op]=a;datb[p][op]=b;

    p>>=1;
    while(p&&(data[p][op]>a||datb[p][op]>b)){
    
      data[p][op]=min(data[(p<<1)][op],data[(p<<1)|1][op]);
      datb[p][op]=min(datb[(p<<1)][op],datb[(p<<1)|1][op]);
    
      dat[p]=min(dat[(p<<1)],dat[(p<<1)|1]);
      dat[p]=min(dat[p],data[(p<<1)][1]+data[(p<<1)|1][0]);
      dat[p]=min(dat[p],datb[(p<<1)][0]+datb[(p<<1)|1][1]);
      
      p>>=1;
    }
    if(p){
      
      dat[p]=min(dat[(p<<1)],dat[(p<<1)|1]);
      dat[p]=min(dat[p],data[(p<<1)][1]+data[(p<<1)|1][0]);
      dat[p]=min(dat[p],datb[(p<<1)][0]+datb[(p<<1)|1][1]);
      
      while(p>1){dat[(p>>1)]=min(dat[(p>>1)],dat[p]);p>>=1;}
    }
    return ;
  }
  inline void del(ui op,ui p,ui a,ui b){
    p+=L;data[p][op]=inf;datb[p][op]=inf;

    p>>=1;
    while(p){
    
      data[p][op]=min(data[(p<<1)][op],data[(p<<1)|1][op]);
      datb[p][op]=min(datb[(p<<1)][op],datb[(p<<1)|1][op]);
    
      dat[p]=min(dat[(p<<1)],dat[(p<<1)|1]);
      dat[p]=min(dat[p],data[(p<<1)][1]+data[(p<<1)|1][0]);
      dat[p]=min(dat[p],datb[(p<<1)][0]+datb[(p<<1)|1][1]);

      p>>=1;
    }
    return ;
  }
}
LL cnt[N],pre[N];
int main(){
  freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  qio>>T;
  for(LL t=1;t<=T;t++){
    LL opt=0,type=0,a=0,b=0;
    qio>>opt>>type>>a>>b;
    q[t]=(oper){opt,type,a,b};ord[t]=t;
    if(type==0){vl[t]=((((ll)(a-b))<<32ll)+a);}
    else {vl[t]=((((ll)-(a-b))<<32ll)+(-a));}
  }
  sort(ord+1,ord+T+1,[&](LL x,LL y){return vl[x]<vl[y];});
  for(LL t=1;t<=T;t++){
    if((t==1)||(vl[ord[t]]!=vl[ord[t-1]]))pre[t]=t;
    else pre[t]=pre[t-1];
    tr[ord[t]]=pre[t];cnt[t]=t;
  }
  
  zkw::init(T);
  for(LL t=1;t<=T;t++){
    LL opt=q[t].opt,type=q[t].type,a=q[t].a,b=q[t].b,ext=tr[t];
    if(opt==1){
      if(cnt[ext]==ext)zkw::ins(type,cnt[ext],a,b);
      cnt[ext]++;
    }
    else {
      cnt[ext]--;
      if(cnt[ext]==ext)zkw::del(type,cnt[ext],a,b);
    }
    ui ans=zkw::dat[1];
    if(ans==inf)qio<<"-1\n";
    else qio<<ans<<'\n';
  }
  return 0;
}
