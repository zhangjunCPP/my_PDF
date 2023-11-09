#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
int ver[N*2],nxt[N*2],head[N],idx;
int dis[N],r,node,dis1[N];
int f[N][25],t,subtree[N],dep[N];
long long two[N];
int dp[N][2];
int n;
vector<int> v;
void add(int x,int y)
{
	ver[++idx]=y;
	nxt[idx]=head[x];
	head[x]=idx;
}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa)
		{
			continue;
		}
		dis[y]=dis[x]+1;
		if(dis[y]>dis[node])
		{
			node=y;
			r=dis[y];
		}
		dfs(y,x);
	}
}
void dfs1(int x,int fa)
{
	subtree[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa)
		{
			continue;
		}
		dep[y]=dep[x]+1;
		f[y][0]=x;
		for(int i=1;i<=t;++i)
		{
			f[y][i]=f[f[y][i-1]][i-1];
		}
		dfs1(y,x);
		subtree[x]+=subtree[y];
	}
}
//int lca(int x,int y)
//{
//	if(dep[x]<dep[y])
//	{
//		swap(x,y);
//	}
//	for(int i=t;i>=0;--i)
//	{
//		if(dep[f[x][i]]>=dep[y])
//		{
//			x=f[x][i];
//		}
//	}
//	if(x==y)
//	{
//		return x;
//	}
//	for(int i=t;i>=0;--i)
//	{
//		if(f[x][i]!=f[y][i])
//		{
//			x=f[x][i];
//			y=f[y][i];
//		}
//	}
//	return f[x][0];
//}
void init(int l,int r)
{
	two[0]=1;
	for(int i=1;i<=n;++i)
	{
		two[i]=two[i-1]*2;
		two[i]%=mod;
	}
	int nowl=l,nowr=r;
	v.push_back(l);
	while(nowl!=nowr)
	{
		nowl=f[nowl][0];
		v.push_back(nowl);
	}
}
int main(){
	cin>>n;
	t=log2(n)+1;
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	dis[node]=0;
	int l=node,r;
	dfs(node,0);
	r=node;
	dep[r]=1;
	dfs1(r,0);
	init(l,r);
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	for(int i=1;i<=n;++i)
	{
		
	}
}
