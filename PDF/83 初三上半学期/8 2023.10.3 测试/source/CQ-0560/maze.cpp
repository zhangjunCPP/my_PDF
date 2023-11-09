//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,int> PLI;
const LL inf=0x3f3f3f3f3f3f3f3fll;
int n,m,k;
bool s[MAXN];
int d[MAXN];
vector<PII> G[MAXN];
LL ans=-1;
void solve_sub3(const int S){
	bool vis[MAXN];LL dis[MAXN];
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<PLI,vector<PLI>,greater<PLI> > Q;
	Q.emplace(dis[S]=0,S);
	for(int u;!Q.empty();){
		u=Q.top().second;Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(const PII&e:G[u])if(dis[u]+e.second<dis[e.first])Q.emplace(dis[e.first]=dis[u]+e.second,e.first);
	}
	ans=inf;
	for(int i=2;i<=n;i++)if(vis[i] && s[i])ans=min(ans,dis[i]);
	printf("%lld\n",ans);
}
bool vis[MAXN];
LL dfs(const int pos,const int w){
	if(s[pos]) return w;
	if(vis[pos]) return inf;
	int sz=G[pos].size();
	if(d[pos]>=sz) return inf;
	vis[pos]=1;
	multiset<LL> S;
	for(const PII&e:G[pos]){
		int x=dfs(e.first,w+e.second);
		if((int)S.size()<sz-d[pos]) S.emplace(x);
		else if(x>*S.begin()) S.erase(S.begin()),S.emplace(x);
	}
	vis[pos]=0;
	return *S.begin();
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=k;i++){
		scanf("%d",&x),s[x]=1;
		if(x==1){puts("0");return 0;}
	}
	bool f=0;
	for(int i=1;i<=n;i++) scanf("%d",&d[i]),f|=d[i];
	for(int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].emplace_back(v,w),G[v].emplace_back(u,w);
	}
	if(!f){solve_sub3(1);return 0;}
	ans=dfs(1,0);
	printf("%lld\n",ans>=inf?-1:ans);
	return 0;
}

