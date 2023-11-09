#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int n,m,Q;

int f[N],cnt;
struct node { int v,w,net; } eg[N<<1];
void add(int uu,int vv,int ww) { eg[++cnt]=(node) { vv,ww,f[uu] }, f[uu]=cnt; }

map< pair<int,int>,int > dis;
priority_queue< pair<int,int> > q;
bool vis[N];
void djstl(int s) {
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) vis[i]=false;
	q.push( make_pair( s,s ) );
	dis[ make_pair( s,s ) ]=-1;
	while(!q.empty()) {
		pair<int,int> uw=q.top(); q.pop();
		int u=uw.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=f[u];i;i=eg[i].net) {
			int v=eg[i].v,w=eg[i].w;
			pair<int,int> vv=make_pair( s,v ),uu=make_pair( s,u );
			if( dis[ uu ] * w < -m ) continue;
			if( !dis.count(vv) || dis[ vv ]>dis[ make_pair(s,u) ]*w ) {
				dis[vv]=dis[ make_pair( s,u ) ]*w;
				q.push( make_pair( dis[ vv ],v ) );
			}
		}
	}
}/*
void floyd() {
	for(int i=1;i<=n;i++) dis[make_pair(i,i)]=1;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int jj=f[i];jj;jj=eg[jj].net) {
				int j=eg[jj].v;
				pair<int,int> ik=make_pair(i,k);
				pair<int,int> kj=make_pair(k,j);
				if( !dis.count(ik) || !dis.count(kj) ) continue;
				pair<int,int> ij=make_pair(i,j);
				if( dis[ik]*dis[kj]*eg[i].w>m ) continue;
				if( !dis.count(ij) || dis[ij]<dis[kj]*dis[ik]*eg[i].w )
					dis[ij]=dis[kj]*dis[ik]*eg[i].w;
			}
		}
	}
}*/
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=2;i<=m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		add(u,v,i); add(v,u,i);
	}
	for(int i=1;i<=n;i++) djstl(i);
//	floyd();
	while(Q--) {
		int u,v; scanf("%d%d",&u,&v);
		int ans=10;
		if( dis.count( make_pair(u,v) ) ) ans=dis[ make_pair(u,v) ];
		printf("%d\n",ans==10 ? -1 : -ans);
	}
	return 0;
}
