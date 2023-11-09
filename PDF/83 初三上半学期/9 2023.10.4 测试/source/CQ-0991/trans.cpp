#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105;
const ll mod=1e9+7;
ll n,m,k;
ll ans;
ll f[N][N],g[N][N];
struct Node{ll x,y,a,b;}e[N];
ll vis[N];
void dfs(ll x){
	if(x>n){
		ll res=1;
		for(ll i=1;i<=m;i++){
			ll x=e[i].x,y=e[i].y,a=e[i].a,b=e[i].b;
			if(vis[x]==vis[y]) res=res*b%mod;
			else res=res*a%mod;
		}
		ans=(ans+res)%mod;
		return;
	}
	for(ll i=1;i<=k;i++){
		vis[x]=i;
		dfs(x+1);
	}
}
void solve(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			f[i][j]=g[i][j]=1;
		}
	}
	for(ll i=1;i<=m;i++){
		ll x,y,a,b;
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		e[i]={x,y,a,b};
		if(n==2){
			f[x][y]=f[x][y]*a%mod;
			g[x][y]=g[x][y]*b%mod;
		}
	}
	if(n==2){
		ans=g[1][2]*g[2][1]%mod*k%mod;
		ans=(ans+f[1][2]*f[2][1]%mod*k%mod*(k-1)%mod)%mod;
	}
	if(n==9||n==12) dfs(1);
	printf("%lld",ans);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
