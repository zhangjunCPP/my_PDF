#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxk=505;
int n,k;
int t[maxn];
struct stamp{int num,cost;}stam[maxk];
int head[maxn],cnt;
struct edge{int to,pre;}line[maxn*2];
void addline(int u,int v)
{
	line[cnt].to=v;
	line[cnt].pre=head[u];
	head[u]=cnt;
	cnt++;
}
int one;
bool vis[maxn];
struct node{int spend,tim;}nod[maxn];
bool cmp(const stamp &x,const stamp &y)
{
	return x.cost<y.cost;
}
int ind[maxn],outd[maxn];
void dfs(int u)
{
	outd[u]--;
	for(int i=head[u];i!=-1;i=line[i].pre)
	{
		int v=line[i].to;
		ind[v]--;
		for(int j=1;j<=k;j++)
		{
			if(nod[i].tim+stam[j].num>=nod[v].tim && nod[i].spend+stam[j].cost<nod[v].spend && !vis[v])
			{
				nod[v].spend=nod[i].spend+stam[j].cost;
			}
		}
		if(ind[v]==0)
			vis[v]=1;
		if(outd[v]!=0)
			dfs(v);
		else
		{
			if(outd[u]>=1)
				dfs(u);
			else
				return ;
		}
	}
}
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&k);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&stam[i].num,&stam[i].cost);
	}
	scanf("%d",&one);
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			printf("%d\n",one);
		return 0;
	}
	sort(stam+1,stam+1+k,cmp);
	for(int i=1;i<=n;i++)
	{
		nod[i].spend=one*i;
		nod[i].tim=t[i];
	}
	nod[0].spend=0;
	nod[0].tim=0;
	for(int i=0;i<n;i++)
	{
		for(int j=n;j>=i+1;j--)
			addline(i,j),ind[j]++,outd[i]++;
	}
	dfs(0);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",nod[i].spend-nod[i-1].spend);
	}
	return 0;
}
