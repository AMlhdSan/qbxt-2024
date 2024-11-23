#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int mo=100000007;

int n,a[maxn],b[maxn],c[maxn];

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=i;
	int ans=0;
	do
	{
		for (int i=1;i<=n;i++)
			c[i]=a[b[i]];
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (c[i]>c[j]) ans=(ans+1ll*c[i]*c[j])%mo;
	}while(next_permutation(b+1,b+n+1));
	printf("%d\n",ans);

	return 0;
}
