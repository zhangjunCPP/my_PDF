//完成时间 15：11 
#include<bits/stdc++.h> 
using namespace std;
int n,m,q;
int k[200005],d[200005];
int head[200005],ver[400005],wei[400005],nxt[400005],num=1;
void add(int u,int v,int w){ver[num]=v,wei[num]=w,nxt[num]=head[u],head[u]=num++;}

int vis[200005];
priority_queue<int> s[200005];
void dijkstra(){
	priority_queue< pair<int,int> > Q;
	for(int i=1;i<=q;i++)s[k[i]].push(0),d[k[i]]=0,Q.push({0,k[i]});
	while(Q.size()){
		int u=Q.top().second;Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		//printf("%d %d\n",u,s[u].top());
		for(int i=head[u],v=ver[i],w=wei[i];i;i=nxt[i],v=ver[i],w=wei[i]){
			//printf("%d -> %d  %d\n",u,v,s[u].top()+w);
			if(s[v].size()<=d[v])s[v].push(s[u].top()+w);
			else if(s[v].top()>s[u].top()+w)s[v].pop(),s[v].push(s[u].top()+w);
			if(s[v].size()==d[v]+1)Q.push({-s[v].top(),v});
		}
	}
}
void Freopen(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dijkstra();
	printf("%d\n",s[1].size()<d[1]?-1:s[1].top());
}
