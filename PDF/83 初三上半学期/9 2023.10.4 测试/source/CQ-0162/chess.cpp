#include<bits/stdc++.h>
#define N 2005
using namespace std;
int p,k,n=1;
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	for(int i=1;i<=k;i++)n*=p;
	if(p==2){
		printf("%d\n",n*(n-1)/2);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
	if(k==1){
		printf("1\n");
		for(int i=0;i<n;i++)printf("%d ",i);
		return 0;
	}
	return 0;
}
