#include<bits/stdc++.h>
using namespace std;

int n,k;
int js[6]={3,5,7,9,11,13};
int os[6]={0,2,4,6,8,10};
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("Yes\n");
		for(int i=1;i<=6;i++){
			printf("%d ",k*i);
		}
	}
	else{
		printf("Yes\n");
		for(int i=0;i<=5;i++)
			printf("%d ",js[i]);
		
		printf("\n");
		for(int i=0;i<=5;i++)
			printf("%d ",js[i]);
		
		printf("\n");
		n-=2;
		if(n){
			for(int i=1;i<=n;i++){
				for(int i=0;i<=5;i++){
					printf("%d ",os[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
} 
