#include<stdio.h>
#include<algorithm>

const int N=105;
int n,k;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==2)
	{
		puts("Yes");
		if(n&1) {for(int i=0;i<6;i++) printf("%d ",i*2); printf("\n"); n--;}
		while(n)
		{
			for(int i=0;i<6;i++) printf("%d ",i*2+1); printf("\n");
			for(int i=0;i<6;i++) printf("%d ",i*2+1); printf("\n");
			n-=2;
		}
	}
	else if(n==1) {puts("Yes");for(int i=1;i<=6;i++) printf("%d ",k*i);}
	else puts("No");
    return 0;
}