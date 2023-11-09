/*
这不所有点的出边最大值吗？？？
有这么简单？？？ 
有特殊的情况，例如三元环，好像就这一个特殊情况。
特判即可。 
*/
#include<bits/stdc++.h>
//#define int long long
const int N=1e6+10,M=2e6+10,inf=1e9+7;
void Freopen();
void Ftest();
int rd();
using namespace std;
int n,m,tot,f,len;
int out[N],vis[N];
int head[N],to[M],nxt[M];
void add( int u, int v) {
	to[++len]=v;
	nxt[len]=head[u];
	head[u]=len;
}
void dfs( int u, int fu, int len) {
	if (vis[u]) {
		if (len==3) f=1;
		return ;
	}
	vis[u]=1;
	for ( int i=head[u]; i; i=nxt[i]) {
		int v=to[i];
		if (v==fu) continue ;
		dfs (v,u,len+1);
	}
}
void solve() {
	n=rd(),m=rd();
	f=0;
	for ( int i=1; i<=n; i++) out[i]=0,vis[i]=0,head[i]=0;
	for ( int i=1,x,y; i<=m; i++) {
		x=rd(),y=rd();
		add(x,y),add(y,x);
		out[x]++,out[y]++;
	}
	dfs(1,0,0);
	int ans=0;
	for ( int i=1; i<=n; i++) ans=max(ans,out[i]);
	if (f) ans=max(ans,3);
	printf("%d\n",ans);
}
signed main() {
	Freopen();
//	Ftest();
	for ( int t=rd(); t; t--) solve();
}
void Freopen() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
void Ftest() {
//	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int rd() {
	int x; scanf("%d",&x);
	return x;
}


