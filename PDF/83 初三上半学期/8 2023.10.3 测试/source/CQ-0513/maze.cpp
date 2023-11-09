/*
d[u]=0
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10,INF=INT_MAX;
ll dis[N];
bool vis[N];
ll cnt,first[N];
struct Edge{
	ll u,v,w,nex;
}a[N<<1];
void add(ll u,ll v,ll w){
	a[++cnt]={u,v,w,first[u]};
	first[u]=cnt;
}
struct node{
	ll id,x;
	bool operator < (const node &b)const{
		return x>b.x;
	}
};
priority_queue<node>q;
ll n,m,k,i,x,flag,y,z,ans=INF;
void dijkstra(ll s){
	for(i=0;i<=n;++i)dis[i]=INF;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		ll u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(ll i=first[u];i;i=a[i].nex){
			ll v=a[i].v,w=a[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
bool ed[N];
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=k;++i)scanf("%lld",&x),ed[x]=1;
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		if(x)flag=1;
	}
	if(flag)return puts("-1"),0;
	for(i=1;i<=m;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	} 
	dijkstra(1);
	for(i=1;i<=n;++i)if(ed[i])ans=min(ans,dis[i]);
	printf("%lld",ans<dis[0]?ans:-1);
	return 0;
}
/*
9 8 1
9
0 0 0 0 0 0 0 0 0
1 2 1
2 3 2
3 4 4
4 5 6
2 7 3
7 6 5
5 6 7
5 8 8
*/
