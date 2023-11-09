#include<bits/stdc++.h>
using namespace std;
int n,dep[100001],st[100001][21],col[100001];
long long ans;
vector <int> G[100001];
const int mod=1e9+7;
void get(int u,int f){
	dep[u]=dep[f]+1;
	st[u][0]=f;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int i=0;i<G[u].size();i++) if(G[u][i]!=f) get(G[u][i],u);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(dep[st[u][i]]>=dep[v]) u=st[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
	return st[u][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void dfs(int pos){
	if(pos==n+1){
		int mx=-1e9;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(col[i]==col[j]) mx=max(mx,dis(i,j));
		ans+=mx;
		while(ans>=mod) ans-=mod;
		return;
	}
	col[pos]=1;
	dfs(pos+1);
	col[pos]=0;
	dfs(pos+1);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	get(1,0);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
