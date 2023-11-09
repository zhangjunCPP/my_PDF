#include<bits/stdc++.h>
using namespace std;
long long sum[505];
void init()
{
	for(int i=1;i<=500;++i)
	{
	    sum[i]=sum[i-1]+i;
	}
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int q;
	cin>>q;
	init();
	for(int i=1;i<=q;++i)
	{
		int n,m;
		bool pd=0;
		scanf("%d%d",&n,&m);
		if(m==0)
		{
			printf("1\n");
			continue;
		}
		if(m>n*(n-1)/2 || m<n-1)
		{
			printf("0\n");
			continue;
		}
		for(int j=0;j<=n-2;++j)
		{
			if(m==n*(n-1)/2-sum[j])
			{
				pd=1;
				break;
			}
		}
		if(pd)
		{
			printf("1\n");
			continue;
		}
		for(int j=1;j<=n/2;++j)
		{
			if(m==j*(n-j))
			{
				pd=1;
				break;
			}
		}
		if(pd)
		{
			printf("1\n");
			continue;
		}
		printf("0\n");
	}
}
