#include<bits/stdc++.h>
//#define int long long
const int N=2e5+10,M=2e5+10,inf=1e9+7;
void Freopen();
void Ftest();
using namespace std;
int n,m,k;
struct node {
	int v,val;
	bool operator < ( const node &rhs) const {
		return val>rhs.val;
	}
} ;
priority_queue<node>q;
int len,ans;
int to[2*N],w[2*N],nxt[2*N],head[N],visb[300][300];
int t[N],d[N];
void add( int x, int y, int z) {
	to[++len]=y,w[len]=z,nxt[len]=head[x];
	head[x]=len;
}
int dis[N],vis[N];
set<pair< int , int > >ss;
map<pair< int , int >, int >V;

void dij( int s) {
	for ( int i=1; i<=n; i++) dis[i]=inf;
	memset(vis,0, sizeof vis);
	dis[s]=0;
	q.push({s,0});
	while (q.size()) {
		int u=q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for ( int i=head[u]; i; i=nxt[i]) {
			if (V.count({u,i})) continue;
			if (visb[u][i]) continue;
			int v=to[i];
			if (dis[v]>dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
				q.push({v,dis[v]});
			}
		}
	}
}
void dfs( int u, int k, int last) {
	if (u==n+1) {
		dij(1);
		int res=inf;
		for ( int i=1; i<=k; i++) res=min(res,dis[t[i]]);
		if (res==inf) {

			cout<<-1,exit(0);		
		}
		ans=max(ans,res);
		memset(visb,0, sizeof visb);
		return ;
	}
	if (k==d[u]+1) {
		dfs(u+1,1,head[u+1]);
		return ;
	}
	for ( int i=last; i; i=nxt[i]) {
		visb[u][i]=1;
		dfs(u,k+1,nxt[i]);
		visb[u][i]=0;
	}
}
void Solve() {
	int f=1,f2=1;
	for ( int i=1; i<=n; i++) {
		if (d[i]!=0) f=0;
		if (d[i]>1) f2=0;
	}
	if (f) {
		dij(1);
		int ans=inf;
		for ( int i=1; i<=k; i++) ans=min(ans,dis[t[i]]);
		if (ans==inf) cout<<-1;
		else cout<<ans<<endl;
		return ;
	}
	if (f2) {
		for ( int u=1; u<=n; u++) {
			ss.clear();
			for ( int i=head[u]; i; i=nxt[i]) ss.insert({w[i],i});
			int i=ss.begin()->second;
			V[{u,i}]=1;
		}
		dij(1);
		int ans=inf;
		for ( int i=1; i<=k; i++) ans=min(ans,dis[t[i]]);
		if (ans==inf) cout<<-1;
		else cout<<ans<<endl;
	}
	dfs(1,1,head[1]);
	cout<<ans;
	return ;
}
signed main() {
	Freopen();
	cin>>n>>m>>k;
	for ( int i=1; i<=k; i++) scanf("%d",&t[i]);
	for ( int i=1; i<=n; i++) scanf("%d",&d[i]);
	for ( int i=1,u,v,w; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
//	for ( int i=head[1];i;i=nxt[i]) cout<<1<<" "<<to[i]<<endl;
	Solve();
}
void Freopen() {
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
void Ftest() {
	freopen(".txt","r",stdin);
	freopen(".txt","w",stdout);
}
/*
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

6
*/

