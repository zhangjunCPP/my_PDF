#include<bits/stdc++.h>
#define int long long
const int N=1e6,inf=1e9+10;
void Freopen() {
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
}
using namespace std;
struct node {
	int v,w;
} ;
struct edge {
	int u,v,w;
} e[N];
queue<int>q;
int dis1[N],vis[N],cnt1[N];
vector<pair< int , int > >G[N];
vector< int >E[N];
int n,m,Q,k,id;
void Spfa1( int s) {
	memset(dis1,127, sizeof dis1);
	memset(vis,0, sizeof vis);
	memset(cnt1,0, sizeof cnt1);
	dis1[s]=0;
	q.push(s);
	cnt1[s]=1;
	while (q.size()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for ( auto i:G[u]) {
			int v=i.first,w=i.second;
			if (dis1[v]>dis1[u]+w) {
				dis1[v]=dis1[u]+w;
				cnt1[v]=cnt1[u];
				if (!vis[v]) vis[v]=1,q.push(v);
			}
			else if (dis1[v]==dis1[u]+w) cnt1[v]+=cnt1[u];
		}
	}
}
int dis2[N],cnt2[N];
void Spfa2( int s) {
	memset(dis2,127, sizeof dis2);
	memset(vis,0, sizeof vis);
	memset(cnt2,0, sizeof cnt2);
	dis2[s]=0;
	q.push(s);
	cnt2[s]=1;
	while (q.size()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for ( auto i:G[u]) {
			int v=i.first,w=i.second;
			if (dis2[v]>dis2[u]+w) {
				dis2[v]=dis2[u]+w;
				cnt2[v]=cnt2[u];
				if (!vis[v]) vis[v]=1,q.push(v);
			}
			else if (dis2[v]==dis2[u]+w) cnt2[v]+=cnt2[u];
		}
	}
}
int dis3[N],cnt3[N];
void Spfa3( int s) {
	memset(dis3,127, sizeof dis3);
	memset(vis,0, sizeof vis);
	memset(cnt3,0, sizeof cnt3);
	dis3[s]=0;
	q.push(s);
	cnt3[s]=1;
	while (q.size()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for ( auto i:G[u]) {
			int v=i.first,w=i.second;
			if (dis3[v]>dis3[u]+w) {
				dis3[v]=dis3[u]+w;
				cnt3[v]=cnt3[u];
				if (!vis[v]) vis[v]=1,q.push(v);
			}
			else if (dis3[v]==dis3[u]+w) cnt3[v]+=cnt3[u];
		}
	}
}
int tot,a[N];
vector< int >way[N];
vector< int >sb;
map<vector<int>,int>key;
void dfs( int u, int len, int t) {
	a[len]=u;
	if (u==t) {
		++tot;
		for ( int i=1; i<=len; i++) sb.push_back(a[i]);
		if(!key.count(sb)) for ( int i=1;i<=len;i++)way[tot].push_back(a[i]);
		return ;
	}
	for ( auto v:E[u]) {
		if (vis[v]) continue;
		vis[v]=1;
		dfs(v,len+1,t);
		vis[v]=0;
	}
}
signed main() {
	Freopen();
	cin>>n>>m>>Q>>k>>id;
	for ( int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i]={u,v,w};
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	while (Q--) {
		int s,t;
		scanf("%lld%lld",&s,&t);
		if (!k) {
			Spfa1(s);
			cout<<cnt1[t]<<endl;
		}
		else {
			int ans=0;
			for ( int i=1; i<=tot; i++) way[i].clear();
			tot=0;
			Spfa1(s);
			Spfa2(t);
			for ( int i=1; i<=m; i++) {
				int u=e[i].u,v=e[i].v,w=e[i].w;
				if (dis1[u]+w+dis2[v]==dis1[t]) E[u].push_back(v);
				else if (dis1[v]+w+dis2[u]==dis1[t]) E[v].push_back(u);
			}
			memset(vis,0, sizeof vis);
			vis[s]=1;
			dfs(s,1,t);
			
			
			for ( int i=1; i<=tot; i++) {
				for ( int j=0; j<way[i].size()-1; j++) {
					int u=way[i][j];
					for ( auto p:G[u]) {
						int v=p.first;
						if (v!=way[i][j+1]) Spfa3(v),ans+=cnt3[t];
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}

