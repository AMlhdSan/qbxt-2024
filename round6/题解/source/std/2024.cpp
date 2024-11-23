#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define ull unsigned long long
inline ll rd() {
    ll s=0,m=0;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-')m=1;ch=getchar();}
    while( isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return m?-s:s;
}
bool MBE;
namespace SOLVER {
const lll M1=614889782588491410,M2=3749562977351496827;
const int pri[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int n,m,K,L,a[200005],pp[37][65];char str[70];lll ans1,ans2,d[200005];
vector<int> g;ull hs,p3[200005];map<ull,lll> mp1,mp2;
int get(char ch) {return ch>='0'&&ch<='9'?ch-'0':ch-'A'+10;}
inline void dfs(int p,int s) {
    if(p>L) {if(s) g.emplace_back(s),hs+=p3[s];return;}
    if(str[p]=='?') {
        for(int i=0;i<K;i++) {
            if((i&&!pp[K][L-p])||s+i*pp[K][L-p]>n) break;
            dfs(p+1,s+i*pp[K][L-p]);
        }
    }
    else dfs(p+1,s);
}
void MAIN() {
    cin>>n>>m;p3[0]=1;for(int i=1;i<=n;i++) p3[i]=p3[i-1]*3;
    for(int i=2;i<=36;i++) for(int j=0,k=1;k<=i*n;j++,k*=i) pp[i][j]=k;
    for(int i=1;i<=n;i++) a[i]=rd();for(int i=1;i<=n;i++) d[a[i]]=rd();
    while(m--) {
        K=rd();scanf("%s",str+1);L=strlen(str+1);int x=rd(),s=0,fl=0,flag=0;lll z=rd();
        for(int i=1;i<=L;i++) if(str[i]!='?') {
            if((str[i]!='0'&&!pp[K][L-i])||s+get(str[i])*pp[K][L-i]>n) {fl=1;break;}
            s+=get(str[i])*pp[K][L-i];
        }
        if(fl) {
            for(int i=1;i<=25&&pri[i]<=x;i++) if((z+1)%pri[i]==0) {printf("%d\n",pri[i]);flag=1;break;}
            if(!flag) printf("%d\n",x);continue;
        }
        ans1=ans2=1;g.clear(),hs=0;dfs(1,s);
        if(!mp1.count(hs)) {for(int s:g) ans1=ans1*d[s]%M1;mp1[hs]=ans1;}
        ans1=(mp1[hs]+z)%M1;
        for(int i=1;i<=15&&pri[i]<=x;i++) if(ans1%pri[i]==0) {printf("%d\n",pri[i]);flag=1;break;}
        if(flag) continue;
        if(!mp2.count(hs)) {for(int s:g) ans2=ans2*d[s]%M2;mp2[hs]=ans2;}
        ans2=(mp2[hs]+z)%M2;
        for(int i=16;i<=25&&pri[i]<=x;i++) if(ans2%pri[i]==0) {printf("%d\n",pri[i]);flag=1;break;}
        if(flag) continue;
        printf("%d\n",x);
    }
}
}
bool MED;
signed main() {
    freopen("2024.in","r",stdin);freopen("2024.out","w",stdout);
    for(int tt=1;tt;tt--) SOLVER::MAIN();
    cerr<<(&MBE-&MED)/1024<<" KB, "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
