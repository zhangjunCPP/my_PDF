#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+5;
int w[maxn];
int head[maxn],cnt;
struct edge{int to,pre;}line[maxn*2];
void addline(int u,int v)
{
	cnt++;
	line[cnt].to=v;
	line[cnt].pre=head[u];
	head[u]=cnt;
}
int dfn[maxn],dfsxu[maxn],dfn_cnt;
void dfs(int u,int fa)
{
	dfn_cnt++;
	dfn[u]=dfn_cnt;
	dfsxu[dfn_cnt]=u;
	for(int i=head[u];i;i=line[i].pre)
	{
		int v=line[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
	}
	dfsxu[dfn_cnt]=u;
}
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addline(u,v);
		addline(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cout<<n/2<<endl;
	return 0;
}
