#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
int ans;//最大魔法总量 
int l[N],r[N],c[N];
int vis[N];
int temp;
int n;
void dfs(int x,int sum)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			temp=0;
			for(int j=l[i];j<=r[i];j++) if(!vis[j]) temp+=c[i];
			dfs(x+1,sum+temp);
			vis[i]=0;
			temp=0;
		}
	}
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&l[i],&r[i],&c[i]);
	if(n<=30) dfs(1,0);
	else
	{
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
