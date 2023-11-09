#include<bits/stdc++.h>
using namespace std;
int p[100],q[100];
int main()
{
	int n;
	scanf("%d",&n);
//	int i;
//	scanf("%d",&i);
	for(int i=1;i<=n;i++)
	{
		iota(p+1,p+i+1,1);
		int ans=0,warning=0;
		do
		{
			for(int j=1;j<=i;j++)q[p[j]]=j;
			bool flag=true,print_flag=true;
			for(int j=1;j<=i;j++)if(p[j]!=q[j]){flag=false;break;}
			ans+=flag;
//			for(int j=1;j<=i;j++)if(p[j]==j)print_flag=false;
//			if(flag){for(int j=1;j<=i;j++)printf("%d ",p[j]);putchar(10);}
		}
		while(next_permutation(p+1,p+i+1));
//		printf("n=%d ans=%d warning=%d\n",i,ans,warning);
		printf("n=%d ans=%d\n",i,ans);
	}
	return 0;
}
