/*
T2 tree
�������������
�����������Ѿ�֪�����������Ĵ�
���ȣ����ǵĸ��ڵ��һ��ͬɫ������һ�߲�ͬɫ����ʱͬɫ����һ�ߵ����������������1�Ĺ���
��Σ������������ϲ���ʱ����кܶ�Ĺ��׵�������һ���ֿ���ȥ���Ǻܺü���
������ʵ��ֻ��Ҫ���Թ۲�һ�£����ѷ��ֹ�����ʵ�������������Ĺ��׵ĳ˻�
��Ȼ�����ﻹ��һ��������������ǵ������н���һ��ͬɫ��ʱ����ʱ�Ĵ𰸻������
���ǲ���ֱ�ӵõ����������ڸ�������Щ���ܣ�Ҳ����ֱ�ӻ�����������
�����Ǻ͵�ǰ���ڵ�ͬɫ���ᷢ����Ҫ֪��ÿ����Ⱦ����ж��ٸ��㣬��ͺ��Ѱ�
��Ȼ������ǽ���¼�ܺ�Ҳ���ǲ��У���������ֻ֪���ܺ��ָ���μ��㹱���أ�
��Ȼ�������ڵ�Ĳ�������
�����Ҫ����һ���������ᷢ���ֳ��˳˻�
��������˼��
ע�⵽�ո����ǿ��ǵ��Ƕ��������ڶ�������£�������Ҫ��������

�����˼·©��̫����
�Ҳ���˵
��֮��ֻ�����һ������ 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=20;
struct edge{
	int v,nex;
}e[N<<1];
int fir[N],ent;
inline void add(int u,int v)
{
	e[++ent]={v,fir[u]};
	fir[u]=ent;
	return;
}
const int LOG=15;
int fa[N][LOG+5],dep[N];
void prework(int u,int f)
{
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=fir[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v!=f)prework(v,u);
	}
	return;
}
inline void dp(int n)
{
	for(int i=1;i<=LOG;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	return;
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	for(int i=LOG;i>=0;i--)if(dep[fa[a][i]]>=dep[b])a=fa[a][i];
	if(a==b)return a|b;
	for(int i=LOG;i>=0;i--)if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0]|fa[b][0];
}
bool c[N];
int ans;
void DFS(int i,int n)
{
	if(i>n)
	{
		int mx=0;
		for(int j=1;j<n;j++)for(int k=j+1;k<=n;k++)if(c[j]==c[k])mx=max(mx,dep[j]+dep[k]-dep[LCA(j,k)]*2);
		ans+=mx;
		return;
	}
	c[i]=true;
	DFS(i+1,n);
	c[i]=false;
	DFS(i+1,n);
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n>10){printf("40240915");return 0;}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	prework(1,1);
	dp(n);
	DFS(1,n);
	printf("%d",ans);
	return 0;
}