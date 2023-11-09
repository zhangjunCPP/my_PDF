#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int n,a,b,diameter;
int dep[1000005],aff[1000005],dis[1000005],go[1000005][21],mi[1000005];
int cnt[1000005],cnt2[1000005];//20
vector<int> G[1000005];
void dfs(int u,int fa){
	dis[u]=dis[fa]+1;
	go[u][0]=fa;
	for(int i=1;(1<<i)<=dis[u];i++)go[u][i]=go[go[u][i-1]][i-1];
	int mx=0,nxt=0,w=u,wi=0;
	for(int v:G[u])if(v!=fa){
		dfs(v,u);
		if(mx<dep[v]+1)nxt=mx,mx=dep[v]+1,wi=w,w=aff[v];
		else if(nxt<dep[v]+1)nxt=dep[v]+1,wi=w;
	}
	dep[u]=mx,aff[u]=w;
	if(diameter<mx+nxt){
		diameter=mx+nxt;
		a=w,b=wi;
	}
}
int __lca(int u,int v){
	if(dis[u]<dis[v])u^=v^=u^=v;
	for(int i=20;i>=0;i--)if(dis[go[u][i]]>=dis[v])u=go[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)if(go[u][i]!=go[v][i])u=go[u][i],v=go[v][i];
	return go[u][0];
}
int __dis(int u,int v){
	return dis[u]+dis[v]-2*dis[__lca(u,v)];
}
void Freopen(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
int check(){
	int num=0;
	for(int i=1;i<=n;i++)if(G[i].size()==1)++num;
	if(num==2)return 1;
	return 0;
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	mi[0]=1;
	for(int i=1;i<=n;i++)mi[i]=2*mi[i-1]%p;
	dfs(1,0);
	if(diameter&1){
		cnt[0]++;
		cnt2[0]++;
		for(int i=1;i<=n;i++)if(i!=a&&i!=b){
			int x=__dis(i,a),y=__dis(i,b);
			if(x<y)++cnt[diameter-y];
			else ++cnt2[diameter-x];
		}
		int rest=n-cnt[0]-cnt2[0],ans=1ll*(mi[cnt[0]+cnt2[0]]-2+p)%p*mi[rest]%p*diameter%p;
		for(int i=1;i<=diameter/2;i++){
			rest-=cnt[i]+cnt2[i];
			int kind1=1ll*(2ll*mi[cnt[i]+cnt2[i]]%p-2+p)%p*mi[rest]%p;
			ans+=1ll*kind1*(diameter-i)%p;
		}
		ans=(ans+2)%p;
		cout<<ans;
	}
	else{
		int num=1;
		for(int i=1;i<=n;i++)if(__dis(i,a)==diameter)++num;
		if(num==2)printf("%lld",(2ll*mi[n-2]%p*diameter%p+2ll*mi[n-2]%p*(diameter-1)%p)%p);
		else printf("%lld",1ll*mi[n-2]*diameter%p);
	}
}











