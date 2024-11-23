#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int maxk=36+2;

int id[300],n,m,len[maxk];

int prime[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int r[maxn];

int mo[6]={0,223092870,58642669,600662303,33984931,8633};

char s[100];
char s1[100];

int a[maxn];
long long d[maxn];
bool able[maxn];

void readint(int &x)
{
	x=0;char c=' ';
	while (c<'0' || c>'9') 
		c=getchar();
	while (c>='0' && c<='9') 
		x=x*10+c-'0',c=getchar();
}

void readlong(long long &x)
{
	x=0;char c=' ';
	while (c<'0' || c>'9') 
		c=getchar();
	while (c>='0' && c<='9') 
		x=x*10+c-'0',c=getchar();
}

bool chk(int x,int l,int k)
{
	for (int i=l;i>=1;i--)
	{
		if (s[i]=='?' || (s[i]>='A'?s[i]-'A'+10:s[i]-'0')==x%k);
		else return false;
		x/=k;
	}
	return true;
}

int main()
{
	freopen("2024.in","r",stdin);
	freopen("2024.out","w",stdout);
	for (int i=0;i<10;i++)
		id[i+'0']=i;
	for (int i=10;i<maxk;i++)
		id[i-10+'A']=i;
	readint(n);
	readint(m);
	for (int i=1;i<=n;i++)
		readint(a[i]);
	for (int i=1;i<=n;i++)
		readlong(d[i]);
	for (int i=1;i<=m;i++)
	{
		int k,x;
		long long z;
		readint(k);
		scanf("%s",s+1);
		readint(x);
		readlong(z);
		int l=strlen(s+1);
		int cnt=0;
		for (int i=1;i<=n;i++)
			if (chk(a[i],l,k)) r[++cnt]=i;
		int ans=100;
		for (int j=1;j<=5 && ans==100;j++)
		{
			int v=1;
			for (int r=1;r<=cnt;r++)
			{
				v=1ll*v*(d[::r[r]]%mo[j])%mo[j];
			}
			for (int r=1;r<=25 && ans==100;r++)
				if (mo[j]%prime[r]==0)
				{
					int newv=((long long)v+z)%prime[r];
					if (newv==0) ans=min(ans,prime[r]);
				}
		}
		printf("%d\n",min(ans,x));
	}

	return 0;
}

