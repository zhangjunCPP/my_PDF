#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
const int N=2e6+10;
void File(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int n,m;
vector<int>g[N];
int du[N];
int vis[N];
int len=0;
int flag=0,ans=0;
void dfs(int u,int fa,int faa){
	vis[u]=1;
	for(int v:g[u]){
		if(!vis[v]) dfs(v,u,fa);
		if(vis[v]){
			if(v==faa) ans=max(ans,3);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		du[x]++,du[y]++;
	}
	ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,du[i]);
	if(ans<3){
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs(i,0,0);
		}
	}
	cout<<ans;
	for(int i=1;i<=n;i++) du[i]=0,g[i].clear(),vis[i]=0;
}
int main(){
	/*
	7 3
	7 5
	5 1
	1 7
	ans:3
	*/
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	File();
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	} 
}
