#include <bits/stdc++.h>
using namespace std;
int q,n,m;
const int maxn=1e5+5;
int a[maxn];
bool flag=0;
void dfs(int now,int tot)
{
	if(now>n)
	{
		if(flag==0)
		{
			cout<<0<<endl;
			return ;
		}
	}
	if(tot==m)
	{
		flag=1;
		cout<<1<<endl;
		return ;
	}
	for(int i=1;i<now;i++)
	{
		dfs(now+1,tot+i);
	}
}
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&q);
	a[3]=3;
	for(int i=4;i<=maxn-5;i++)
		a[i]=a[i-1]+(i-1);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		if(n==1 && m!=0)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==2 && m==1)
		{cout<<1<<endl;continue;}
		if(m==0)
		{cout<<1<<endl;continue;}
		if(m>a[n])
		{
			cout<<0<<endl;
			continue;
		}
		if(m<n-1)
		{
			cout<<0<<endl;
			continue;
		}
		dfs(1,m);
		flag=0;
	}
	return 0;
}
