/*
C 01宝藏
肯定暴力，第一档3^15*15=215233605有点极限，第二档2^25=16777216乱跑
具体第一档直接DFS，第二档枚举选/不选确定答案
注意看第二档，感觉其实有点正解的味道，因为选/不选是个01背包
但是我已经管不着了，两个暴力60pts，不要白不要
考虑到第一档过于极限，我们需要把乘的15删掉，于是在过程中直接维护极差即可
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[50];
namespace Sub1
{
	int ans=2e9;
	vector<int>col,fol;
	void DFS(int u,int sum[4])
	{
		if(u>n)
		{
			int mx=max(max(sum[1],sum[2]),sum[3]);
			int mn=min(min(sum[1],sum[2]),sum[3]);
			if(mx-mn<ans)
			{
				ans=mx-mn;
				fol=col;
			}
			return;
		}
		for(int i=1;i<=3;i++)
		{
			sum[i]+=a[u];
			col.push_back(i);
			DFS(u+1,sum);
			sum[i]-=a[u];
			col.pop_back();
		}
		return;
	}
	inline void solve()
	{
		if(n>15)return;
		int sum[4]={0,0,0,0};
		DFS(1,sum);
		for(auto it:fol)printf("%d ",it);
		exit(0);
	}
}
namespace Sub2
{
	#define ll long long
	ll target;
	bool vis[50];
	vector<int>op;
	int fol[50];
	bool f;
	void DFS(int u,ll sum,int c)
	{
		if(sum==target)
		{
			for(auto it:op)fol[it]=c,vis[it]=true;
			f=true;
			return;
		}
		if(u>n||sum>target)return;
		DFS(u+1,sum,c);
		if(vis[u]||f)return;
		op.push_back(u);
		DFS(u+1,sum+a[u],c);
		op.pop_back();
		return;
	}
	inline void solve()
	{
		ll sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		if(sum%3)return;
		target=sum/3;
		for(int i=1;i<=3;i++)f=false,DFS(1,0,i),op.clear();
		for(int i=1;i<=n;i++)if(a[i])printf("%d ",fol[i]);else printf("%d ",rand()%3+1);
		exit(0);
	}
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	Sub1::solve();
	Sub2::solve();
	puts("Where is the mother of the author of this contest?");
	return 0;
}
