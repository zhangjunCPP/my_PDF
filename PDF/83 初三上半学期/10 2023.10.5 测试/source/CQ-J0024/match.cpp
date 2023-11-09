#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n,m;
int x,y;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d%d",&x,&y);
		if(m==1)
		{
			cout<<1<<"\n";
			continue;
		}
		if(m==0)
		{
			cout<<0<<"\n";
			continue;
		}
		if(n==1)
		{
			cout<<0<<"\n";
			return 0;
		}
		if(m==n-1)//¾Õ»¨Í¼/Á´ 
		{
			cout<<m<<"\n";
			continue;
		}
		if(m==n)
		{
			cout<<m-1<<"\n";
			continue;
		}
	}
	return 0;
}
