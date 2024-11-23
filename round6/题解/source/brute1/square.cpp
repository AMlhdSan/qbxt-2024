#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=100010;
const int mo=1000000007;

int n,m,k,a[maxn],v[10];

int get_nxt(int x)
{
	int y=0;
	while (x)
		y+=v[x%10],x/=10;
	return y;
}

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<10;i++)
	{
		v[i]=1;
		for (int j=1;j<=k;j++)
			v[i]*=i;
	}
	for (int i=1;i<=m;i++)
	{
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if (opt==1)
			for (int i=l;i<=r;i++)
				a[i]=get_nxt(a[i]);
		else
		{
			int ans=0;
			for (int i=l;i<=r;i++)
				ans=(ans+a[i])%mo;
			printf("%d\n",ans);
		}
	}

	return 0;
}
