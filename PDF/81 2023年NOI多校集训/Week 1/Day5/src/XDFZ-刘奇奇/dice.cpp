#include<bits/stdc++.h>
using namespace std;
int n,k;
signed main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("Yes\n");
		for(int i=1;i<=6;i++){
			printf("%d ",i*k);
		}
	}else if(k==2){
		printf("Yes\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++){
				printf("%d ",j*2);
			}
			printf("\n");
		}
	}else{
		int a=0b00001;
		int b=0b00010;
		int c=0b00100;
		int d=0b01000;
		int e=0b10000;
		int f=0b11111;
		puts("Yes");
		for(int i=1;i<=n;i++){
			printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
		}
	}
	return 0;
}
