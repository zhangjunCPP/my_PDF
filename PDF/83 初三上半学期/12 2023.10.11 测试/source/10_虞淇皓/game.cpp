#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,p[N];
vector<int>E[N];
int vis[N];
void dfs(int u){
	vis[u]=1;
	for(int v:E[u]){
		if(vis[v])continue;
		dfs(v);
	}
}
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		E[i].clear();
	}
	string str;cin>>str;
	for(int i=1;i<=k;i++){
		p[i]=(str[i-1]=='P'?1:0);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	int fl=1;
	for(int i=1;i<=n;i++){
		fl=(fl&vis[i]);
	}
	if(!fl||m==n-1){
		printf("%c\n",p[1]==1?'G':'P');
		return;
	}
	printf("%c\n",p[(m-n+2-1+k)%k+1]==1?'G':'P');
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)sol();
	return 0;
}


