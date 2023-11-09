#include<bits/stdc++.h>
#define N 10005
#define int long long
using namespace std;
int n,u[N],v[N],ans,vis[N];
map<int,int> tong;
void dfs(int x,int now){
	if(x==n){
		if(!tong[now]){
			tong[now]=1;
			ans++;
		}
		return ;
	}
	if(vis[u[x]]==0&&vis[v[x]]==0){
		vis[u[x]]=1;
		dfs(x+1,now*10+u[x]);
		vis[u[x]]=0;
		vis[v[x]]=1;
		dfs(x+1,now*10+v[x]);
		vis[v[x]]=0;
	}else{
		dfs(x+1,now);
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
5
1 2
1 3
1 4
1 5
*/

/*
7
7 2
7 6
1 2
7 5
4 7
3 5
*/
