#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans,vis[21],u[401],v[401],ind[21];
const int mod=998244353;
void dfs(int pos){
	if(pos==m+1){
		for(int i=1;i<=n;i++) if(vis[i]&&ind[i]<2) return;
		ans++;
		if(ans>=mod) ans-=mod;
		return;
	}
	dfs(pos+1);
	if(vis[u[pos]]&&vis[v[pos]]) ind[u[pos]]++,ind[v[pos]]++,dfs(pos+1),ind[u[pos]]--,ind[v[pos]]--;
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	scanf("%d",&q);
	while(q--){
		for(int i=1;i<=n;i++) scanf("%1d",&vis[i]);
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
