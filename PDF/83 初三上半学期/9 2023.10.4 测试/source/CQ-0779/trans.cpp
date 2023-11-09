#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit(x) (x&-x)
const int N=5005,mod=1e9+7;
int T,n,m,K;
int fa[N],id[N],Res[N],g[N][N];
int U[N],V[N],D[N],S[N];
void solve12() {
	ll res1=1,res2=1;
	for(int i=1;i<=m;i++) res1=(res1*D[i])%mod,res2=(res2*S[i])%mod;
	ll ans=K*(K-1)%mod*res1+K*res2%mod;
	printf("%lld\n",ans%mod);
}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	fa[x]=y;
}
vector<int>e[N];
void add(int u,int v) {
	e[u].pb(v);
	e[v].pb(u);
}
void dfs(int u) {
	int in=0;
	for(auto v:e[u]) if(Res[v]) in++;
	Res[u]=K-in;
	for(auto v:e[u]) if(!Res[v]) dfs(v);
}
void solve3456() {
	ll pr=0;
	for(int i=0;i<(1<<m);i++) {
		int flag=0,idx=0;
		ll ans=1;
		for(int j=1;j<=n;j++) fa[j]=j,id[j]=0;
		for(int j=0;j<m;j++) {
			if(i&(1<<j)) {
				merge(U[j+1],V[j+1]);
				ans=(ans*S[j+1])%mod;
			}
		}
		for(int j=0;j<m;j++) {
			if(!(i&(1<<j))) {
				ans=(ans*D[j+1])%mod;
				if(find(U[j+1])==find(V[j+1])) {
					flag=1;
					break;
				}
			}
		}
		if(flag) continue;
		for(int j=1;j<=n;j++) {
			int x=find(j);
			if(!id[x])id[x]=++idx;
			id[j]=id[x];
		}
		for(int j=1;j<=idx;j++)Res[j]=0,e[j].clear();
		for(int j=1;j<=m;j++)g[id[U[j]]][id[V[j]]]=0,g[id[V[j]]][id[U[j]]]=0;
		for(int j=1;j<=m;j++) if(!g[id[U[j]]][id[V[j]]])add(id[U[j]],id[V[j]]),g[id[U[j]]][id[V[j]]]=1,g[id[V[j]]][id[U[j]]]=1;
		dfs(1);
		for(int j=1;j<=idx;j++) ans=(ans*Res[j])%mod;
		pr=(pr+ans)%mod;
	}
	printf("%lld\n",pr);
}
void solve78() {
	for(int i=1;i<=n;i++)Res[i]=0,e[i].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)g[i][j]=0;
	for(int i=1;i<=m;i++) {
		if(!g[U[i]][V[i]]) add(U[i],V[i]);
		g[U[i]][V[i]]=1;
		g[V[i]][U[i]]=1;
	}
	dfs(1);
	int ans=1;
	for(int i=1;i<=n;i++) ans=(ans*Res[i])%mod;
}
signed main() {
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		int flag=0;
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=m;i++) {
			scanf("%d%d%d%d",&U[i],&V[i],&D[i],&S[i]);
			if(S[i]!=0||D[i]!=1) flag=1;
		}
//		if(n==2) solve12();
//		else 
		if(m<=20) solve3456();
		else 
		if(!flag) solve78();
	}
	return 0;
}
