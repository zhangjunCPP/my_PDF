/*
T2 cut
我们转移的时候需要往回遍历转移，这样的时间复杂度是n^2的，不可接受
思考有没有更快的方法？
当然，我们发现在没有新的数字加入的时候遍历这些状态毫无意义
也就是说在我们加入了某个数之后，之后任何这个数的状态都无需遍历
这启发我们记录每一个数最后一次出现的位置而仅从这几个位置进行状态转移
不难做到O(na)的时间复杂度 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N];
int last[25],dp[N],pre[N];
queue<int> to_vis;//加一个队列保证顺序访问
bool M[25];//mex辅助标记数组
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
