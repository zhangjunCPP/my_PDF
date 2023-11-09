#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=510;
int T[N];
int num[K],cost[K];
int one;
ll sum[N];
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.bf","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",T+i);
	for(int i=1;i<=k;i++)scanf("%d%d",num+i,cost+i);
	scanf("%d",&one);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+one;
		for(int j=1;j<i;j++)for(int l=1;l<=k;l++)if(T[i]-T[j]<num[l]-1)sum[i]=min(sum[i],sum[j-1]+cost[l]);
		printf("%lld\n",sum[i]-sum[i-1]);
	}
	return 0;
}
