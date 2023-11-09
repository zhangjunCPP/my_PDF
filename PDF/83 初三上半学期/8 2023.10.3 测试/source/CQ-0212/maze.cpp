#include<stdio.h>
#include<stdlib.h>
#include<queue>

#define int long long
const int N=2e5+5,inf=2e9;
struct dy{
	int v,w,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v,int w){
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int n,m,k,a[N],dis[N];
bool f[N],kf[N];
struct dy1{
	int x,v;
	bool operator<(const dy1 y)const{
		return v>y.v;
	}
};
void dij(){
	std::priority_queue<dy1> q;
	for(int i=1;i<=n;i++) dis[i]=inf,f[i]=0;
	for(int i=1;i<=n;i++) if(kf[i]) {
		dis[i]=0;q.push({i,0});
	}
	while(!q.empty())
	{
		int u=q.top().x;q.pop();
		if(!f[u])
		{
			f[u]=1;
			for(int i=head[u];i;i=edge[i].next)
			{
				int v=edge[i].v,w=edge[i].w;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push({v,dis[v]});
				}
			}
		}
	}
}

struct dy2{
	int x,v;
	bool operator<(const dy2 y)const{
		return v+dis[x]>y.v+dis[y.x];
	}
};
bool vis[N];
void bfs(){
	std::priority_queue<dy2> q;
	q.push({1,0});
	while(!q.empty())
	{
		dy2 u=q.top();q.pop();
		vis[u.x]=1;
//		printf(":%d\n",u.x);
		if(kf[u.x])
		{
			if(u.v>=inf) puts("-1");
			else printf("%lld\n",u.v);
			std::exit(0);
		}
		std::priority_queue<dy2> qq;
		for(int i=head[u.x];i;i=edge[i].next)
		{
			int v=edge[i].v,w=edge[i].w;
//			printf("-::%d\n",v);
			if(!vis[v])qq.push({v,u.v+w});
		}
		for(int i=1;i<=a[u.x]&&!qq.empty();i++){
//			dis[qq.top().x]=inf;
//		printf("--::%d %d\n",qq.top().x,qq.top().v+dis[qq.top().x]);
		qq.pop();
		}
		while(!qq.empty()) {q.push(qq.top());
//				printf("::%d %d\n",qq.top().x,qq.top().v+dis[qq.top().x]);
		qq.pop();
		}
	} 
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,x;i<=k;i++)
	{
		scanf("%lld",&x);
		kf[x]=1;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(m--)
	{
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
//	for(int i=1;i<=k;i++) dij(1);
	dij();
	bfs();
	puts("-1");
//	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
} 
