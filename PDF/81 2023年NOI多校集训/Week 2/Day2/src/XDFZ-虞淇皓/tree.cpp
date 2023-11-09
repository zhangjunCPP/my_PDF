//±©Á¦ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,mod=1e9+7;
int n;
vector<int>f[1000010];
int father[N],deep[N],siz[N],top[N],son[N];
void dfs_sp1(int u,int fa){
	father[u]=fa;
	deep[u]=deep[fa]+1;
	siz[u]=1;
	for(int v:f[u]){
		if(v==fa)continue;
		dfs_sp1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
} 
void dfs_sp2(int u,int fa){
	if(son[u]){
		int v=son[u];
		top[v]=top[u];
		dfs_sp2(v,u);
	}
	for(int v:f[u]){
		if(v==fa||top[v])continue;
		top[v]=v;
		dfs_sp2(v,u);
	}
}
int lca(int x,int y){
	int fx=top[x],fy=top[y];
	while(fx!=fy){
		if(deep[fx]<deep[fy]){
			swap(x,y);swap(fx,fy);
		}
		x=father[fx];
		fx=top[x];
	}
	if(deep[x]>deep[y])swap(x,y);
	return x;
}
int dis(int x,int y){
	int lc=lca(x,y);
	return deep[x]+deep[y]-2*deep[lc];
}
int vis[N],ans;
void dfs(int k){
	if(k>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				if(vis[i]==vis[j])sum=max(sum,dis(i,j));
			}
		}
		ans=(ans+sum)%mod;
		return;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=2;
	dfs(k+1);
	vis[k]=0;
}
int ksm(int x,int y){
	int an=1;
	while(y){
		if(y&1)an=an*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return an;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out,","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x].push_back(y);
		f[y].push_back(x);
	}
	if(f[1].size()==n-1){
		cout<<ksm(2,n+1);
		return 0;
	}
	dfs_sp1(1,0);
	top[1]=1;
	dfs_sp2(1,0);
	dfs(1);
	cout<<ans;
	return 0; 
}
/*
6
1 2
2 3
3 4
4 5
3 6
*/
