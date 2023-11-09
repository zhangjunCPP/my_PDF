#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1)
	{
		puts("Yes");
		for(int i=1;i<=6;++i)
		{
			printf("%d ",k*i);
		}
		return 0;
	}
	if(k==2)
	{
		puts("Yes");
		if(n%2)
		{
			int cnt=0;
			for(int i=1;i<=n-1;++i)
			{
				for(int j=1;j<=6;++j)
				{
					printf("%d ",2*cnt+++1);
				}
				puts("");
			}
			for(int i=1;i<=6;++i)
			{
				printf("%d ",(i-1)*2);
			}
		}
		else
		{
			int cnt=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=6;++j)
				{
					printf("%d ",2*cnt+++1);
				}
				puts("");
			}
		}
		return 0;
	}
	
}
