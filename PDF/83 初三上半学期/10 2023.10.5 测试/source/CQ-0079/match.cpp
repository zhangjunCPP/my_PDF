#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16;
int T,n,m,d[N];
vector<int> eg[N];
bool vis[N],fbi;
int dep[N];
void dfs(int u,int dad) {
	vis[u]=true; dep[u]=dep[dad]+1;
	for(int i=0;i<(int)eg[u].size();i++) {
		if(fbi) return ;
		int v=eg[u][i]; if(v==dad) continue;
		if(!vis[v]) { dfs(v,u); continue; }
		if( dep[u]-dep[v]+1==3 ) fbi=true;
	}
}
signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m); fbi=false;
		for(int i=1;i<=n;i++) d[i]=dep[i]=0, eg[i].clear(), vis[i]=false;
		for(int i=1;i<=m;i++) {
			int u,v; scanf("%d%d",&u,&v);
			eg[u].push_back(v);
			eg[v].push_back(u);
			d[u]++; d[v]++;
		} int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,d[i]);
		if(ans>=3) { printf("%d\n",ans); continue; }
		dfs(1,0); if(fbi) ans=3;
		printf("%d\n",ans);
	}
	return 0;
}
