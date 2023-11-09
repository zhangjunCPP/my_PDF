#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16,M=1e6+16;
int n,m,ID,Q;
int s[N];
int cnt,f[N];
struct edge { int v,net; } eg[M<<1];
void add(int uu,int vv) { eg[++cnt]=(edge) { vv,f[uu] }, f[uu]=cnt; }
int fa[N][25],dep[N];
void fds(int u,int dad) {
	fa[u][0]=dad; dep[u]=dep[dad]+1;
	for(int i=1;i<=23;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=f[u];i;i=eg[i].net) {
		int v=eg[i].v;
		if(!dep[v]) fds(v,u);
	}
}
int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=23;i>=0;i--) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return v;
	for(int i=23;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i], v=fa[v][i];
	return fa[u][0];
}
int net[N];
bool vis[N];
void dfs(int &ans,int u,int ed,int lati,int latj) {
//	for(int i=1;i<=m;i++) cout<<vis[i];
//	puts("");
	if(u==ed) { 
		if(s[ed]) {
			for(int i=lati+1;i<=m;i++) 
				if(!vis[i]) for(int j=latj+1;j<i;j++) if(!vis[j]) ans++;
		} else {
			for(int i=lati+1;i<=m;i++) 
				if(!vis[i]) for(int j=max(latj,i)+1;j<=m;j++) if(!vis[j]) ans++;
		} /*puts("");*/ return ; 
	}
	int v=net[u];
	if(s[u]) {
		for(int i=lati+1;i<=m;i++) {
			if(vis[i]) continue;
			for(int j=latj+1;j<i;j++) {
				if(vis[j]) continue;
				vis[i]=vis[j]=true;
				dfs(ans,v,ed,i,j); vis[i]=vis[j]=false;
			}
		} 
	} else {
		for(int i=lati+1;i<=m;i++) {
			if(vis[i]) continue;
			for(int j=max(latj,i)+1;j<=m;j++) {
				if(vis[j]) continue;
				vis[i]=vis[j]=true;
				dfs(ans,v,ed,i,j); vis[i]=vis[j]=false;
			}
		}
	}
}
void solve(int u,int v) {
	int ans=0,lca=LCA(u,v);
	int now=u; while(now!=lca) net[now]=fa[now][0], now=fa[now][0];
	now=v; while(now!=lca) net[fa[now][0]]=now, now=fa[now][0];
//	now=u; while(now!=v) printf("%d->",now), now=net[now];
//	printf("%d\n",v);
	dfs(ans,u,v,0,0);
	printf("%d\n",ans);
}
signed main() {
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	scanf("%d%d%d",&n,&m,&ID);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<n;i++) {
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	} scanf("%d",&Q); fds(1,0);
	while(Q--) {
		int u,v; scanf("%d%d",&u,&v);
		solve(u,v);
	}
	return 0;
}
