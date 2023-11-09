/*
T4 boring
你这，我越看越不对劲
我们需要做的仅仅只是快速求解区间lcm而已
思考lcm是否存在区间可加性？
两个区间的lcm的lcm就是合起来的大区间的lcm啊
额
等等
lcm是不是不能取模...
那确实，稍微处理处理看能不能骗到Subtask3
我看2个亿在FZ的评测机上应该还是很有机会
当然，还有求解gcd和lcm的常数，这就把机会夺走了QAQ
看着230pts其实也不算低了，但是T1怕爆...
不对？
暴力好像也不行？？
lcm不能够取模，取模就WA
只能够存储——质因数出现情况
显然我们对每个数都需要做唯一分解定理然后再对质因数处理
好麻烦，但是确实能得到30pts是吧
拆！对每一个质数建线段树！
我们需要取得每一个区间指数的最大值，那么这个问题就好解决得多
众所周知质数是ln级别的，我不知道是什么意思，但是大概10%？
设质数的数量是p，那么时间复杂度O(kp log n)
总之至少n^2的可以允许卡过去，但是空间很不幸地炸掉了
哎呀就写暴力不行吗，搞这么多废物
但是暴力就只剩10pts了QAQ
*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5000;
int prime[N],tot;
bool vis[N];
inline void S(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(vis[i])continue;
		prime[++tot]=i;
		for(int j=2;i*j<=n;j++)vis[i*j]=true;
	}
	return;
}
int pt[N][N];
inline void CHAI(int p,int x)
{
	for(int i=1;i<=tot&&prime[i]<=x;i++)while(x%prime[i]==0)pt[p][i]++,x/=prime[i];
	return;
}
int a[N];
bool tis[N];
int ans[N];
inline void add(int p)
{
	for(int i=1;i<=tot;i++)ans[i]=max(ans[i],pt[p][i]);
	return;
}
inline ll qpow(ll a,ll b)
{
	if(!b)return 1;
	if(!a)return 0;
	ll ret=1;
	while(b)
	{
		if(b&1)(ret*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	S(2000);
	for(int i=1;i<=n;i++)scanf("%d",a+i),CHAI(i,a[i]);
	while(q--)
	{
		int k;
		scanf("%d",&k);
		memset(tis,0,sizeof tis);
		memset(ans,0,sizeof ans);
		while(k--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=l;i<=r;i++)if(!tis[i])add(i),tis[i]=true;
		}
		ll Ans=1;
		for(int i=1;i<=tot;i++)(Ans*=qpow(prime[i],ans[i]))%=mod;
		printf("%lld\n",Ans);
	}
	return 0;
}
