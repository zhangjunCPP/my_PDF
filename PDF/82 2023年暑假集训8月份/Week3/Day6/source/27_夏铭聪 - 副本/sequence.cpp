#include<stdio.h>

const int N=55,mod=998244353;
int n,k,f[N],sum[N],t,d[N],cnt[255];
void dfs(int u,int x){
	if(sum[u-1]>k) return ;
	if(u==n+1)
	{
		if(sum[u-1]<=k) (cnt[sum[u-1]]+=1)%=mod;
		return ;
	}
	f[u]=d[u-1];d[u]=f[u]+f[u-1];sum[u]=sum[u-1]+f[u];
	dfs(u+1,x^1);
	f[u]=f[u-1];d[u]=d[u-1]+f[u];sum[u]=sum[u-1]+f[u];
	dfs(u+1,x);
	return ;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[0]=f[1]=1;sum[1]=1;d[1]=2;
	dfs(2,1);
	for(int i=1;i<=k;i++) printf("%d ",cnt[i]%mod*2%mod);
    return 0;
}
/*
1134903168

*/