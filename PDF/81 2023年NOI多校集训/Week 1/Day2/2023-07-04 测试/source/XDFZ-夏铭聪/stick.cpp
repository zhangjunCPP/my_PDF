#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int N=1e5+5;
bool f[505][N];
int n,m;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	srand(time(0));
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int t=n*(n-1)/2;
		if(m==0||(m>=n-1&&m<=t)) puts("1");
		else puts("0");
	}
    return 0;
}