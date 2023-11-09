#include<bits/stdc++.h>
using namespace std;
int t,n,m;
vector<int>G[1000010];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	for(cin>>t;t--;){
		scanf("%d%d",&n,&m);int ans=!!m;
		set<int>rest;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int u,v;m--;)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
		for(int i=1;i<=n;i++)ans=max(ans,(int)G[i].size());
		for(int i=1;ans<3&&i<=n;i++)
		if(G[i].size()>1){
			int a=G[i][0],b=G[i][1];
			for(int v:G[a])if(v==b)ans=3;
		}
		printf("%d\n",ans);
	}
	return 0;
}
