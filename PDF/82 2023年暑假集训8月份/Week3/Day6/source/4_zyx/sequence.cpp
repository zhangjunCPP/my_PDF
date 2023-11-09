#include<bits/stdc++.h>
using namespace std;
int n,k,p,dp[251],a[41];
map <vector<int>,bool> vis;
vector <int> now;
const int mod=998244353;
void get(int pos){
	if(p>k) return;
	if(now.size()){
		if(!vis[now]) p++;
		vis[now]=1;
	}
	if(pos==n+1) return;
	get(pos+1);
	now.push_back(a[pos]);
	get(pos+1);
	now.pop_back();
}
void dfs(int pos){
	if(pos==n+1){
		p=0;
		vis.clear();
		get(1);
		if(p>k) return;
		dp[p]++;
		if(dp[p]>=mod) dp[p]-=mod;
		return;
	}
	a[pos]=0;
	dfs(pos+1);
	a[pos]=1;
	dfs(pos+1);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
		
	scanf("%d%d",&n,&k);
	if(k<n){
		for(int i=1;i<=k;i++) printf("0 ");
		return 0;
	}
	if(k==n){
		for(int i=1;i<k;i++) printf("0 ");
		printf("2");
		return 0;
	}
	dfs(1);
	for(int i=1;i<=k;i++) printf("%d ",dp[i]);
	return 0;
}
