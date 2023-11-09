#include<stdio.h>

#define int long long
const int N=0;
int p,s;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&s);
	// printf("2");
	
	// s--;
	// int tt=t-s;
	if(p-2==s*2)
	{
		printf("23");
		for(int i=1;i<n;i++) printf("2");
		printf("33");
		for(int i=1;i<n;i++) printf("2");
	}
	else if(p-2>s*2) puts("Impossible");
	else
	{
		int t=(s+1)*2-p,h=1,l=s;
		while(t>0)
		{
			l--;h++;
			int tmp=(l-1)/2;
			if(t-tmp<0)
			{
				l-=t;
			}
		}
	}
    return 0;
}