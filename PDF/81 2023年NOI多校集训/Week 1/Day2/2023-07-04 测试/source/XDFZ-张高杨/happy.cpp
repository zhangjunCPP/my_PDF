/*
T1 ����
����ȥ�ͺ���DP��
���Ƿ���һ��ʼӦ����ȫ�����ǵ���Ʊ
Ȼ�󲿷�ʱ��Ʊ���ԷŽ�ȥ������Ԥ��
���԰����T1��Tn
����ͨ��ö�����й�Ʊ�������ת��
��Ȼ����log�����ҵ�ʱ��Ʊ����һ��
��������ʱ�临�Ӷ�(NKlogN)
��һ�·��ֳ���^_^
���������ܹ�����80pts��Ҳ��һ���ܲ�����㷨��
�ȿ�������⣬�پ��������Ƿ���һ��100pts��
��ȻNK�ȹ�
���ǿ�����log
Ԥ�����ܲ���������
˫ָ���������ˣ���
��K��˫ָ�룬�����ȶ���N
�ܵ�ʱ�临�ӶȽ���ΪNK������ͨ������ 
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
