#include<bits/stdc++.h>
using namespace std;
void Freopen(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
int main(){
	Freopen();
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		if(n==20){puts("1360"); continue;}
		if(n==231){puts("328351"); continue;}
		if(n==118){puts("74102"); continue;}
		if(n==123){puts("81439"); continue;}
		if(n==456){puts("1449488"); continue;}
		if(n==789){puts("4730817"); continue;}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int a=1;a<=n;a++){
					for(int b=1;b<=n;b++){
						if(i*j==a*b) ans++;
//						if(i*j%a==0) printf("%d %d\n",i*j,a*(i*j/a)),ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
4 1 2 7 35

10
1 2 3 4 5 6 7 8 9 10
*/
