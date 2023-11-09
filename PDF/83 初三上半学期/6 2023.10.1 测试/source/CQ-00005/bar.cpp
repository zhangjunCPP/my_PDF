#include<bits/stdc++.h>
#define int long long
const int N=60,inf=1e9+10;
void Freopen() {
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
}
using namespace std;
int n,m,k;
struct edge {
	int v,w;	
} ;
int cnt=0;
vector<edge>G[N];
struct node {
	int val,len;
	int way[N*N];
} sb[N];
int vis[N],a[N],val[N];
int cmp(node a,node b) {
	if (a.val==b.val) {
		for ( int i=1; ; i++) 
			if (a.way[i]==b.way[i]) continue ;
			else return a.way[i]<b.way[i];
	}
	return a.val<b.val;
}
void dfs( int u, int len, int s) {
	a[len]=u;
	if (u==n) {
		int tot=0;
		sb[++cnt].val=s;
		sb[cnt].len=len;
		for ( int i=1; i<=len; i++) sb[cnt].way[++tot]=a[i];
		return ;
	}
	for ( auto i:G[u]) {
		int v=i.v,w=i.w;
		if (vis[v]) continue;
		vis[v]=1;
		dfs(v,len+1,s+w);
		vis[v]=0;
	}
}
signed main() {
	Freopen();
	cin>>n>>m>>k;
	for ( int i=1,u,v,w; i<=m; i++) {
		cin>>u>>v>>w;
		G[u].push_back( { v,w } );
	}
	vis[1]=1;
	dfs(1,1,0);
	sort(sb+1,sb+1+cnt,cmp);
	if (sb[k].len==0) return cout<<-1,0;
	cout<<sb[k].len<<endl;
	for ( int i=1; sb[k].way[i]; i++)
		cout<<sb[k].way[i]<<" ";
}
