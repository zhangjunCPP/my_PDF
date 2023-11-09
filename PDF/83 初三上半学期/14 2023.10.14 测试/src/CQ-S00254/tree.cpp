#include<iostream>
#include<cstdio>
using namespace std;
const int N=17;
int lft[N],rit[N],n,ans;
bool vis[N];
void dfs(int pos){
	if(pos==n){
		ans++;
		return;
	}
	if(vis[lft[pos]]||vis[rit[pos]]){
		dfs(pos+1);
		return;
	}
	if(!vis[lft[pos]]){
		vis[lft[pos]]=true;
		dfs(pos+1);
		vis[lft[pos]]=false;
	}
	if(!vis[rit[pos]]){
		vis[rit[pos]]=true;
		dfs(pos+1);
		vis[rit[pos]]=false;
	}
}
signed main(){
//	freopen("D:\\down1014\\tree\\ex_tree2.in","r",stdin);
	freopen("tree.in","r",stdin);
	freopen("tree.in","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&lft[i],&rit[i]);
	}
	dfs(1);
	printf("%d",ans);
}
