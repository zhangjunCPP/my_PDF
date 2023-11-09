#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1e9,w[500001],dep[500001],dp[500001],st[500001][21];
vector <int> G[500001],S,T;
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
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	get(1,0);
	for(int i=1;i<=n;i++){
		int mn=-1e9;
		for(int U=1;U<=n;U++){
			for(int V=1;V<=n;V++){
				int u=U,v=V,k=lca(u,v),f=1;
				if(u==i||v==i) continue;
				S.clear();
				T.clear();
				S.push_back(u);
				T.push_back(v);
				while(u!=k){
					u=st[u][0];
					if(u==i) f=0;
					S.push_back(u);
				}
				while(v!=k){
					v=st[v][0];
					if(v==i) f=0;
					T.push_back(v);
				}
				if(!f) continue;
				for(int j=T.size()-2;j>=0;j--) S.push_back(T[j]);
				dp[0]=1;
				for(int j=1;j<S.size();j++){
					dp[j]=dp[j-1];
					for(int l=0;l<j;l++) if(w[S[j]]>w[S[l]]) dp[j]=max(dp[j],dp[l+1]+1);
				}
				mn=max(mn,dp[S.size()-1]);
			}
		}
		ans=min(ans,mn);
	}
	printf("%d",ans);
	return 0;
}
