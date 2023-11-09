#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int tim[N];
struct TmT{
	int c,t;
};
TmT tmt[505];
long long dp[N];
bool cmp(TmT a,TmT b)
{
	return a.t>b.t;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&tim[i]);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&tmt[i].t,&tmt[i].c);
	}
	int one;
	cin>>one;
	sort(tmt+1,tmt+k+1,cmp);
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1]+one;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(tim[j]-tmt[i].t<=0)
			{
				dp[j]=min(dp[j],dp[0]+tmt[i].c);
			}
			else
			{
				int w=lower_bound(tim+1,tim+n+1,tim[j]-tmt[i].t+1)-tim;
			    dp[j]=min(dp[j],dp[w-1]+tmt[i].c);
			}
			dp[j]=min(dp[j],dp[j-1]+one);
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d\n",dp[i]-dp[i-1]);
	}
}
