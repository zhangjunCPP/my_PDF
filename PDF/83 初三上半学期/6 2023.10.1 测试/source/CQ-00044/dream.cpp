#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
int n,m,q,k;
struct E_{int v,w;};
vector<E_>G[100010];
auto dijkstra(int s){
	vector<ll>dis(n+5,1e18),cnt(n+5);
	vector<int>vis(n+5);
	priority_queue<pair<int,int>>q;
	q.emplace(dis[s]=0,s);cnt[s]=1;
	for(int u;!q.empty();){
		u=q.top().second,q.pop();
		if(vis[u]++)continue;
		for(auto e:G[u]){
			ll x=dis[u]+e.w;
			if(dis[e.v]>x)dis[e.v]=x,cnt[e.v]=cnt[u],q.emplace(-dis[e.v],e.v);
			else if(dis[e.v]==x)(cnt[e.v]+=cnt[u])%=mod;
		}
	}return make_pair(dis,cnt);
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d%d%d%*d",&n,&m,&q,&k);
	for(int i=1,u,v,w;i<=m;i++)
	scanf("%d%d%d",&u,&v,&w),G[u].push_back({v,w}),G[v].push_back({u,w});
	for(int s,t;q--;){
		cin>>s>>t;
		vector<ll>ds,dt,cs,ct,cms(n+5);//cnt miss
		tie(ds,cs)=dijkstra(s),tie(dt,ct)=dijkstra(t);
		ll dis=ds[t],ans=0;
		if(!k){if(dis>1e17)puts("0");else cout<<cs[t]<<endl;continue;}
		if(dis>1e17||(G[s].size()==1&&G[s][0].v==t)){puts("0");continue;}
		cms[s]=1;vector<int>a(n);iota(begin(a),end(a),1);sort(begin(a),end(a),[&](int x,int y){return ds[x]<ds[y];});
		for(int u:a){
			if(ct[u]!=1||ds[u]+dt[u]!=dis)cms[u]=0;
			for(auto e:G[u])if(ds[u]+e.w==ds[e.v])(cms[e.v]+=cms[u])%=mod;
		}ans=cs[t]-cms[t];
		for(int u=1;u<=n;u++)if(u!=t&&ds[u]+dt[u]==dis)
		for(auto e:G[u])if(ds[u]+e.w+dt[e.v]!=dis)(ans+=cs[u]%mod*ct[e.v])%=mod;
		cout<<(ans%mod+mod)%mod<<endl;
	}
	return 0;
}
