/*
B segment
这样的题首先考虑的是DP
发现DP不是很能做之后发掘一下性质再想
考虑每个元素要么自己是一个区间要么和前一个凑成一个区间
想到一个点，长度为 $1$ 的区间肯定是由不大不小刚刚好的数字组成的
注意到 $a_i$ 为正，这说明一个重要的事情，任何长度为 $2$ 的区间一定比原数大
也就是说，如果我们想要提升某个数的值，那么把它放进一个区间内就好了
或者说，我们考虑我们合并的区间数
发现了吗？我们合并的再多，这东西有子结构最优性
我们肯定不会想着合并出更大的最大值，而是想尽办法把最小值放大
那其实我们可以猜个结论
我们每次寻找最小的那个数并尝试合并，这样一定能够得到答案

看了半天看得头痛，写不出来，还是算了，暴力吧
*/
#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9;
int a[114];
void DFS(int i,int mn,int mx)
{
	if(i>n+1)return;//不统计答案
	if(i==n+1){ans=min(ans,mx-mn);return;}
	DFS(i+2,min(mn,a[i]+a[i+1]),max(mx,a[i]+a[i+1]));
	DFS(i+1,min(mn,a[i]),max(mx,a[i]));
	return;
}
int main()
{
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	if(n>20)return 0;//不想挣扎
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	DFS(1,1e9,-1e9);
	printf("%d",ans);
	return 0;
}
