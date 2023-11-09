//异或和，异或是不会进位的
//两个倍数然后搜？
#include <bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=1e6;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		printf("Yes\n");
		for(int i=1;i<=6;i++)
		{
			printf("%d ",i*k);
		}
		return 0;
	}
	if(k==2)
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=6;j++)
			{
				printf("%d ",2*i*j);
			}
			printf("\n");
		}
		return 0;
	}
	if(k%2==1)
	{
		printf("No\n");
		return 0;
	}
	else
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=6;j++)
			{
				if(i*k*j<=maxn)
				{
					printf("%d ",i*k*j);
				}
				else
				{
					printf("%d ",0);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
