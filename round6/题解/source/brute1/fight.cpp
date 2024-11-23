#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

//C(n,i)C(n,i+y) = C(n,i)C(n,n-i-y) = C(2n,n-y)

const int maxn=1000010;

int n,y,p,fac[maxn],ifac[maxn];

int ksm(int a,int b,int p)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%p;
		a=1ll*a*a%p;
		b>>=1;
	}
	return ans;
}

int C(int n,int m,int p)
{
	if (n<p && m<p) return 1ll*fac[n]*ifac[m]%p*ifac[n-m]%p;
	else return 1ll*C(n%p,m%p,p)*C(n/p,m/p,p)%p;
}

int C(int n,int m,int p,int pk)//C(n,m)%p^k
{
	if (p!=pk) return 0;
	//prework
	fac[0]=1;
	for (int i=1;i<p;i++)
		fac[i]=1ll*fac[i-1]*i%pk;
	for (int i=0;i<p;i++)
		ifac[i]=ksm(fac[i],p-2,p);

	//work
	return C(n,m,p);
}

int gcd(int a, int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}

void merge(int p1,int a1,int p2,int a2,int &p,int &a)
//x%p1=a1
//x%p2=a2
//合并为一个方程
//x%p=a
{
	p = p1 / gcd(p1,p2) * p2;
	if (p1<p2) swap(p1,p2),swap(a1,a2);
	a = a1;
	while (a % p2 != a2)//O(min(p1,p2))
		a += p1;
}

int C(int n,int m)
{
	int x=p;
	int p=1,a=0;
	for (int i=2;i<=x;i++)
		if (x%i==0)
		{
			int y=1;
			while (x%i==0)
				x/=i,y*=i;
			int z=C(n,m,i,y);
			merge(p,a,y,z,p,a);
		}
	return a;
}

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d%d%d",&n,&y,&p);
	printf("%d\n",C(2*n,n-y));
	
	return 0;
}
