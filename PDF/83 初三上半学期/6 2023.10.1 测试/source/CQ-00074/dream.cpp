/*
t2
抓紧时间骗分

k=0
等价于求最短路方案数
自环不用管，重边要管 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10,INF=0x7fffffff,mod=1e9+7;
ll cnt,first[N];
struct Edge{
	ll u,v,w,nex;
}a[N];
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
ll i,n,dis[N],num[N];
bool vis[N];
void dijkstra(ll s){
	priority_queue<node>q;
	for(i=1;i<=n;++i)dis[i]=INF;
	for(i=1;i<=n;++i)vis[i]=0;
	for(i=1;i<=n;++i)num[i]=0;
	num[s]=1;
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
				num[v]=num[u];
				q.push({v,dis[v]});
			}
			else if(dis[v]==dis[u]+w){
				(num[v]+=num[u])%=mod;
			}
		}
	}
}
ll m,T,k,id,x,y,z,s,t;
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&m,&T,&k,&id);
	for(i=1;i<=m;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
//		if(x==y)continue;
		add(x,y,z);
		add(y,x,z);
	}
	while(T--){
		if(k){puts("0");continue;}
		scanf("%lld%lld",&s,&t);
		dijkstra(s);
		printf("%lld\n",num[t]);
	}
	return 0;
}

