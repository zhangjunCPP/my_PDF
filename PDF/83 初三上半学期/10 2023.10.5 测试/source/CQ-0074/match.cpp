#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,d[N],ans;
int st[N],top,vis[N],dis[N];
vector<int>E[N];
void dfs(int u){
	st[++top]=u,dis[u]=top,vis[u]=1;
	for(int v:E[u]){
		if(dis[v]){
			if(dis[u]-dis[v]+1==3){
				ans=3;
				return;
			}
			continue;
		}
		dfs(v);
	}
	top--;dis[u]=0;
}
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)d[i]=0,E[i].clear();
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			if(ans==3)break;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){sol();}
	return 0;
}
/*
g++ match.cpp -o match -std=c++14 -O2 -Wall
./match
*/