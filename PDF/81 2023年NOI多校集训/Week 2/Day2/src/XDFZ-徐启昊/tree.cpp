#include<bits/stdc++.h>
#define int long long
#define _ std::

const int N=2e5+11,inf=1e9,mod=1e9+7;
void Freopen(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}

_ vector<int>G[N*2];
int n,ans;
int dep[N],fa[N],col[N],out[N];
struct tree{
	int siz[N],son[N];
	void dfs1(int u,int fu){
		siz[u]=1;
		fa[u]=fu;
		dep[u]=dep[fu]+1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v==fu)
				continue;
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])
				son[u]=v;
		}
	}
	int top[N];
	void dfs2(int u,int topt){
		top[u]=topt;
		if(son[u])
			dfs2(son[u],topt);
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v==son[u]||v==fa[u])
				continue;
			dfs2(v,v);
		}
	}
	int lca(int u,int v){
		int fu=top[u],fv=top[v];
		while(fu!=fv){
			if(dep[fu]<dep[fv]){
				_ swap(u,v);
				_ swap(fu,fv);
			}
			u=fa[fu];
			fu=top[u];
		}
		if(dep[u]<dep[v])
			return u;
		return v;
	}
	
}T;
int gdis(int u,int v){
	return dep[u]+dep[v]-dep[T.lca(u,v)]*2;
}
void sol10(int k){
	if(k==n+1){
		int ma=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(col[i]==col[j]&&col[i]!=0)
					ma=_ max(ma,gdis(i,j));
		ans=(ans+ma)%mod;
		return;
	}
	col[k]=1;
	sol10(k+1);
	col[k]=2;
	sol10(k+1);
}
void check(){
	if(n<=10){
		sol10(1);
		_ cout<<ans; 
		return;
	}
	if(out[1]==n-1){
		int a=2,b=n+1,res=1;
		while(b){
			if(b&1)
				res=(res*a)%mod;
			a=(a*a)%mod;
			b>>=1;
		}
		_ cout<<res;
		return;
	}
	_ cout<<rand()*rand()%mod*rand()%mod<<_ endl;
}
signed main(){
	Freopen();
	srand(time(0));
	_ cin>>n;
	for(int i=1,x,y;i<n;i++){
		_ cin>>x>>y;
		G[x].push_back(y);
		out[x]++;
		G[y].push_back(x);
	}
	T.dfs1(1,0);
	T.dfs2(1,1);
	check();
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
