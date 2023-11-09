/*
我不会位运算
而且这题捆绑测试
就算辛辛苦苦码了一堆字也可能不得70'的点
干脆稳拿那30'先 
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,_k,sp=1,fl,ans[6];
int zhi[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("Yes\n");
		for(int i=1;i<=6;i++)
			printf("%d ",k);
		return 0;
	}
	if(k==2){
		printf("Yes\n");
		if(n%2==0){
			for(int j=0;j<n;j++){
				for(int i=1;i<=6;i++){
					printf("%d ",sp+2*j);
					sp+=2;
				}
			printf("\n");
			}
			return 0;
		}
		for(int j=0;j<n-1;j++){
			for(int i=1;i<=6;i++){
				printf("%d ",sp+2*j);
				sp+=2;
			}
			printf("\n");
		}
		for(int i=2;i<=12;i+=2)
			printf("%d ",i);
		printf("\n"); 
		return 0;
	}
	_k=(2*k)^k;
	for(int i=0;i<17;i++)
		if(zhi[i]==k) fl++;
	for(int i=0;i<17;i++)
		if(_k==zhi[i]) fl=-1;
	if(fl<0){
		printf("No\n");
		return 0;
	}
	else if(fl==0&&n%2==0){
		printf("No\n");
		return 0;
	} 
	else{
		printf("Yes\n");
		for(int i=0;i<6;i++)
			ans[i]=(k*(i+2))^k;
		for(int i=0;i<6;i++)
			printf("%d ",k*(i+1));
		printf("\n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<6;j++)
				printf("%d ",ans[j]);
			printf("\n");
		}
	}
	return 0;
}
