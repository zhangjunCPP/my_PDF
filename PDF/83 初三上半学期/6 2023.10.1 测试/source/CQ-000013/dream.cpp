#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int p=1000000007;

int n,m,q,k,type,ans,s,t;
int cnt[2][100005],vis[100005],out[100005],no[100005];ll dis[2][100005];
int head[100005],ver[400005],nxt[400005],weight[400005],num=1;
void add(int u,int v,int w){
	ver[num]=v,weight[num]=w,nxt[num]=head[u],head[u]=num++;
	ver[num]=u,weight[num]=w,nxt[num]=head[v],head[v]=num++;
}
void dijkstra1(int s,ll d[],int cnt[]){
	priority_queue< pair<int,int> > Q;
	for(int i=1;i<=n;i++)vis[i]=0,d[i]=0x3f3f3f3f3f3f3f3f,cnt[i]=0;
	d[s]=0;cnt[s]=1;
	Q.push({0,s});
	while(Q.size()){
		int u=Q.top().second;
		Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u],v=ver[i],w=weight[i];i;i=nxt[i],v=ver[i],w=weight[i]){
			if(d[v]>d[u]+w)
				d[v]=d[u]+w,cnt[v]=cnt[u],Q.push({-d[v],v});
			else if(d[v]==d[u]+w)
				cnt[v]=(cnt[v]+cnt[u])%p;
		}
	}
}
void dijkstra2(int s,ll d[],int cnt[]){
	priority_queue< pair<int,int> > Q;
	for(int i=1;i<=n;i++)vis[i]=0,d[i]=0x3f3f3f3f3f3f3f3f,cnt[i]=0,out[i]=0,no[i]=0;
	d[s]=0;cnt[s]=1;no[s]=1;
	Q.push({0,s});
	while(Q.size()){
		int u=Q.top().second;
		Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(dis[0][u]+d[u]==dis[0][t]&&out[u]>=2)ans=(ans+no[u])%p,no[u]=0;
		for(int i=head[u],v=ver[i],w=weight[i];i;i=nxt[i],v=ver[i],w=weight[i]){
			if(d[v]>d[u]+w)
				d[v]=d[u]+w,cnt[v]=cnt[u],Q.push({-d[v],v}),out[v]=1,no[v]=no[u];//printf("%d = %d\n",v,u);
			else if(d[v]==d[u]+w)
				cnt[v]=(cnt[v]+cnt[u])%p,out[v]++,no[v]=(no[v]+no[u])%p;//printf("%d <- %d\n",v,u);
		}
	}
}
void Freopen(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d%d%d%d",&n,&m,&q,&k,&type);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	while(q--){
		scanf("%d%d",&s,&t);
		if(s==t){
			printf("%d",k^1);
			continue;
		}
		if(k==0){
			dijkstra1(t,dis[1],cnt[1]);
			printf("%d",cnt[1][s]);
		}
		else{
			ans=0;
			dijkstra1(s,dis[0],cnt[0]);
			dijkstra2(t,dis[1],cnt[1]);
			for(int u=1;u<=n;u++)if(u!=t&&dis[0][u]+dis[1][u]==dis[0][t])//u在最短路上 
				for(int i=head[u],v=ver[i],w=weight[i];i;i=nxt[i],v=ver[i],w=weight[i])
					if(dis[0][u]+w+dis[1][v]!=dis[0][t])
						(ans+=1ll*cnt[0][u]*cnt[1][v]%p)%=p;//路线不在最短路上 
			printf("%d",ans);
		}
	}
}
/*
511


*/
