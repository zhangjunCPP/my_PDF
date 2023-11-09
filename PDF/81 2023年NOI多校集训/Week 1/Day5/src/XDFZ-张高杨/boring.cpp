/*
T4 boring
���⣬��Խ��Խ���Ծ�
������Ҫ���Ľ���ֻ�ǿ����������lcm����
˼��lcm�Ƿ��������ɼ��ԣ�
���������lcm��lcm���Ǻ������Ĵ������lcm��
��
�ȵ�
lcm�ǲ��ǲ���ȡģ...
��ȷʵ����΢�������ܲ���ƭ��Subtask3
�ҿ�2������FZ���������Ӧ�û��Ǻ��л���
��Ȼ���������gcd��lcm�ĳ�������Ͱѻ��������QAQ
����230pts��ʵҲ������ˣ�����T1�±�...
���ԣ�
��������Ҳ���У���
lcm���ܹ�ȡģ��ȡģ��WA
ֻ�ܹ��洢�����������������
��Ȼ���Ƕ�ÿ��������Ҫ��Ψһ�ֽⶨ��Ȼ���ٶ�����������
���鷳������ȷʵ�ܵõ�30pts�ǰ�
�𣡶�ÿһ���������߶�����
������Ҫȡ��ÿһ������ָ�������ֵ����ô�������ͺý���ö�
������֪������ln����ģ��Ҳ�֪����ʲô��˼�����Ǵ��10%��
��������������p����ôʱ�临�Ӷ�O(kp log n)
��֮����n^2�Ŀ���������ȥ�����ǿռ�ܲ��ҵ�ը����
��ѽ��д���������𣬸���ô�����
���Ǳ�����ֻʣ10pts��QAQ
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
