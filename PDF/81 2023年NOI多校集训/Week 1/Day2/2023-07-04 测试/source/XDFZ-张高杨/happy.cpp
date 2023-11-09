/*
T1 游乐
看上去就很像DP啊
我们发现一开始应该设全部都是单次票
然后部分时限票可以放进去来缩减预算
所以按序从T1到Tn
我们通过枚举所有购票情况进行转移
显然二分log即可找到时限票的上一个
这样做，时间复杂度(NKlogN)
算一下发现超了^_^
不过这样能够稳拿80pts，也是一个很不错的算法了
先看看别的题，再决定本题是否冲击一下100pts吧
显然NK稳过
咱们考虑削log
预处理能不能做到？
双指针大哥起手了！！
放K个双指针，这样稳定到N
总的时间复杂度降低为NK，完美通过此题 
*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const ll maxn=100010,maxk=510;
ll T[maxn],num[maxk],cost[maxk];
ll ptr[maxk];
ll sum[maxn];
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	ll n,K,one;
	scanf("%lld%lld",&n,&K);
	for(ll i=1;i<=n;i++)scanf("%lld",T+i);
	T[0]=-1e9;
	for(ll i=1;i<=K;i++)scanf("%lld%lld",num+i,cost+i);
	scanf("%lld",&one);
	for(ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+one;
		for(ll j=1;j<=K;j++)
		{
			while(T[i]-T[ptr[j]]>=num[j])ptr[j]++;
			sum[i]=min(sum[i],sum[ptr[j]-1]+cost[j]);
		}
		printf("%lld\n",sum[i]-sum[i-1]);
	}
	return 0;
}
