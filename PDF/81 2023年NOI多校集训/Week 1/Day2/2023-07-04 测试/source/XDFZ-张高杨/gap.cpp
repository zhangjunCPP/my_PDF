/*
T3 区间
哇超，DP哥吗？
这种类型的题看上去和DP八竿子打不着，反而最有可能是DP
注意到其实ai是否为1似乎是一个特殊点
注意到很特别的ai的性质
肯定是一段一段相同的数字
这样我们将其分成几段
对应回原排列
排列之间肯定互不冲突
我们运用值域思想
相邻的两段不能放在一起
可以调换顺序满足这一要求，但是1很特殊，它不可以
于是dddd了
这里的问题是，我不能有多个相同排名的段出现
于是每次都不能够选择相邻的一段（或者就只能反着放）
现在状态数实在太多了，我们很需要合并同类项！
不知道啊，还有没有印象——卡农
这不就对了？其实剩下的除了不能选的都是一样的！
（一样哥持续发光发热）
当前这一段的要求是不能和上段连续
上一段上升时这一段必须下降
此时如果ai=1那么不可能下降
所以可供选择的情况是：
剩下的所有可选排名-1，这一堆随便选，上下也无所谓
特殊的一种，需要被特判，但是万一被选过了呢？
咱么，需要把上面的混到一起才可以达成目标（这样就成为了普普通通的排列数QAQ） 
所以在最后减去特判的答案即可
怎么减呢？
实际上认为每一个有两种状态：1和0
1是上升，那么我们需要解决下面这个子问题：
每个元素有一个编号和一个状态1/0，编号互不相同，求编号递增的11和编号递减的00有多少种。
不过这些都太过复杂，甚至可能不可做
先来一个暴力搜索试试水吧 
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int len[40];
int ans;
void DFS(int i,int n,bool vis[],int last,bool last_sit)
{
	if(i>n)
	{
		(ans=ans+1)%=mod;//多少有点寒碜 
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(vis[j])continue;
		if(len[i]==1)
		{
			if(j==last-1&&(last_sit==0||len[i-1]==1))continue;
			if(j==last+1&&(last_sit==1||len[i-1]==1))continue;
		}
		vis[j]=true;
		if(j!=last-1||last_sit==1)DFS(i+1,n,vis,j,0);
		if(len[i]!=1&&(j!=last+1||last_sit==0))DFS(i+1,n,vis,j,1);
		vis[j]=false;
	}
	return;
}
int a[40];
bool vis[40];
int main()
{
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i+=a[i])
	{
		len[++tot]=a[i];
		for(int j=1;j<a[i];j++)if(a[i+j]!=a[i]){printf("0");return 0;}
	}
	DFS(1,tot,vis,-1,0);
	printf("%d",ans);
	return 0;
}
