//先预处理，预处理什么？
//lcm用乘起来再除以gcd？
//区间是否有重叠？重叠好像没啥用？只能每次query？太假了线段树维护区间内的乘积和和gcd？
//然后查询的时候就用乘积和来除以gcd
//草，忘记线段树怎么写了
#include <bits/stdc++.h>
using namespace std;
int n,q;
const int maxn=1e5+5;
int a[maxn];
int ans[maxn];
const int mod=998244353;
//struct segmenttree{
//	int l,r;
//	long long sum;
//}t[maxn*4];
//void build(int p,int l,int r)
//{
//	if(l==r)
//	{
//		t[p].sum=a[l];
//		return ;
//	}
//	int mid=(l+(r-l)/2)>>1;
//	build(p*2,l,mid);
//	build(p*2+1,mid+1,r);
//	t[p].sum=t[p*2].sum*t[p*2+1].sum;
//}
//long long query(int l,int r)
//{
//	
//}
int main()
{
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=2*k;j++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
		}
	}
	return 0;
}
