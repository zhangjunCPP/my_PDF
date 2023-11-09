#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
/*
对于当前一个点u 如果已经知道从他出发每条边的时间 最坏情况下就是取第du+1小
然后一直这么走 走到s集合中的点 
无向图：可以从每个点出发跑dij 时间复杂度感觉有点危险啊。。？
80%应该是没问题的
好吧我好像发现这个做法有点问题
对于每个点 荆棘刺的路是确定的？ 但不能删 因为可以走回来 那就变成单向？ 
倒着来？是多源啊
不能贪心的选 样例都过不去 按线段数选？？
直接找最长路也不行
把每条路都列出来排序？
按线段数选也不会证啊 
优先堵直达的 边权从小到大 这些边可以删
倒退 每个点把前du堵了 用第du+1小来更新后面的点 
出口间的边无用 不会从一出口走到另一个 
好像挺对？ 拓补一下？ 无向图拓个P
咋个搞，队列？ 分层吗 多源 层数取max？ 层数又怎么求啊 
无向图。。缩点吗。。成一个DAG可以拓补 但SCC里面的怎么搞 
*/
const int N=2e5+10;
int n,m,k,cnt,head[N],vis[N],d[N],deg[N],vis2[N],dis[N];
int tag[N],ans;
struct node{
	int to,w,next;
}e[N<<1];
struct edge{
	int u,v;
}edg[N<<1];
void add(int u,int v,int w){e[++cnt].to=v,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
priority_queue<PII,vector<PII>,greater<PII> > Q;
void dijkstra(int s){
	while(!Q.empty())Q.pop();
	for(int i=1;i<=n;++i)vis2[i]=0,dis[i]=2e9;
	dis[s]=0,Q.push({0,s});
	while(!Q.empty()){
		int u=Q.top().second;Q.pop();
		if(vis2[u])continue;
		vis2[u]=1;
		for(int i=head[u];i;i=e[i].next){
//			if(tag[i])continue;
			int v=e[i].to;
			if(vis2[v])continue;
			if(dis[v]>dis[u]+e[i].w)dis[v]=dis[u]+e[i].w,Q.push({dis[v],v});
		}
	}
}
bool check(int s,int wt){
	int res=0;
	while(s){
		if(s&1)++res;
		s>>=1;
	}
	return res==wt;
}
int dfs(int u,int fa,int dis){
//	if(now>m){
//		if(!check())return;
//		for(int i=1;i<=m;++i)cout<<tag[i]<<" ";
//		cout<<"\n";
//		dijkstra(1);
//		int res=2e9;
//		for(int i=1;i<=n;++i)
//			if(vis[i])res=min(res,dis[i]);
//		if(res!=2e9)ans=max(ans,res);
//		return;
//	}
//	tag[now]=1,dfs(now+1);
//	tag[now]=0,dfs(now+1);
	tag[u]=1;
	if(vis[u]){
		return dis;
	}
	int res=0;
	for(int s=(1<<deg[u])-1;~s;--s){
		int minn=0;
		if(!check(s,d[u]))continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(v==fa||tag[v])continue;
			if(!((s>>(i-1))&1)){
				int tmp=dfs(v,u,dis+e[i].w);
				if(tmp>0)minn=max(minn,tmp);
			}
		}
		if(minn!=2e9)res=max(res,minn);
	}
	tag[u]=0;
	return res?res:-1;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		int x=read();
		vis[x]=1;
	}
	for(int i=1;i<=n;++i)d[i]=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w),++deg[u],++deg[v],edg[i].u=u,edg[i].v=v;
	}
	for(int i=1;i<=n;++i)
		if(d[i]>=deg[i]){printf("-1\n");return 0;}
	if(n<=15&&m<=15){
		ans=dfs(1,0,0);
		printf("%d\n",ans?ans:-1);
	}else{
		dijkstra(1);
		for(int i=1;i<=n;++i){
			if(vis[i])ans=max(ans,dis[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
7 15 2
4 7
2 0 0 1 0 0 0
1 2 7
1 3 5
1 4 1
3 5 4
4 6 3
3 7 7
4 3 4
7 1 4
5 6 3
2 3 7
7 5 3
4 7 4
6 2 7
2 4 4
6 7 6

5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
