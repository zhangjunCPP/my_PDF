#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
const int maxn=1e6+5;
long long ans;
int head[maxn],k;
struct edge{int to,pre;}line[maxn];
void addline(int u,int v)
{
	k++;
	line[k].to=v;
	line[k].pre=head[u];
	head[u]=k;
}
int d[maxn],c,ind[maxn];
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=line[i].pre)
	{
		int v=line[i].to;
		if(v==fa)
			continue;
		d[v]=d[u]+1;
		if(d[v]>d[c])
			c=v;
		dfs(v,u);
	}
}
int C(int n,int m)
{
	if(n==1 && m==1)
		return 1;
	if(m==0)
		return 1;
	if(m==n)
		return 1;
	return C(n-1,m-1)+C(n-1,m);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		addline(u,v);
		addline(v,u);
		ind[u]++;
		ind[v]++;
	}
	dfs(1,0);
	d[c]=0;
	dfs(c,0);
	int mid=n>>1;
	if(n==1)
	{
		printf("%d",0);
		return 0;
	}
	if(n==2)
	{
		printf("%d",2);
		return 0;
	}
	if(ind[1]==n-1)
	{
		if(n%2==0)
			cout<<((2%mod)*((long long)pow(2,n)%mod)%mod+mod)%mod;
		else
		{
			if(n==3)
				cout<<12;
			else
			{
				for(int i=1;i<=n/2;i++)
					ans+=C(n,i);
				ans*=4;
				cout<<ans%mod;
			}
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=mid;i++)
			ans+=C(n,i);
		ans*=d[c];
		ans*=2;
		ans+=(d[c]-1)*2;
		cout<<ans;
	}
	return 0;
}
