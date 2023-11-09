#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,k;
ll d[N],val[N];
ll vis[N],in[N];
struct EDGE{ll v,nex,w;}e[N];
ll head[N],cnt;
void add(ll u,ll v,ll w){e[++cnt].v=v;e[cnt].w=w;e[cnt].nex=head[u];head[u]=cnt;}
vector<ll> a[N];
void bfs(){
	queue<ll> q;
	for(ll i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=head[x];i;i=e[i].nex){
			ll v=e[i].v,w=e[i].w;
			a[v].push_back(val[x]+w);
			if(!(--in[v])){
				if((ll)a[v].size()>d[v]){
					sort(a[v].begin(),a[v].end());
					val[v]=a[v][d[v]];
					q.push(v);
				}
			}
		}
	}
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=k;i++){
		ll x;scanf("%lld",&x);
		vis[x]=1;
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&d[i]);
	for(ll i=1;i<=m;i++){
		ll x,y,w;
		scanf("%lld%lld%lld",&x,&y,&w);
		if(vis[x]&&vis[y]) continue;
		if(vis[y]) swap(x,y);
		else if(!vis[x]&&x<y) swap(x,y);
		add(x,y,w);in[y]++;
	}
	bfs();
	printf("%lld",val[1]);
	return 0;
}

