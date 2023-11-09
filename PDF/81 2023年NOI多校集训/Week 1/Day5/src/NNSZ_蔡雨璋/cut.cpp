#include<bits/stdc++.h>
using namespace std;
int n,a[100010]={},ans=1,cut[100010]={},situ[100010]={},dp[100010]={},tot=0;

int check(int si)
{
	for(int i=0;i<=20;i++)
		if(((1<<(i))&si)==0)
		{
//			cout<<bitset<5> (si)<<' '<<i<<endl;
			return i;
		}
	return 20;
}


int main()
{
	freopen("cut.in","r",stdin); 
	freopen("cut.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cut[1]=1;
	for(int i=1;i<=n;i++)
	{
		if( !(situ[ans]&(1<<a[i])) )
			situ[ans]+=(1<<a[i]);
		else
		{
			dp[ans]=check(situ[ans]);
			cut[++ans]=i;situ[ans]+=(1<<a[i]); 
		}
	}
	dp[ans]=check(situ[ans]);
	for(int i=1;i<=ans;i++)
	{
//		printf("dp[%d]:%d\nsitu[%d]:",i,dp[i],i);cout<<bitset<5> (situ[i])<<endl;
		tot+=dp[i];
//		printf("tot+=dp[%d],tot=%d\n",i,tot);
	}
	printf("%d %d\n",tot,ans);
	for(int i=1;i<=ans;i++)printf("%d ",cut[i]);
	return 0;
}
/*
第一眼的时候确实被吓住了...
但是仔细一看，再用手模拟一下，就会发现
直接从第一个数开始枚举，检查这个数与当前所选段中的元素是否重复，如果重复了就cut掉，重新记录 
等等，好像没那么简单 
如果是 1 0 2 5 3 4 0 6 7呢
很明显答案是8，但是如果按上面的想法的话会在第二个0就cut掉，得出答案是7
寄
等等，用状压dp？ 
dp[i][j]存在i状态下选第j个数(k)后mex的最大值 
转移式就是dp[i][j]=max(dp[i-(1<<(k-1)][j-1],dp[1<<(k-1)][j]); 
好像也不行......一共有 1,048,575 种状态，空间复杂度一定会爆炸 
再寄一次 
mad，干脆直接
for(int i=1;i<n;i++)枚举切几刀 
	int cut=i;
	for(int j=1;j<=n;j++)//看在哪个位置切 
		然后直接暴力求解 
		...
寄寄寄寄 
等等
或许可以这样
先按第一种思路预处理，然后再用两个for遍历，如果两段拼起来的值比原来更大，就先记录下来 
问题是怎么存.. 
mad，感觉之前看状压看魔怔了，现在脑子里全是状压 
那就用状压试试？用situ[]存预处理后每段的颜色状态（二进制）合并就用 | （按位或）
好吧...来不及时间写力，只能按第一种方法写了... 
*/
