#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
void Freopen(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int T,n,m;
int du[MAXN];
vector<int> G[MAXN<<1];
int dep[MAXN]; bool vis[MAXN],flag;
void dfs(int u,int fa){
	if(flag) return ;
	dep[u]=dep[fa]+1; vis[u]=true;
	for(auto v:G[u]){
		if(v==fa) continue;
		if(vis[v]){
			int siz=dep[u]-dep[v]+1;
			if(siz==3){flag=true; return ;}
		}
		dfs(v,u);
		if(flag) return ;
	}
}
int main(){
	Freopen();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			vis[i]=false; du[i]=dep[i]=0;
			for(int j=0;j<(int)G[i].size();j++) G[i][j]=0;
		}
		for(int i=1;i<=m;i++){
			int u,v; scanf("%d%d",&u,&v);
			du[u]++; du[v]++;
			G[u].push_back(v); G[v].push_back(u);
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,du[i]);
		if(ans>=3) printf("%d\n",ans);
		else{
			flag=false;
			dfs(1,0);
			if(flag) ans=max(ans,3);
			printf("%d\n",ans);
		}
	}
	return 0;
} 
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5

1
3 2
1 2
2 3
*/
