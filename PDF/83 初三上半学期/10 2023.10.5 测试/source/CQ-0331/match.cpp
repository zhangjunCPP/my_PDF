#include<bits/stdc++.h>
using namespace std;
int t,n,m,u,v,out[1000001],vis[1000001];
vector <int> G[1000001];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) out[i]=0,G[i].clear();
		int ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u),out[u]++,out[v]++;
		}
		for(int i=1;i<=n;i++) ans=max(ans,out[i]);
		if(ans<3){
			for(int i=1;i<=n;i++){
				for(auto j:G[i]) vis[j]=1;
				for(auto j:G[i]) for(auto l:G[j]) if(l!=i&&vis[l]) ans=max(ans,3);
				for(auto j:G[i]) vis[j]=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
