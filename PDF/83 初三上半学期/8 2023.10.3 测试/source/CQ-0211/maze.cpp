#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
const int inf=0x3f3f3f3f;
int n,m,k;
int s[N],d[N];
int dis[N];
bool vip[N],fbi;
#define ppt pair<int,int>
#define mmp make_pair
vector<ppt> eg[N];
void add(int u,int v,int w) {
	eg[u].push_back( mmp(v,w) );
	eg[v].push_back( mmp(u,w) );
} 

int dso[N];
bool vit[N];
void djstl() {
	priority_queue< ppt,vector<ppt>,greater<ppt> > q;
	memset(dso,0x3f,sizeof(dso));
	memset(vit,false,sizeof(vit));
	q.push( mmp(0,1) ); dso[1]=0;
	while(!q.empty()) {
		int u=q.top().second; q.pop();
		if(vit[u]) continue;
		vit[u]=true;
		for(int i=0;i<(int)eg[u].size();i++) {
			int v=eg[u][i].first, w=eg[u][i].second;
			if( dso[v]>dso[u]+w ) {
				dso[v]=dso[u]+w;
				q.push( mmp(dso[v],v) );
			}
		}
	}
}

queue<int> q;
vector<int> blt[N];
#define lb lower_bound
#define be(i) blt[i].begin()
#define ed(i) blt[i].end()
inline int read() {
	int x=0; bool f=false; char ch=getchar();
	while( ch<'0' || ch>'9' ) { if(ch=='-') f=true; ch=getchar(); }
	while( ch>='0' && ch<='9' ) { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return f ? -x : x;
}
signed main() {
//	freopen("ex_maze1.in","r",stdin);
	freopen("maze.in","r",stdin);
	freopen("maze.out","r",stdout); 
	n=read(); m=read(); k=read();
	for(int i=1;i<=k;i++) s[i]=read(), vip[s[i]]=true;
	for(int i=1;i<=n;i++) d[i]=read(), fbi&=(d[i]==0);
	if(fbi) {
		djstl();
		int ans=0;
		for(int i=1;i<=k;i++) ans=min(ans,dso[s[i]]);
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=m;i++) {
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	} memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++) q.push(s[i]), dis[s[i]]=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int i=0;i<(int)eg[u].size();i++) {
			int v=eg[u][i].first, w=eg[u][i].second;
			int dit=dis[u]+w;//从u->v的“最短路”长度
			if( dit>dis[v] ) continue;
			blt[v].insert( lb(be(v),ed(v),dit),dit ); 
			if( (int)blt[v].size()>d[v] ) {
				dis[v]=blt[v][d[v]]; q.push(v);
			}
		}
	} 
//	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//	puts("");
	if(dis[1]==inf) puts("-1");
	else printf("%d\n",dis[1]);
	return 0;
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
*/
