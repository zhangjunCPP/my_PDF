#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=4010,INF=0x3f3f3f3f;
int n,id,mx,ans=INF,len,to[N<<1],ne[N<<1],head[N],a[N],st[N],dp[M][M];
void add(int x,int y) {to[++id]=y,ne[id]=head[x],head[x]=id;}
void dfs1(int u,int fa,int rt)
{
	for(int i=1;i<=len;i++)
		if(a[u]>a[st[i]]) dp[rt][u]=max(dp[rt][u],dp[rt][st[i]]+1);
	st[++len]=u;
	for(int i=head[u];i;i=ne[i])
	{
		int v=to[i];if(v==fa) continue;
		dfs1(v,u,rt);
	}
	len--;
}
void dfs2(int u,int fa,int s,int rt)
{
	mx=max(mx,dp[rt][u]);
	for(int i=head[u];i;i=ne[i])
	{
		int v=to[i];if(v==fa||v==s) continue;
		dfs2(v,u,s,rt);
	}
}
int main()
{
	freopen("lis.in","r",stdin),freopen("lis.out","w",stdout);
	scanf("%d",&n);for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dp[i][j]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);for(int i=1;i<=n;i++) dfs1(i,0,i);
	for(int i=1;i<=n;i++)
	{
		mx=0;for(int j=1;j<=n;j++) if(i!=j) dfs2(j,0,i,j);
		ans=min(ans,mx);
	}
	printf("%d",ans);
}
/*
5
1 2
2 3
3 4
4 5
1 2 3 4 5
*/
