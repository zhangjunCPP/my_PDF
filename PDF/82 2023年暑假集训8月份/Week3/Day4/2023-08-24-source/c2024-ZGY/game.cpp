/*
B game
首先一个简单的分析，这是个单调栈
我们的策略肯定是首先满足大的x
从大的x开始，先把所有小的给他，让他把自己的分吃满
发现这样一定是更优的，不然如果存在y使得vy<vx，还存在一种方法使得x吃满不如y吃满的话，显然我可以让y吃的给一部分给x使得答案更大
于是排序之后做成为了一个思路，但缺乏正确性证明（简单粗暴的对拍） 
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void r(T &&x)
{
	char c;x=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x*=10,x+=c-'0',c=getchar();
	return;
}
template<typename T,typename ...Args>
inline void r(T &&x,Args &&...args){r(x);r(args...);return;}
const int N=1919810;
using ll=long long;
struct person{
	ll v;
	int id;
	bool operator < (const person &oth){if(v==oth.v)return id<oth.id;return v>oth.v;}
}p[N];
int op[N],opt;
int main()
{
	int n;
	r(n);
	for(int i=1;i<=n;i++)r(p[i].v),p[i].id=i;
	sort(p+1,p+n+1);
	ll ans=0;
	for(int i=1,ptr=n;i<=n;i++)
	{
		if(p[i].id<ptr)
		{
			op[++opt]=p[i].id;
			ans+=(ptr-p[i].id)*p[i].v;
			ptr=p[i].id;
		}
	}
	printf("%lld\n",ans);
	for(int i=1,ptr=n;i<=opt;i++)
	{
		for(int j=op[i]+1;j<=ptr;j++)printf("%d ",j);
		ptr=op[i];
	}
	printf("1");
	return 0;
}
