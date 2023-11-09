#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int p=998244353;
int fac[1000005],inv[1000005],pinv[1000005];
int C(int n,int m){return 1ll*fac[n]*pinv[m]%p*pinv[n-m]%p;}
int Catalan(int n){return 1ll*C(2*n,n)*inv[n+1]%p;}
struct Node{
	int l,lt,r,rt,mul,op;
	Node operator + (const Node &x){
		if(op==-1)return x;
		else if(x.op==-1)return (*this);
		else{
			int ans=1ll*mul*x.mul%p;
			if(!op&&!x.op){
				if(rt==x.lt)ans=1ll*ans*Catalan(r+x.l)%p;
				else ans=1ll*ans*Catalan(r)%p*Catalan(x.l)%p;
			}
			else if(!op){if(rt!=x.lt)ans=1ll*ans*Catalan(r)%p;}
			else if(!x.op){if(x.lt!=rt)ans=1ll*ans*Catalan(x.l)%p;}
			return Node{
				l+(op&&lt==x.lt)*x.l,
				lt,
				x.r+(x.op&&rt==x.rt)*r,
				x.rt,
				ans,
				op&&x.op&&x.lt==lt
			};
		}
	}
};

int n,m,q,type;
int dis[100005],go[100005][20],s[100005];
vector<int> G[100005];
Node f[100005][20],g[100005][20];//17
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=pinv[0]=pinv[1]=1;
	for(int i=2;i<=1000000;i++)
		fac[i]=1ll*fac[i-1]*i%p,
		inv[i]=1ll*(p-p/i)*inv[p%i]%p,
		pinv[i]=1ll*pinv[i-1]*inv[i]%p;
}
void dfs(int u,int fa){
	go[u][0]=fa;
	f[u][0]=g[u][0]={1,s[u],1,s[u],1,1};
	dis[u]=dis[fa]+1;
	for(int i=1;(1<<i)<=dis[u];i++){
		go[u][i]=go[go[u][i-1]][i-1];
		f[u][i]=f[u][i-1]+f[go[u][i-1]][i-1];
		g[u][i]=g[go[u][i-1]][i-1]+g[u][i-1];
	}
	for(int v:G[u])if(v!=fa)
		dfs(v,u);
}
Node ask(int u,int v){
	Node l={0,0,0,0,0,-1},r={0,0,0,0,0,-1};
	if(dis[u]<dis[v])swap(u,v);
	for(int i=17;i>=0;i--)if(dis[go[u][i]]>=dis[v]){
		l=l+f[u][i];
		u=go[u][i];
	}
	if(u==v)return l+f[u][0];
	for(int i=17;i>=0;i--)if(go[u][i]!=go[v][i]){
		l=l+f[u][i],r=g[v][i]+r;
		u=go[u][i],v=go[v][i];
	}
	return l+f[u][0]+g[v][1]+r;
}
int lca(int u,int v){
	if(dis[u]<dis[v])swap(u,v);
	for(int i=17;i>=0;i--)if(dis[go[u][i]]>=dis[v])u=go[u][i];
	if(u==v)return u;
	for(int i=17;i>=0;i--)if(go[u][i]!=go[v][i])u=go[u][i],v=go[v][i];
	return go[u][0];
}
int dist(int u,int v){
	return dis[u]+dis[v]-2*dis[lca(u,v)];
}
void Freopen(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
}
int main(){
	Freopen();
	init();
	scanf("%d%d%d",&n,&m,&type);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		Node res=ask(s,t);
		if(res.op)printf("%lld\n",1ll*C(m,2*dist(s,t)+2)*Catalan(res.l)%p);
		else printf("%lld\n",1ll*C(m,2*dist(s,t)+2)*res.mul%p*Catalan(res.l)%p*Catalan(res.r)%p);
	}
}
