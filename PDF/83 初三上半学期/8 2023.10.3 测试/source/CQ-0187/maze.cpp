#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
const int N=2e5+10;
struct node{
	int id,val;
	bool operator<(const node &other)const{
		return val>other.val;
	}
};
int s[N],vis[N],d[N],dis[N];
struct Node{
	int to,nxt,w;
}e[N<<1];
int head[N],cnt;
void add(int u,int v,int w){
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)dis[i]=inf;
	priority_queue<node>q;
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
		dis[s[i]]=0;q.push({s[i],0});
	}
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1;i<=k;i++)d[s[i]]=0;
	for(int i=1;i<=m;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	while(!q.empty()){
		int x=q.top().id,val=q.top().val;q.pop();
		if(d[x]>0){d[x]--;continue;}
		if(vis[x])continue;
		dis[x]=val;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[x]+w<dis[v])
			q.push({v,dis[x]+w});
		}
	}
	if(dis[1]==inf)printf("-1");
	else printf("%d",dis[1]);
	return 0;
}
