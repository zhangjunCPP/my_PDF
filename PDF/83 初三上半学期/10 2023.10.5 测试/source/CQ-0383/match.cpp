#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int vis[1000005];
vector<int> G[1000005];
void Freopen(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)G[i].clear(),vis[i]=0;
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		int ans=0;
		for(int u=1;u<=n;u++)ans=max(ans,(int)G[u].size());
		if(ans>=3)printf("%d\n",ans);
		else{
			for(int u=1;u<=n;u++){
				for(int v:G[u]){
					vis[v]=u;
					for(int w:G[v])if(vis[w]==u){ans=3;break;}
					if(ans==3)break;
				}
				if(ans==3)break;
			}
			printf("%d\n",ans);
		}
	}
}
/*
1
3 3
1 2
2 3
3 1 
*/
