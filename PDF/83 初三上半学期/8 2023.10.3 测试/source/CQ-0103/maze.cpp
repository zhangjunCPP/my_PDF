#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define v first
#define w second
const int N=5e5+5;
const ll inf=1e18;
ll dis[N],d[N],n,m,k,vis[N];
vector<pii>e[N];
struct node{
	ll v,val;
	bool operator < (const  node &other) const {
		return val>other.val;
	}
};
priority_queue<node>q;
signed main() {
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)dis[i]=inf;
	for(int i=1,x;i<=k;i++) {
		scanf("%d",&x);
		dis[x]=0;
		q.push({x,0});
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",&d[i]);
		if(!dis[i]) d[i]=0;
	}
	for(int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	while(!q.empty()) {
		int u=q.top().v,w=q.top().val;
		q.pop();
		if(vis[u]) continue;
		if(!d[u]) {
			vis[u]=1;
			dis[u]=w;
		}
		else {
			d[u]--;
			continue;
		}
		for(auto V:e[u]) {
			if(!vis[V.v]) {
				q.push({V.v,dis[u]+V.w});
			}
		}
	}
	if(dis[1]==inf) printf("-1");
	else printf("%lld",dis[1]);
	return 0;
}
