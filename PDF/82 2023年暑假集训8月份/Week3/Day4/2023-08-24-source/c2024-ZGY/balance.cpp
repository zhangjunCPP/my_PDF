/*
C balance
�������ı����Ұ����⣬˭��ȥд���Ⱑ
������ʱ���ٰ�����chuachua�˵���
���Կ���ǰ����������
ע�⵽��Ҫ�õ���40ptsҪ����㷨����ֻ����n^2
��ϸһ����Ŷ��������Ȼ�ǿ���
�������ˣ�DFS���ж����Ⱥ󱲵Ĺ�ϵ������һ�¾���O(1)�õ����
����ö�٣�ʱ�临�Ӷ�������n^2
Ȼ�������������ݣ�����Ȼ����ֱ�Ӷ�λ�������һ�����ּ��ɣ����ջ������ˣ�ֱ�Ӱ��м��Ǹ���ɾ������
�������ֱ�����ͻ����������ͻȻ���֣��������ⶼ�Ѿ���֮�����ˣ��ѵ������ǵ����⣿
����ʱ�޸���3s����ѡ�����
���ò�˵������ȥ��ĺܿ��У����Ǽ��ϻ���AB��Ķ����������ֻ������ʱ����

���ֱ�����û����ô���ã����ǻ�Ҫ��������
������ĵ�����ɾȥһ����֮��ɢ�����Ķ����
������ҪѰ����һ��O(1)����ķ���

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
			if(en[u]<st[v])//����ͬһ������
			{
				siz[0]=en[son[v]]-st[son[v]];
				siz[1]=en[son[u]]-st[son[u]];
				siz[2]=n-en[v]-en[u]+st[v]+st[u]-2; 
			}
			else//����ͬһ������,��ʱ��v��u������
			{
				siz[0]=en[son[v]]-st[son[v]];
				if(st[v]>=st[son[u]]&&en[v]<=en[son[u]])siz[1]=max(mx[u],en[son[u]]-st[son[u]]+en[v]-st[v]-1);//������������
				else siz[1]=en[son[u]]-st[son[u]];
				siz[2]=n-en[u]+st[u]-2;
				if(u==1)siz[2]=mx[u];
			}
			if(max(siz[0],max(siz[1],siz[2]))<mn)mn=max(siz[0],max(siz[1],siz[2])),ans=j;
		}
		printf("%d\n",ans);
	}
	//д��ƨ������
	//�׸�40pts �Ҿ��Ǹ��İ� 
	return 0;
}
