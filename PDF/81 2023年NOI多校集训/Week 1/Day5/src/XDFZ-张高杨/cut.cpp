/*
T2 cut
����ת�Ƶ�ʱ����Ҫ���ر���ת�ƣ�������ʱ�临�Ӷ���n^2�ģ����ɽ���
˼����û�и���ķ�����
��Ȼ�����Ƿ�����û���µ����ּ����ʱ�������Щ״̬��������
Ҳ����˵�����Ǽ�����ĳ����֮��֮���κ��������״̬���������
���������Ǽ�¼ÿһ�������һ�γ��ֵ�λ�ö������⼸��λ�ý���״̬ת��
��������O(na)��ʱ�临�Ӷ� 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N];
int last[25],dp[N],pre[N];
queue<int> to_vis;//��һ�����б�֤˳�����
bool M[25];//mex�����������
int ord[N],tot;
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dp[1]=a[1]==0,last[a[1]]=1,pre[1]=0,to_vis.push(a[1]);
	for(int i=2;i<=n;i++)
	{
//		printf("dp %d:\n",i);
		memset(M,0,sizeof M);
		int j=to_vis.size(),mex=0;
		to_vis.push(a[i]);
		last[a[i]]=i;
		M[a[i]]=true;
		while(M[mex])mex++;
//		printf("update num %d last %d mex %d\n",a[i],last[a[i]],mex);
		dp[i]=dp[i-1]+mex;
		pre[i]=i-1;
		while(j--)
		{
			int u=to_vis.front();to_vis.pop();
			if(u==a[i])continue;
			M[u]=true;
			while(M[mex])mex++;
//			printf("update num %d last %d mex %d\n",u,last[u],mex);
			if(dp[last[u]-1]+mex>dp[i])
			{
				dp[i]=dp[last[u]-1]+mex;
//				printf("update dp %d <- dp %d => %d\n",i,last[u]-1,dp[i]);
				pre[i]=last[u]-1;
			}
			to_vis.push(u);
		}
	}
	for(int i=n;i;)
	{
		ord[++tot]=pre[i]+1;
		i=pre[i];
	}
	sort(ord+1,ord+tot+1);
	printf("%d %d\n",dp[n],tot);
	for(int i=1;i<=tot;i++)printf("%d ",ord[i]);
	return 0;
}
