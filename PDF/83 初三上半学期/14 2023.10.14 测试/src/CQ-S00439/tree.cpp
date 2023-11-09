#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353 ;
const int N = 1e6 + 5 ;
int n,ans,vis[N];
pair<int,int>t[N]; 
void dfs(int k){
	if(k>n-1){
		ans=(ans+1)%mod;
		return;
	}
	if(!vis[t[k].first]&&!vis[t[k].second]){
		vis[t[k].first]=1;
		dfs(k+1);
		vis[t[k].first]=0;
		vis[t[k].second]=1;
		dfs(k+1);
		vis[t[k].second]=0;
	}else{
		dfs(k+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		t[i]=make_pair(x,y);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
} 
