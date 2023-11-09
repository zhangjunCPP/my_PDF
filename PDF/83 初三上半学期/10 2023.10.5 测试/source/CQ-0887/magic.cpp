/*
B magic
������ʵҲû�кܻᣬ������ʵ��ϸ���룬�����������ʶԵ�
���������Ǳ��� $15$ ��ˮ����Ļ�Ծ�����Ȼ�󲻶����Ƹ����䣬��֤���ȫ���ȶ�����
��Ϊˮ����ֻ��͸����� $7$ ���йأ��������ٴ����ƣ�����ߵ�ˮ����һ���������޹��ˣ������ȶ�������Ȼ�Ǻõ�
��ô����ÿ�ξ�ö�ٲ�����ת�ƣ�ʱ�临�Ӷ� $\mathcal{O}(15n2^{15})$
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1010,S=140000;
ll dp[2][S];
int l[N],r[N],c[N];
int ANS[S][20][20];
int B;
inline void Init_Val()
{
	for(int s=0;s<(1<<B);s++)
	{
		for(int i=0;i<B;i++)
		{
			for(int j=i;j<B;j++)
			{
				int sit=s,st=0,p=st+j;
				while(st<=j)
				{
					if(!(sit&1))ANS[s][i][j]+=(i<=st);
					sit>>=1;
					st++;
				}
			}
		}
	}
	return;
}
inline ll Val(int j,int st,int sit){return c[st+j]*ANS[sit][max(l[st+j]-st,0)][min(r[st+j]-st,B-1)]+c[st+j]*max(0,r[st+j]-st-B+1);}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",l+i,r+i,c+i);
	B=min(17,n);
	Init_Val();
	for(int i=B;i<=n;i++)
	{
		memset(dp[i&1],0,sizeof dp[i&1]);
		for(int s=0;s<(1<<B);s++)
		{
			dp[i&1][s]=dp[(i&1)^1][(s<<1)%(1<<B)+1];
			for(int j=0;j<B;j++)if((s>>j)&1)dp[i&1][s]=max(dp[i&1][s],dp[i&1][s-(1<<j)]+Val(j,i-B+1,s));
		}
	}
	printf("%lld",dp[n&1][(1<<B)-1]);
	return 0;
}
