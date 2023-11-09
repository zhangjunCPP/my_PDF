#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2023;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n,m,Q,k,id;

int f[N],cnt;
struct edge { int v,w,net; }eg[N<<1];
void add(int uu,int vv,int ww) { eg[++cnt]=(edge) { vv,ww,f[uu] }, f[uu]=cnt; }

int dis[N][N],dit[N][N];
#define ppt pair<int,int>
#define mmp make_pair
priority_queue< ppt,vector<ppt>,greater<ppt> > q;
bool vis[N],vip[N];
void djstl(int s) {
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) vis[i]=false,dis[s][i]=inf,dit[s][i]=0;
	q.push(mmp(0,s)); vip[s]=true; dit[s][s]=1; dis[s][s]=0;
	while(!q.empty()) {
		int u=q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=f[u];i;i=eg[i].net) {
			int v=eg[i].v;
			if( dis[s][v]>dis[s][u]+eg[i].w ) {
				dis[s][v]=dis[s][u]+eg[i].w;
				dit[s][v]=1; q.push(mmp(dis[s][v],v));
			} else if( dis[s][v]==dis[s][u]+eg[i].w ) dit[s][v]++;
		}
	} 
}
signed main() {
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&m,&Q,&k,&id);
	for(int i=1;i<=m;i++) {
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	} while(Q--) {
		int s,t; scanf("%lld%lld",&s,&t);
		if(!vip[s]) djstl(s);
		if(!vip[t]) djstl(t);
		if(!k) printf("%lld\n",dit[s][t]%mod);
		else {
			int ans=0;
//			for(int i=1;i<=n;i++) printf("dit[%d][%d]=%d   dis[%d][%d]=%d\n",s,i,dit[s][i],s,i,dis[s][i]);
//			for(int i=1;i<=n;i++) printf("dit[%d][%d]=%d   dis[%d][%d]=%d\n",t,i,dit[t][i],t,i,dis[t][i]);
			int ipp=0;
			for(int i=1;i<=n;i++) {
				if(dis[s][i]+dis[t][i]==dis[s][t]) {
					if(i==t) continue;
					for(int j=f[i];j;j=eg[j].net) {
						int u=eg[j].v;
//						cout<<i<<" "<<u<<endl;
						if( dis[s][i]+eg[j].w+dis[t][u]==dis[s][t] ) { continue; }
						ans+=dit[s][i]*dit[t][u]; ans%=mod;
					} ipp+=dit[t][i]>1 ? dit[t][i] : 0;
				} 
			} ans+=ipp; printf("%lld\n",ans); 
		} 
	}
	return 0;
}
/*
4 5 2 1 0
1 2 1
2 3 1
1 3 2
2 4 5
3 4 2
1 3
1 4
*/
