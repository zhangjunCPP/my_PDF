#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 200005
#define INF 2e9
using namespace std;
int n,m,k,d[N],deg[N],cnt;
bool op[N],vis[N];
vector<pii> e[N];
int dfs(int x,int fa){
	if(op[x])return 0;
	vis[x]=1;
	if(deg[x]-(x>1)<=d[x])return INF;
	vector<int> tmp;
	tmp.clear();
	for(pii i:e[x]){
		int v=i.se,w=i.fi;
		if(v==fa||vis[v])continue;
		tmp.pb(w+dfs(v,x));
	}
	sort(tmp.begin(),tmp.end());
	vis[x]=0;
	if((int)tmp.size()>d[x])return tmp[d[x]];
	return INF;
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,x;i<=k;i++){
		scanf("%lld",&x);
		op[x]=1;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
	for(int i=1,x,y,w;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&w);
		e[x].pb(mp(w,y));
		e[y].pb(mp(w,x));
		deg[x]++;
		deg[y]++;
	}
	int ans=dfs(1,0);
	if(ans>=INF)ans=-1;
	printf("%lld",ans);
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
