#include<bits/stdc++.h>
using namespace std;

int q;
int shu[1000];

int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	
	scanf("%d",&q);
	
	for(int i=1;i<=500;++i)
	{
		shu[i]=shu[i-1]+i;
	}
	
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1 and b!=0)
		{
			puts("0");
			continue ;
		}
		if(b==0)
		{
			puts("1");
			continue ;
		}
		if(b>shu[a-1] or b<a-1)
		{
			puts("0");
			continue;
		}
		puts("1");
	}
	
	return 0;
}
