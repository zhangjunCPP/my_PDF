#include<bits/stdc++.h>
#define LL long long
#define PII pair<LL,int>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
const int mod=1e9+7;
int n,m,q,k,id,vis[N],num[N],cnt,head[N<<1];
LL dis[N];
vector<int> pre[N<<1];
struct node{
	int to,next,w;
}e[N<<2];
void add(int u,int v,int w){e[++cnt].to=v,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
priority_queue<PII,vector<PII>,greater<PII> > Q;
void dijkstra(int s){
	while(!Q.empty())Q.pop();
	for(int i=1;i<=n;++i)dis[i]=1e18,vis[i]=0,num[i]=1;
	dis[s]=0ll,num[s]=1,Q.push({0ll,s});
	while(!Q.empty()){
		int u=Q.top().second;Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(vis[v])continue;
			if(dis[v]>dis[u]+1ll*e[i].w){
				num[v]=num[u],dis[v]=dis[u]+1ll*e[i].w,Q.push({dis[v],v});
				pre[v].clear(),pre[v].push_back(u);
			}else if(dis[v]==dis[u]+1ll*e[i].w)num[v]=num[v]+num[u],pre[v].push_back(u);
		}
	}
}
LL dfs(int u,int t){
	if(u==t)return 0;
//	if(deg[u]==1)return dfs(e[head[u]].to,t);
	LL res=0;
//	if(pre[u].size()==1)
//		for(auto v:pre[u])res=(res+dfs(v,t,0))%mod;
//	else
//		for(auto v:pre[u])res=(res+dfs(v,t,1))%mod;
	if(pre[u].size()==1)
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(pre[u][0]==v)continue;
			res=(res+num[v])%mod;
		}
	else
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			res=(res+num[v])%mod;
		}
	int ss=pre[u].size();
	for(int i=0;i<ss;++i)res=(res+dfs(pre[u][i],t))%mod;
	return res;
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	n=read(),m=read(),q=read(),k=read(),id=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	while(q--){
		int s=read(),t=read();
		dijkstra(t);
		if(!vis[s])printf("0\n");
		else if(k==0)printf("%d\n",num[s]);
		else printf("%lld\n",dfs(s,t));
	}
	return 0;
}
