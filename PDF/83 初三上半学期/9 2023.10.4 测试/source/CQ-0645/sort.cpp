#include<bits/stdc++.h> 
using namespace std;
int t,n,p;
int f[1005];
int g[1005];
int C[1005][1005];
void work(){
	scanf("%d%d",&n,&p);
	g[0]=1;g[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++)
			g[i]=(g[i]+1ll*g[j-1]*g[i-j]%p)%p;
	}
	f[0]=1;f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];//i打头阵 
		for(int j=1;j<i;j++){//j打头阵 
		int ans=f[j];
			for(int k=j;k>=1;k--){
				f[i]=(f[i]+1ll*g[j-k+1]*f[i-j]%p*f[k-1]%p);
			}
		}
	}
	int mul=1;
	for(int i=1;i<=n;i++) mul=1ll*mul*i%p;
	printf("%d",(mul-f[n]+p)%p);
}
void Freopen(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&t);
	while(t--)
		work();
}
/*
1
5 998244353
*/
