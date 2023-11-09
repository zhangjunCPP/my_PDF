/*
D match
其实限制2卡的很死，直接就说我们每个数只能选择一个二进制位
因为但凡有两个数选择了同一个二进制位，这就意味着一定会出现AND!=0的情况
这其实让我们构造起来有迹可循
注意OR运算的特殊性，$s$ 不可能小于给出的 $b$ 全部或起来的值
所以先把 $b$ 给全部做好，然后考虑怎么让每个 $1$ 只被一个数占据
先不管那个
$\sum p_k \le 10^6$ 这个东西不管怎么看都是很关键的
除非是它写错了
还真是
$n=2$ 的情况怎么解决？
我们只需要找到冲突的最高位，然后把较大的那个的冲突给取消掉就好了 
*/
#include<bits/stdc++.h>
using namespace std;
bitset<1919810>ans;
int p[1919810],q[1919810];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,k[2];
	scanf("%d%d",&n,&m);
	if(n>2){for(int i=1;i<=m;i++)putchar('1');return 0;}//死
	if(n==1)
	{
		scanf("%d",k);
		for(int i=1;i<=k[0];i++)
		{
			scanf("%d",p+i);
			ans[p[i]-1]=1;
		}
		for(int i=m-1;i>=0;i--)printf("%d",(int)ans[i]);
		return 0;
	}
	int ptr[2];
	scanf("%d",k);for(int j=1;j<=k[0];j++)scanf("%d",p+j);ptr[0]=k[0];
	scanf("%d",k+1);for(int j=1;j<=k[1];j++)scanf("%d",q+j);ptr[1]=k[1];
	while(ptr[0]&&ptr[1])
	{
		while(p[ptr[0]]>q[ptr[1]])ans[p[ptr[0]--]]=1;
		if(p[ptr[0]]==q[ptr[1]])break;
		ans[q[ptr[1]--]]=1;
	}
	if(!ptr[0]||!ptr[1])
	{
		while(ptr[0])ans[p[ptr[0]--]]=1;
		while(ptr[1])ans[p[ptr[1]--]]=1;
		for(int i=m;i;i--)printf("%d",(int)ans[i]);
		return 0;
	}
	int x=p[ptr[0]];
	ans[x]=1;
	while(ans[x])ans[x]=0,x++;
	ans[x]=1;
	while(p[ptr[0]]==q[ptr[1]]&&ptr[0]&&ptr[1])ans[p[ptr[0]]]=1,ptr[0]--,ptr[1]--;
	if(p[ptr[0]]>q[ptr[1]])while(ptr[1])ans[q[ptr[1]]]=1,ptr[1]--;
	else while(ptr[0])ans[p[ptr[0]]]=1,ptr[0]--;
	for(int i=m;i;i--)printf("%d",(int)ans[i]);
	return 0;
}
