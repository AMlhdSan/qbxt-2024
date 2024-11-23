#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int mo=100000007;

int n,a[maxn];

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int sum=0;
	int ans=0;
	for (int i=1;i<=n;)
	{
		int j=i;
		while (j<=n && a[j]==a[i])
			j++;
		ans=(ans+1ll*sum*(j-i)%mo*a[i])%mo;
		sum=(sum+1ll*a[i]*(j-i))%mo;
		i=j;
	}
	for (int i=3;i<=n;i++)
		ans=1ll*ans*i%mo;
	printf("%d\n",ans);

	return 0;
}
