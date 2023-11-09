#include<bits/stdc++.h>
#define int long long
#define N 105
#define mod 1000000007
using namespace std;
int T,n,m,k,u[N],v[N],a[N],b[N],id[N],ans;
void dfs(int x){
	if(x==n+1){
		int res=1;
		for(int i=1;i<=m;i++){
			if(id[u[i]]==id[v[i]]){
				if(b[i])res=res*b[i]%mod;
				else res=0;
			}else{
				if(a[i])res=res*a[i]%mod;
				else res=0;
			}
		}
		ans=(ans+res)%mod;
		return ;
	}
	for(int i=1;i<=k;i++){
		id[x]=i;
		dfs(x+1);
	}
}
void solve(){
	ans=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld%lld",&u[i],&v[i],&a[i],&b[i]);
	dfs(1);
	printf("%lld\n",ans);
}
signed main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
/*
1
2 4 3
2 1 1 1
2 1 2 2
2 1 2 0
1 2 1 1
*/
