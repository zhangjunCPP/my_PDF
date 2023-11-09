#include<bits/stdc++.h>
#define int long long
#define _ std::
#define re register

const int N=500+11,inf=1e9;

void Freopen(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
}
_ vector<int>G[411][411*2],siz[411];
int n,tot=1,ans,aans=inf;
int X[N],Y[N],w[N],dp[N],fa[N],U[N],du[N],vis[N],tag[N],vv[N];
void dfs(int u,int fu,int id){
	fa[u]=fu;
	vv[u]=1;
	for(re int i=0;i<G[id][u].size();i++){
		int v=G[id][u][i];
		if(v==fu)
			continue;
		dfs(v,u,id);
	}
}
void init(){
	for(int i=1;i<=tot;i++)
		for(int j=0;j<siz[i].size();j++)
			G[i][siz[i][j]].clear();
	for(int i=1;i<=tot;i++)
		siz[i].clear();
	tot=1;
}
void solve(int del){
	memset(U,0x3f,sizeof(U));
	memset(du,0,sizeof(du));
	ans=0;
	int cnt=0;
	for(re int i=1;i<n;i++)
		if(X[i]!=del&&Y[i]!=del){
			G[tot][X[i]].push_back(Y[i]);
			G[tot][Y[i]].push_back(X[i]);
			du[X[i]]++,du[Y[i]]++;
			siz[tot].push_back(X[i]);
			siz[tot].push_back(Y[i]);
			U[tot]=_ min(U[tot],_ min(X[i],Y[i]));
		}
		else
			tot++;
	for(re int i=1;i<=tot;i++){
		if(siz[i].empty())
			continue;
		memset(fa,0,sizeof(fa));
		memset(dp,0,sizeof(dp));
		memset(vv,0,sizeof(vv));
		memset(vis,0,sizeof(vis));
		cnt=0;
		dfs(U[i],0,i);
		for(re int j=0;j<siz[i].size();j++){
			int v=siz[i][j];
			if(vis[v])
				continue;
			vis[v]=1;
			if(du[v]==1)
				tag[++cnt]=v;
		}
		for(int l=1;l<=cnt;l++)
			for(int r=l+1;r<=cnt;r++){
				if(tag[l]>tag[r])
					_ swap(tag[l],tag[r]);
				for(int i=tag[l];i<=tag[r];i++){
					if(!vv[i])
						continue;
					dp[i]=1;
					for(int j=fa[i];j;j=fa[j])
						if(w[j]<w[i])
							dp[i]=_ max(dp[i],dp[j]+1);
				}
				ans=_ max(ans,dp[tag[r]]);
			}
	}
	init();
}
signed main(){
	Freopen();
	_ cin>>n;
	for(re int i=1;i<n;i++)
		_ cin>>X[i]>>Y[i];
	for(re int i=1;i<=n;i++)
		_ cin>>w[i];
	for(re int i=1;i<=n;i++)
		solve(i),aans=_ min(aans,ans);
	_ cout<<aans; 
	return 0;
}
/*
5
1 2
2 3
3 4
4 5
1 2 3 4 5

2
*/
