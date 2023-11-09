#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=2e9+1;
int n,m,k,d[N];
bool flag[N],f;
int head[N],cnt;
struct node{
	int nxt,v,val;
}tree[N<<1];
void add(int u,int v,int w){
	if(flag[u]) u=n+1;
	if(flag[v]) v=n+1;
	if(u==v) return;
	tree[++cnt]={head[u],v,w},head[u]=cnt;
	tree[++cnt]={head[v],u,w},head[v]=cnt;
}
queue<int> q;
int dis[N];
bool vis[N];
void dij(int st){
	for(int i=1;i<=n;++i) dis[i]=INF;
	d[st]=0,q.push(st);
	while(q.size()){
		int x=q.front(); q.pop(),vis[x]=false;
		for(int i=head[x],y;i;i=tree[i].nxt) if(dis[y=tree[i].v]>dis[x]+tree[i].val){ dis[y]=dis[x]+tree[i].val; if(!vis[y]) vis[y]=true,q.push(y); }
	}
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=k;++i) scanf("%d",&x),flag[x]=true;
	for(int i=1;i<=n;++i) scanf("%d",&d[i]),f|=(d[i]>0);
	for(int i=1,u,v,w;i<=m;++i) scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	//if(!f){//15pts
		dij(1);
		if(dis[n+1]==INF) puts("-1");
		else printf("%d\n",dis[n+1]);
		return 0;
	//}

	return 0;
}
