/*
C balance
你这样的鲍丽芬摆在这，谁还去写正解啊
订正的时候再把正解chuachua了得了
所以考虑前两档鲍丽芬
注意到想要拿到这40pts要求的算法极限只能是n^2
仔细一看，哦妈妈的这居然是棵树
于是有了，DFS序判断祖先后辈的关系，分讨一下就能O(1)得到结果
加上枚举，时间复杂度正好是n^2
然后两档特殊数据，链自然可以直接定位，将大的一个均分即可，而菊花更简单了，直接把中间那个点删掉就行
从这种种鲍丽芬突进上来，你突然发现，好像正解都已经呼之欲出了，难道这真是道简单题？
发现时限给了3s，首选淀粉质
不得不说，看上去真的很可行，但是肩上还有AB题的对拍任务，这个只能先暂时搁置

发现暴力并没有那么好拿，我们还要查找子树
最神奇的点在于删去一个点之后散开来的多个块
我们需要寻找另一个O(1)计算的方法

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
const int N=300010;
struct edge{
	int v,nex;
}e[N*2];
int fir[N],ent;
int n;
inline void add(int u,int v)
{
	e[++ent]={v,fir[u]};
	fir[u]=ent;
	return;
}
int st[N],en[N],dfn;
int son[N],mx[N];
void DFS(int u)
{
	st[u]=++dfn;
	for(int i=fir[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!st[v])DFS(v);
		if(en[v]-st[v]>en[son[u]]-st[son[u]])mx[u]=en[son[u]]-st[son[u]],son[u]=v;
		else if(en[v]-st[v]>mx[u])mx[u]=en[v]-st[v];
	}
	en[u]=dfn;
	return;
}
inline void Sub_link()
{
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2)printf("%d\n",(n+i+1)/2);
		else printf("%d\n",i/2);
	}
	exit(0);
}
inline void Sub_flower()
{
	puts("2");
	for(int i=2;i<=n;i++)puts("1");
	exit(0);
}
int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	r(n);
	bool link=true,flower=true;
	for(int i=1;i<n;i++)
	{
		int u,v;
		r(u,v);
		add(u,v),add(v,u);
		if(v!=u+1)link=false;
		if(u!=1)flower=false;
	}
	if(link)Sub_link();
	if(flower)Sub_flower();
	DFS(1);
//	for(int i=1;i<=n;i++)printf("%d %d %d %d\n",st[i],en[i],son[i],mx[i]);
	for(int i=1;i<=n;i++)
	{
		int mn=1e9,ans=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			int u=i,v=j;
			if(st[u]>st[v])swap(u,v);
			int siz[3];
			if(en[u]<st[v])//不在同一子树内
			{
				siz[0]=en[son[v]]-st[son[v]];
				siz[1]=en[son[u]]-st[son[u]];
				siz[2]=n-en[v]-en[u]+st[v]+st[u]-2; 
			}
			else//若在同一子树内,此时有v是u的子孙
			{
				siz[0]=en[son[v]]-st[son[v]];
				if(st[v]>=st[son[u]]&&en[v]<=en[son[u]])siz[1]=max(mx[u],en[son[u]]-st[son[u]]+en[v]-st[v]-1);//在最大的子树内
				else siz[1]=en[son[u]]-st[son[u]];
				siz[2]=n-en[u]+st[u]-2;
				if(u==1)siz[2]=mx[u];
			}
			if(max(siz[0],max(siz[1],siz[2]))<mn)mn=max(siz[0],max(siz[1],siz[2])),ans=j;
		}
		printf("%d\n",ans);
	}
	//写个屁，死了
	//白给40pts 我就是个寄吧 
	return 0;
}
