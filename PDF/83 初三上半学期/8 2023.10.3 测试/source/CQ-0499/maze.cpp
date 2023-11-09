#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,m,k;
ll a[N];
ll vis[N];
vector<pair<ll,ll>>e[N],g[N];

ll dis[N],vvv[N];
void dij(){
	For(i,2,n)dis[i]=1e18;
	priority_queue<pair<ll,ll>>q;
	q.push({0,1});
	while(q.size()){
		ll x=q.top().second;
		q.pop();
		if(vvv[x])continue;
		vvv[x]=1;
		for(auto i:g[x]){
			ll y=i.first,z=i.second;
			if(dis[x]+z<dis[y]){
				dis[y]=dis[x]+z;
				q.push({-dis[y],y});
			}
		}
	}
	ll ans=1e18;
	For(i,1,n){
		if(vis[i]){
			ans=min(ans,dis[i]);
		}
	}
	if(ans==1e18){
		printf("-1");
	}else{
		printf("%lld",ans);
	}
}

bool cmp(pair<ll,ll>a,pair<ll,ll>b){
	if(vis[a.first]!=vis[b.first])return vis[a.first]>vis[b.first];
	return a.second<b.second;
}

void mian(){
	
	scanf("%lld%lld%lld",&n,&m,&k);
	For(i,1,k){
		ll x;
		scanf("%lld",&x);
		vis[x]=1;
	}
	For(i,1,n){
		scanf("%lld",&a[i]);
	}
	For(i,1,m){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		e[x].pb({y,z}),e[y].pb({x,z});
	}
	For(x,1,n){
		sort(e[x].begin(),e[x].end(),cmp);
		for(auto i:e[x]){
			ll y=i.first,z=i.second;
			if(a[x])--a[x];
			else g[x].pb({y,z});
		}
	}
	dij();
	
}

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
