#include<bits/stdc++.h>
using namespace std;
int n,u,v,rt=-1,flag=1,dp[300001],siz[300001];
vector <int> G[300001];
void find(int x,int f,int all){
	siz[x]=1;
	dp[x]=0;
	for(auto y:G[x]) if(y!=f){
		find(y,x,all);
		siz[x]+=siz[y];
		dp[x]=max(dp[x],siz[y]);
	}
	dp[x]=max(dp[x],all-siz[x]);
	if(rt==-1||dp[rt]>dp[x]) rt=x;
}
void dfs(int x,int f){
	siz[x]=1;
	for(auto y:G[x]) if(y!=f){
		dfs(y,x);
		siz[x]+=siz[y];
	}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		if(u<v) swap(u,v);
		if(u!=i-1||v!=i) flag=0;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(G[1].size()==n-1){
		printf("2\n");
		for(int i=2;i<=n;i++) printf("1\n");
		return 0;
	}
	if(flag){
		for(int i=1;i<=n/2;i++) printf("%d\n",(i+1+n)>>1);
		for(int i=n/2+1;i<=n;i++) printf("%d\n",i>>1);
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
		int x=-1;rt=-1;
		for(auto j:G[i]) if(x==-1||siz[j]>siz[x]) x=j;
		find(x,i,siz[x]);
		printf("%d\n",rt);
	}
	return 0;
}
