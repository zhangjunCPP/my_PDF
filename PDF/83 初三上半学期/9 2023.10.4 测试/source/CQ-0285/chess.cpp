#include<bits/stdc++.h>
using namespace std;
int p,k,n;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	if(k==1){
		printf("1\n");
		for(int i=0;i<p;i++){
			printf("%d ",i);
		}
		return 0;
	}
	if(p==2){
		n=1;for(int i=1;i<=k;i++)n*=p;
		printf("%d\n",n*(n-1)/2);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
	return 0;
}