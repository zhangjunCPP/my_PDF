#include<bits/stdc++.h>
using namespace std;

const int MAXN=3000;
const int mo=998244353;
int n;
int a[MAXN];
int vis[MAXN];
int b[MAXN];
long long ans=0;
int c[MAXN];
int tot=0;

void dfs(int cur);

int main()
{
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

void dfs(int cur)
{
	if(cur==n+1)
	{
		for(int i=1;i<=n;++i)
		{
			if(abs(b[i]-b[i-1]==1) or abs(b[i+1]-b[i])==1)
			{
				return ;
			}
		}
		ans=(ans+1)%mo;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			b[cur]=i;
			vis[i]=1;
			dfs(cur+1);
			vis[i]=0;
		}
	}
}
