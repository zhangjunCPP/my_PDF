#include<bits/stdc++.h>
using namespace std;
int q,n,m;
bool dp[51][2501];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	
	dp[0][0]=1;
	for(int i=1;i<=50;i++){
		for(int j=1;j<=i;j++){
			for(int l=2500;l>=j*j;l--) dp[i][l]|=dp[i-j][l-j*j];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		if(n*n<2*m) printf("0\n");
		else{
			if(dp[n][n*n-2*m]) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
