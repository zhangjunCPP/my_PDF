#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
int n,id,op;
inline void decode(int &l,int &r,int &k,ll lstans,int testop){
	lstans%=19260817;
	if(testop){
		l^=lstans; l=(l%n+n)%n+1;
		r^=lstans; r=(r%n+n)%n+1;
		if(l>r) swap(l,r);
		k^=lstans;
		k=(k%min(r-l+1,100))+1;
	}
} 
vector< pair<ll,int> > G[maxn];
int p[maxn],vis[maxn];
ll ans=0;
int P[maxn];
vector<int> v;
int dfn[maxn],fa[maxn],tot;
ll dep[maxn];
inline void DFS(int x,int f){
	dfn[x]=++tot;
	for(auto y:G[x]){
		if(y.second!=f){
			fa[y].second=x;
			dep[y].second=x;
			DFS(y.second,x);
		}
	}
}
inline void solve(int l,int r){
	v.clear();
	for(int i=1;i<=n;i++){
		if(vis[i]) v.push_back(p[i]); 
	}
	for(int i=1;i<=)
}
inline void dfs(int now,int l,int r,int cnt,int k){
	if(cnt>k) return ;
	if(now==r+1 && cnt==k){
		solve(l,r);
		return ;
	}
	vis[now]=1;
	dfs(now+1,l,r,cnt+1,k);
	vis[now]=0;
	dfs(now+1,l,r,cnt,k);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0); 
	cin>>id;
	cin>>op>>n;
	for(int i=1;i<n;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(w,v));
		G[v].push_back(make_pair(w,u));
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	ll lstans=0;
	int Q;
	cin>>Q;
	while(Q--){
		int l,r,k;
		cin>>l>>r>>k;
		decode(l,r,k,lstans,op);
		
	}
	return 0;
}

