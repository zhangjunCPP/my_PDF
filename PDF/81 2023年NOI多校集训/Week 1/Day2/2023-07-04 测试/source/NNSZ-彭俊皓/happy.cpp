#include<iostream>
using namespace std;
const int MAXN=100005,MAXM=505;
int a,b,c;
int lct[MAXN],que[MAXN];
int w[MAXM],cost[MAXM];
long long dp[MAXN];
inline int read(){
	char x=getchar();int t=0;
	while(!isdigit(x))x=getchar();
	while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
	return t;
}
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	a=read();b=read();
	for(register int i=1;i<=a;++i)lct[i]=read();
	for(register int i=1;i<=b;++i)w[i]=read(),cost[i]=read();
	c=read();
	for(register int i=1;i<=a;++i)
	{
		dp[i]=dp[i-1]+c;
		for(register int k=1;k<=b;++k)
		{
			int l=0,r=i-1,mid;
			while(r-l>1)
			{
				mid=(l+r)>>1;
				if(lct[i]-lct[mid]>=w[k])l=mid;
				else r=mid;
			}
//			printf("(%d)",dp[l]);
			dp[i]=min(dp[i],dp[l]+cost[k]);
		}
//		printf("[%d]\n",dp[i]);
	}
	for(register int i=1;i<=a;++i)printf("%lld\n",dp[i]-dp[i-1]);
	return 0;
}
