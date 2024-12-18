#include<bits/stdc++.h>
#define LL long long
#define SZ(x) ((LL)(x.size()))
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
void writeln(LL x){write(x);puts("");}
void writecs(LL x){write(x);putchar(' ');}

const LL N = 1000+95 , M = 1000000+95;
LL n,m,k,P,A[N],B[N],cA[M],cB[M];
int main(){
  freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  n=read();m=read();k=read();P=read();
  for(LL i=1;i<=n;i++)
    for(LL j=1;j<=m;j++){LL x=read();A[i]+=x;B[j]+=x;}
  {
    priority_queue<LL>p;
    for(LL i=1;i<=n;i++)p.push(A[i]);
    for(LL t=1;t<=k;t++){
      LL v=p.top();p.pop();
      cA[t]=cA[t-1]+v;p.push(v-m*P);
    }
  }
  {
    priority_queue<LL>p;
    for(LL i=1;i<=m;i++)p.push(B[i]);
    for(LL t=1;t<=k;t++){
      LL v=p.top();p.pop();
      cB[t]=cB[t-1]+v;p.push(v-n*P);
    }
  }
  LL ans=-(LL)(1e18);
  for(LL a=0;a<=k;a++){
    LL b=(k-a);
    ans=max(ans,cA[a]+cB[b]-a*b*P);
  }
  writeln(ans);
  return 0;
}
