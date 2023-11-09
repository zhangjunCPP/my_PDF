#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int mod = 1e9+7,N = 505; 
ll n,m,k,vis[N],in[N],d[N],ck[N][N];
struct G{
	ll x,y,w[2],col;
}g[N];
struct node{
	ll v,id;
};
vector<node> e[N];
ll bfs(int u){
	ll res = 1;
	queue<int> q;
	q.push(u),in[u] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 1;
		res *= max((k-d[u]),0ll),res %= mod;
		for(node t:e[u]){
			int v = t.v,id = t.id;
			if(vis[v]) continue;
			if(g[id].col) if(!in[v]) q.push(v),in[v] = 1;
			else{
				if(!in[v]) q.push(v),in[v] = 1;
				d[v]++;
			}
		}
	}
	return res;
}
ll calc(){
	ll res = 1;
	for(int i=1;i<=n;i++) in[i] = d[i] = vis[i] = 0;
	for(int i=1;i<=m;i++) res *= g[i].w[g[i].col],res %= mod;
	for(int i=1;i<=n;i++) if(!vis[i]) res *= bfs(i),res %= mod;
	return res;
}
void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=m;i++){
		cin >> g[i].x >> g[i].y >> g[i].w[0] >> g[i].w[1];
		e[g[i].x].pb({g[i].y,i}),e[g[i].y].pb({g[i].x,i});
		g[i].col = 0;
	}
	if(m<=20){
		ll ans = 0;
 		for(int s=0;s<(1<<m);s++){
 			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ck[i][j] = -1;
 			int tt = 0;
 			for(int i=1;i<=m;i++){
 				if(s&(1<<(i-1))) g[i].col = 1;
 				else g[i].col = 0;
 				if(ck[g[i].x][g[i].y]==-1)ck[g[i].x][g[i].y] = ck[g[i].y][g[i].x] = g[i].col;
 				else if(ck[g[i].x][g[i].y]!=g[i].col) tt = 1;
			}
			if(tt) continue;
			ans += calc(),ans %= mod;
		}
		cout << ans << '\n';
	}else{
		cout << calc() << "\n";
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) solve(); 
	return 0;
} 
