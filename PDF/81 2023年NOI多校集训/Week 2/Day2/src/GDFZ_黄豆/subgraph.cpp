#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define pi pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define mem(arr,val) memset((arr),(val),sizeof(arr))
using namespace std;

typedef long long ll;
const int MAXN=1e6+5;const ll INF=1e18;
int n,m,deg[MAXN];ll N,M,B,f[MAXN];
int tot=0,head[MAXN];
struct Edge{
	int to,nxt;Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){}
}edge[MAXN<<1];
inline void Add(int u,int v){edge[++tot]=Edge(v,head[u]);head[u]=tot;}

int pre[MAXN],nxt[MAXN];
queue<int>q;bool inq[MAXN];
inline bool topo(int k){
	bool flag=false;
	for(int i=nxt[0];i<=n;i=nxt[i])if(deg[i]<k){q.push(i);inq[i]=flag=true;}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(!inq[v]&&--deg[v]<k){q.push(v);inq[v]=true;}
		}
	}
	return flag;
}
int nG,mG,bG;bool vis[MAXN];
void dfs(int u){
	nG++;vis[u]=true;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(inq[v])bG++;
		else{
			mG++;
			if(!vis[v])dfs(v);
		}
	}
}
inline ll solve(){
	mem(vis,false);
	ll res=-INF;
	for(int i=nxt[0];i<=n;i=nxt[i])if(!vis[i]){
		if(inq[i]){nxt[pre[i]]=nxt[i];pre[nxt[i]]=pre[i];continue;}
		nG=mG=bG=0;
		dfs(i);mG>>=1;
		res=max(res,M*mG-N*nG+B*bG);
	}
	return res;
}
int main(){
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	scanf("%d%d%lld%lld%lld",&n,&m,&M,&N,&B);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);Add(u,v);Add(v,u);deg[u]++;deg[v]++;
	}
	for(int i=0;i<=n;i++){pre[i]=i-1;nxt[i]=i+1;}
	int mx=0;for(int i=1;i<=n;i++)mx=max(mx,deg[i]);
	for(int i=1;i<=mx;i++){
		if(!topo(i)){f[mx=i]=-INF;break;}
		f[i]=solve();
	}
	ll maxn=-INF;
	for(int i=1;i<=mx;i++)maxn=max(maxn,f[i]);
	for(int i=mx;i>=1;i--)if(f[i]==maxn){
		printf("%d %lld\n",i,maxn);
		break;
	}
	return 0;
}
