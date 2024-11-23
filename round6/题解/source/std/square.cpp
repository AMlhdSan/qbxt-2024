#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inc(a,b) {a+=b;if (a>=mo) a-=mo;}

const int maxv=100010;
const int maxn=100010;
const int maxl=14;
const int mo=1000000007;

int n,m,k,v[10],vis[maxv],mark[maxv],l;

bool circ[maxv];
int nxt[maxv][maxl];
int tmp[maxl];

int gcd(int a,int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}

int get_nxt(int x)
{
	int y=0;
	while (x)
		y+=v[x%10],x/=10;
	return y;
}

struct node
{
	int nxt_sum[maxl];
	int not_in_circ;
	int sum;
	int delta;
	node()
	{
		memset(nxt_sum,0,sizeof(nxt_sum));
		not_in_circ=0;
		sum=0;
		delta=0;
	}
	void init(int v)
	{
		delta=0;
		if (v<maxv && circ[v])
		{
			for (int i=0;i<l;i++)
				nxt_sum[i]=nxt[v][i];
			sum=0;
			not_in_circ=0;
		}
		else
		{
			not_in_circ=1;
			sum=v;
		}
	}
	void color(int x)
	{
		delta+=x;
		x%=l;
		delta%=l;
		for (int i=0;i<l;i++)
			tmp[i]=nxt_sum[(i+x)%l];
		for (int i=0;i<l;i++)
			nxt_sum[i]=tmp[i];
	}
}z[maxn<<2|1];

node operator+(const node &l,const node &r)
{
	node res;
	for (int i=0;i<::l;i++)
		inc(res.nxt_sum[i],l.nxt_sum[i]+r.nxt_sum[i]);
	inc(res.sum,l.sum+r.sum);
	res.not_in_circ = l.not_in_circ+r.not_in_circ;

	return res;
}

void push_col(int rt)
{
	if (z[rt].delta)
	{
		z[rt<<1].color(z[rt].delta);
		z[rt<<1|1].color(z[rt].delta);
		z[rt].delta=0;
	}
}

void build(int l,int r,int rt)
{
	if (l==r)
	{
		int v;
		scanf("%d",&v);
		z[rt].init(v);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	z[rt]=z[rt<<1]+z[rt<<1|1];
}

void modify(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr)
	{
		if (z[rt].not_in_circ == 0)
		{
			z[rt].color(1);
			return;
		}
		if (l==r)
		{
			z[rt].init(get_nxt(z[rt].sum));
			return;	
		}
	}
	push_col(rt);
	int m=(l+r)>>1;
	if (nowl<=m) modify(lson,nowl,nowr);
	if (m<nowr) modify(rson,nowl,nowr);
	z[rt]=z[rt<<1]+z[rt<<1|1];
}

node query(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return z[rt];
	push_col(rt);
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query(lson,nowl,nowr)+query(rson,nowl,nowr);
		else return query(lson,nowl,nowr);
	}
	else return query(rson,nowl,nowr);
}

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<=9;i++)
	{
		v[i]=1;
		for (int j=1;j<=k;j++)
			v[i]=v[i]*i;
	}
	int r=1;
	for (int i=1;i<=k;i++)
		r=r*9;
	r=r*9;
	//printf("%d\n",r);
	l=1;
	for (int i=1;i<=r;i++)
		if (!vis[i])
		{
			int size=1;
			vis[i]=1;
			mark[i]=i;
			int x=i;
			while (true)
			{
				x=get_nxt(x);
				if (vis[x]) break;
				vis[x]=++size;
				mark[x]=i;
			}
			if (mark[x]==i)
			{
				int z=size-vis[x]+1;
				//printf("%d %d\n",x,z);
				l=l/gcd(l,z)*z;
				for (int i=1;i<=z;i++)
				{
					//printf("%d ",x);
					circ[x]=true;
					x=get_nxt(x);
				}
				//printf("\n");
			}
		}
	for (int i=1;i<=r;i++)
		if (circ[i])
		{
			int x=i;
			for (int j=0;j<l;j++)
			{
				nxt[i][j]=x;
				int y=0;
				while (x)
					y+=v[x%10],x/=10;
				x=y;
			}
		}
	build(root);
	for (int i=1;i<=m;i++)
	{
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if (opt==1) modify(root,l,r);
		else 
		{
			node res = query(root,l,r);
			printf("%d\n",(res.nxt_sum[0]+res.sum)%mo);
		}
	}
	fflush(stdout);

	return 0;
}
