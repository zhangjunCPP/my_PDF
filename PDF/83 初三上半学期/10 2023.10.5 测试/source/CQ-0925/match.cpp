#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int N = 1e6+5;
int n,m,deg[N]; 
struct G{
	int u,v;
}g[N];
map<int,int> mp[N];
vector<int> e[N]; 
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) deg[i] = 0;
	for(int i=1;i<=m;i++) cin >> g[i].u >> g[i].v,deg[g[i].u]++,deg[g[i].v]++;
	int ans = 0;
	for(int i=1;i<=n;i++) ans = max(ans,deg[i]);
	if(ans<3){
		for(int i=1;i<=n;i++) mp[i].clear(),e[i].clear();
		for(int i=1;i<=m;i++){
			int u = g[i].u,v = g[i].v;
			e[u].pb(v),e[v].pb(u);
			if(u>v) swap(u,v);
			mp[u][v] = 1; 
		}
		for(int i=1;i<=n;i++){
			if(deg[i]<2) continue;
			int u=e[i][0],v=e[i][1];
			if(u>v) swap(u,v);
			if(mp[u][v]){
				ans = 3;
				break;
			}	
		}
	}
	cout << ans << '\n'; 
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) solve(); 
	return 0;	
}
//三元环和最大度数 
