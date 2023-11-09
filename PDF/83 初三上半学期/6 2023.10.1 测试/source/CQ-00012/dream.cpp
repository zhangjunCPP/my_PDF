#include<bits/stdc++.h>
using namespace std;
int n,m,q,k,id;
const int maxn=1e5+5;
#define pii pair<ll,int>
#define ll long long
//map< pair<int,int> , ll> mp;
vector< pair<int,ll> > G[maxn];
priority_queue<pii,vector< pii >,greater< pii > > Q;
ll dis[maxn];
int s,t,vis[maxn],ind[maxn];
vector<int> G2[maxn];
inline void dij(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[t]=0ll;
	Q.push(make_pair(0ll,t));
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto v:G[x]){
			int to=v.first;
			ll w=v.second;
			if(dis[to]>dis[x]+w){
				dis[to]=dis[x]+w;
				Q.push(make_pair(dis[to],to));
				G2[to].clear();
				G2[to].push_back(x);
			}
			else if(dis[to]==dis[x]+w){
				G2[to].push_back(x);
			}
		}
	}
}
const ll mod=1e9+7;
ll dp[maxn][2];
int qq[maxn];
int VIS[maxn],cmd;
inline void solve(){
	for(int i=1;i<=n;i++) G2[i].clear(),ind[i]=0;
	dij();
	for(int i=1;i<=n;i++)
		for(auto v:G2[i]) ind[v]++;
	memset(dp,0,sizeof dp);
	memset(VIS,0,sizeof VIS);
	cmd=1;
	dp[s][0]=1ll;
	int l=1,r=0;
	for(int i=1;i<=n;i++)
		if(!ind[i]) qq[++r]=i;
	while(l<=r){
		int x=qq[l++];
		if(x==t){
			for(auto v:G2[x])
				if(!--ind[v]) qq[++r]=v;
			continue;
		}
		cmd++;
		int cnt=0;
		for(auto v:G2[x]){
			dp[v][0]=(dp[v][0]+dp[x][0])%mod;
			if(!--ind[v]) qq[++r]=v;
			VIS[v]=cmd;
			cnt++;
		}
		for(auto v:G[x]){
			if(cnt>1 || VIS[v.first]!=cmd)
				dp[v.first][1]=(dp[v.first][1]+dp[x][0])%mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i][0]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<dp[i][1]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
		for(auto v:G2[i]) ind[v]++;
	l=1,r=0;
	for(int i=1;i<=n;i++)
		if(!ind[i]) qq[++r]=i;
	while(l<=r){
		int x=qq[l++];
		if(x==t){
			for(auto v:G2[x])
				if(!--ind[v]) qq[++r]=v;
			continue;
		}
		for(auto v:G2[x]){
			dp[v][1]=(dp[v][1]+dp[x][1])%mod;
			if(!--ind[v]) qq[++r]=v;
		}
	}
//	if(k) dp[t][k]=(dp[t][k]+dp[t][0])%mod;
	printf("%lld\n",dp[t][k]);
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&q,&k,&id);
	for(int i=1,u,v;i<=m;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
//		if(!mp[{u,v}]) mp[{u,v}]=mp[{v,u}]=w;
//		else mp[{u,v}]=mp[{v,u}]=min(mp[{u,v}],w);
	}
//	for(auto y:mp){
//		int u=y.first.first,v=y.first.second;
//		ll w=y.second;
//		G[u].push_back(make_pair(v,w));
//	}
	while(q--){
		scanf("%d%d",&s,&t);
		solve();
	}
	return 0;
}
