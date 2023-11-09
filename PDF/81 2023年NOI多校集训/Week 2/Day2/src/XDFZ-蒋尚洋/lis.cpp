#include<bits/stdc++.h>
using namespace std;
int n;
int w[500010],delv;
vector<int>G[500010];
struct dfs{
	int res;
	vector<int>dp;
	void f(int u,int fa){
		int type=0,pos=0,raw=0;
		if(dp.empty()||w[u]>dp.back())type=1,dp.push_back(w[u]);
		else{
			type=2;
			pos=lower_bound(begin(dp),end(dp),w[u])-begin(dp);raw=dp[pos];
			dp[pos]=w[u];
		}res=max(res,(int)dp.size());
		for(int v:G[u])if(v!=fa&&v!=delv)f(v,u);
		if(type==1)dp.pop_back();
		else dp[pos]=raw;
	}dfs(int u):res(0),dp{}{f(u,0);}
};
int calc(){
	int res=0;
	for(int i=1;i<=n;i++)if(i!=delv&&(int)G[i].size()-(find(begin(G[i]),end(G[i]),delv)!=end(G[i]))<=1)res=max(res,dfs(i).res);
	return res;
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	int ans=2e9;
	for(int i=1;i<=n;i++){
		delv=i;ans=min(ans,calc());
	}cout<<ans;
	return 0;
}
