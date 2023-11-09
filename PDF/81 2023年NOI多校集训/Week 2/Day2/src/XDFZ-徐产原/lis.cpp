#include<bits/stdc++.h>
using namespace std;
int n,m,cut,dad;
vector<int> G[4005];
int num[4005],dp[4005],p[4005];
bool dfs(int u,int fa,int len){
	dp[u]=0;p[len]=num[u];
	for(int i=1;i<len;i++)if(p[i]<p[len])dp[len]=max(dp[len],dp[i]+1);
	if(dp[len]>m){
		dad=fa;
		cut=u;
		return true;
	}
	else{
		for(int v:G[u])if(v!=fa){
			if(dfs(v,u,len+1))
				return true;
		}
		return false;
	}
}
bool dfs2(int u,int fa,int len){
	dp[u]=0;p[len]=num[u];
	for(int i=1;i<len;i++)if(p[i]<p[len])dp[len]=max(dp[len],dp[i]+1);
	if(dp[len]>m){
		cut=u;
		return true;
	}
	else{
		for(int v:G[u])if(v!=fa&&v!=cut){
			if(dfs2(v,u,len+1))
				return true;
		}
		return false;
	}
}
bool check(){
	if(!dfs(1,0,1))return true;
	if(dfs2(1,0,1)||dfs2(cut,dad,1))return false;
	return true;
}
void Freopen(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	int l=1,r=n;
	while(l<r){
		m=(l+r)>>1;
		if(check())r=m;
		else l=m+1;
	}
	m=l;
	check();
	cout<<l<<endl;
}