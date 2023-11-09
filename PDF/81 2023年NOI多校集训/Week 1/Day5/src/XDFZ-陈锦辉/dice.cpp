//the code is from chenjh
#include<cstdio>
int n,k;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	int g=0;//log_2
	for(int i=k;i;i>>=1)++g;
	puts("Yes");
	int a[6]={0,k,k<<g,k<<g|k,(k<<(g<<1)),(k<<(g<<1))|k};
	for(int i=1;i<=n;i++){
		printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
	}
	return 0;
}

