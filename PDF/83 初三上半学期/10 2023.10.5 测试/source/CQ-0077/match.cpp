#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pb push_back
#define pii pair<ll,ll>
const ll N=1e6+5,mod=998244353,inf=0x3f3f3f3f,INF=1e18;
int T,n,m,dep[N],ans;
vector<int>e[N];
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	for(auto v:e[u]) {
		if(!dep[v]) dfs(v,u);
		else if(dep[v]==dep[u]-2) ans=3;
	}
}
signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++) {
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=0;
		dfs(1,0);
		for(int i=1;i<=n;i++) ans=max(ans,(int)e[i].size());
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)dep[i]=0,e[i].clear();
	}
	return 0;
}
