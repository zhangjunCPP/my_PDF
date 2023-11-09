#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("Yes\n");
		printf("%d %d %d %d %d %d",k,k*2,k*3,k*4,k*5,k*6);
		return 0;
	}
	if(k==2){
		printf("Yes\n");
		if(n%2){
			for(int i=1;i<=n-1;i++)printf("1 3 5 7 9 11\n");
			printf("2 4 6 8 10 12\n");
		}else{
			for(int i=1;i<=n-2;i++)printf("1 3 5 7 9 11\n");
			printf("2 4 6 8 10 12\n");
			printf("2 4 6 8 10 12\n");
		}
		return 0;
	}
	return 0;
} 
