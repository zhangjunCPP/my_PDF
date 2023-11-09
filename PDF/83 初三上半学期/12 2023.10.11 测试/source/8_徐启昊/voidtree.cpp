#include<bits/stdc++.h>
#define Genshin_Impact_starts ios::sync_with_stdio ( false )
#define int long long
void Freopen() {
	freopen("voidtree.in", "r", stdin);
	freopen("voidtree.out", "w", stdout);
}
void Ft() {
	freopen("voidtree.in", "r", stdin);
	freopen("voidtree.out", "w", stdout);
}
using namespace std;
const int N=1e6+100, inf=1e9+10;
int n, id, op, q, ans, tt;
inline void decode( int &l, int &r, int &k, int lstans, int testop) {
	lstans%=19260817;
	if (testop) {
		l^=lstans; l=(l%n+n)%n+1;
		r^=lstans; r=(r%n+n)%n+1;
		if (l>r) swap(l,r);
		k^=lstans;
		k=(k%min(r-l+1ll, 100ll))+1;
	}
}
struct node {
	int u, v, w;	
} e[N], ed[N];
int p[N], fa[N];
int gf( int x) {
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
bool cmp( node a, node b) {
	return a.w>b.w;
}
map<pair< int, int>, int>vis;
vector< pair< int, int> >G[N];
void dfs( int rt, int u, int fu, int w) {
	if (rt!=u&&!vis.count({rt,u})) e[++tt]={rt,u,w},
		vis[{rt,u}]=vis[{u,rt}]=1;
	for ( auto i:G[u]) {
		int v=i.first, val=i.second;
		if (v==fu) continue ;
		dfs(rt, v, u, w+val);
	}
}
signed main() {
	Freopen();
	cin>>id;
	cin>>op>>n;
	for ( int i=1; i<n; i++) 
		cin>>e[i].u>>e[i].v>>e[i].w,
		vis[{e[i].u,e[i].v}]=vis[{e[i].v,e[i].u}]=1,
		G[e[i].u].push_back({e[i].v,e[i].w}),
		G[e[i].v].push_back({e[i].u,e[i].w});
	tt=n-1;
	dfs(1, 1, 0, 0);
	for ( int i=1; i<=n; i++) cin>>p[i];
	cin>>q;
	while (q--) {
		int l, r, k;
		cin>>l>>r>>k;
		decode(l, r, k, ans, op);
		ans=0;
		int tot=0;
		for ( int i=1; i<=tt; i++) {
			int f1=0, f2=0;
			for ( int j=l; j<=r; j++) {
				if (e[i].u==p[j]) f1=1;
				if (e[i].v==p[j]) f2=1;
			}
			if (f1&&f2) ed[++tot]=e[i];
		}
		for ( int i=1; i<=n; i++) fa[i]=i;
		sort(ed+1, ed+1+tot, cmp);
		int cnt=0;
		if (k-1==0) {
			cout<<0<<endl;
			continue ;
		}
		for ( int i=1; i<=tot; i++) {
			int u=ed[i].u, v=ed[i].v, w=ed[i].w;
			u=gf(u), v=gf(v);
			if (u==v) continue ;
			cnt++;
			ans+=w;
			fa[v]=u;
			if (cnt==k-1) break ;
		}
		cout<<ans<<endl;
	}
}
/*
0
0 8
2 1 168841147
3 2 185715402
4 3 225620062
5 2 229186192
6 1 56387677
7 1 912381225
8 6 897978762
6 8 4 1 3 2 5 7
10
1 4 1
3 8 4
1 3 2
2 8 3
3 4 1
1 5 5
1 6 1
3 7 2
3 6 4
1 4 3


0
1721744028
1534543050
2446924275
0
1534543050
0
640521656
580176611
1534543050

*/
