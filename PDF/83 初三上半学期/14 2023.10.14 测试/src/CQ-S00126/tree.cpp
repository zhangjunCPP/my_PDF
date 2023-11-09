#include<stdio.h>

#define int long long
const int N=1e6+5,mod=998244353;
int ksm(int x,int y){
	int s=1;
	while(y){
		if(y&1) (s*=x%mod)%=mod;
		(x*=x%mod)%=mod;y>>=1; 
	}
	return s;
}
int n,a[N],l[N],r[N],ans;
void dfs(int u){
	if(u==n){
		ans++;
		return ;
	}
	if(a[l[u]]==a[r[u]]&&!a[l[u]]){
		a[l[u]]=1;dfs(u+1);a[l[u]]=0;
		a[r[u]]=1;dfs(u+1);a[r[u]]=0;
	}
	else dfs(u+1); 
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);bool f=1,ff=1;
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		if(l[i]!=1) f=0;
		if(l[i]!=r[i]-1) ff=0;
	}
	if(f) {printf("%lld",n);return 0;} 
	if(ff){
		a[1]=1;a[2]=2;
		for(int i=3;i<=n;i++) a[i]=(a[i-1]+a[i-2])%mod;
		printf("%lld\n",a[n]);
		return 0;
	}
	dfs(1);printf("%lld\n",ans);
//	printf("%lld",n+(n-2)*2-1);
	return 0;
}

