#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=2e5+5, inf=1e18;

ll s[maxn], d[maxn], dis[maxn], vis[maxn];
multiset<ll> st[maxn];
vector<pair<ll,ll> > g[maxn];

struct node {
	ll x;
	ll v;
	bool operator <(const node&other) const {
		return v>other.v;
	}
};

int main() {
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n,m,k; cin>>n>>m>>k;
	for(ll i=1;i<=k;i++) cin>>s[i];
	for(ll i=1;i<=n;i++) cin>>d[i], dis[i]=inf;
	for(ll i=1;i<=m;i++) {
		ll u,v,w; cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	priority_queue<node> q;
	for(ll i=1;i<=k;i++) q.push((node){s[i],0});
	while(q.size()) {
		ll x=q.top().x,v=q.top().v; q.pop();
		if(vis[x]) continue;
		vis[x]=1; dis[x]=v;
		for(auto p:g[x]) {
			ll y=p.first, z=p.second;
			st[y].insert(z+v);
			while(st[y].size()>d[y]+1) st[y].erase(--st[y].end());
			if(st[y].size()>d[y]) q.push((node){y,*--st[y].end()});
		}
	}
	if(dis[1]!=inf) cout<<dis[1]<<'\n';
	else cout<<"-1\n";
	return 0;
}
