#include<bits/stdc++.h>
using namespace std;
int n,k,tot,a[101][7];
int count(int x){
	int res=0;
	while(x) res++,x>>=1;
	return res;
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=6;i++){
		if((1<<i)==k){
			printf("Yes\n");
			int h=1;
			for(int i=2;i<=6;i++) a[1][i]=k*h,h*=2;
			for(int i=2;i<=n;i++) for(int j=1;j<=6;j++) a[i][j]=a[1][j];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=6;j++) printf("%d ",a[i][j]);
				printf("\n");
			}
			return 0;
		}
	}
	if(n==1) for(int i=1;i<=6;i++) a[1][i]=i*k;
	else{
		long long h=1;
		for(int i=2;i<=6;i++) a[1][i]=k*h,h*=(1ll<<count(k));
		for(int i=2;i<=n;i++) for(int j=1;j<=6;j++) a[i][j]=a[1][j];
	}
	if(a[1][6]>1e6) printf("No");
	else{
		printf("Yes\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
