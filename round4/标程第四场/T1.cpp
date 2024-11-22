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

vector<LL>vc[10];

int main(){
  freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  for(LL b=1;b<=2154ll;b++)vc[(b*b*b)%10].pb(b);
  
  LL TC=read();
  while(TC--){
    LL L=read(),R=read(),ans=0;
    for(LL a=L;a<=min(R,2154ll);a++){
      if((a*a*a)>(10*R+3))break;
      LL d=((3-(a*a*a))%10+10)%10,posL=0,posR=0;
      auto checkL=[&](LL b){return ((L<=b)?(1):(0));};
      auto checkR=[&](LL b){return (((a*a*a)+(b*b*b)<=(10*R+3))?(1):(0));};
      {
	LL l=0,r=SZ(vc[d])-1;posL=SZ(vc[d]);
	while(l<=r){
	  LL mid=(l+r)>>1;
	  if(checkL(vc[d][mid])){r=mid-1;posL=mid;}
	  else {l=mid+1;}
	}
      }
      {
	LL l=0,r=SZ(vc[d])-1;posR=-1;
	while(l<=r){
	  LL mid=(l+r)>>1;
	  if(checkR(vc[d][mid])){l=mid+1;posR=mid;}
	  else {r=mid-1;}
	}
      }
      if(posL<=posR)ans+=(posR-posL+1);
    }
    writeln(ans);
  }
  return 0;
}
