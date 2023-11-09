#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,k;
int t[MAXN],num[600],cost[600];
int one;
long long dp[MAXN];

int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t[i]);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&num[i],&cost[i]);
	}
	scanf("%d",&one);
	
	if(k==0)
	{
		for(int i=1;i<=n;++i)
		{
			printf("%d\n",one);
		}
		return 0;
	}
	
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1]+one;
		for(int j=1;j<=k;++j)
		{
			int y=t[i]-num[j];
			int xu=upper_bound(t+1,t+1+n,y)-t;
			dp[i]=min(dp[i],dp[xu-1]+cost[j]);
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		int result=dp[i]-dp[i-1];
		printf("%d\n",result);
	}
	
	return 0;
}
