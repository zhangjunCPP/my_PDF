#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e6+5;
int t;
int n,m,d[N];
int fa[N];
bool vis[N],flag;
vector<int> e[N];
void dfs(int u,int fath){
	if(flag) return ;
	fa[u]=fath;
	if(vis[u]){
		int sz=1;
		for(int v=fa[u];v!=u;v=fa[v]) sz++;
		if(sz==3) flag=1;
		return ;
	}
	vis[u]=1;
	for(auto v:e[u]) if(v!=fath) dfs(v,u);
}
void work(){
	_(n),_(m);
	memset(d+1,0,sizeof(int)*n);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=m;i++){
		int u,v; _(u),_(v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
		d[u]++,d[v]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	if(ans<3){
		memset(vis+1,0,sizeof(bool)*n);
		memset(fa+1,0,sizeof(int)*n);
		flag=0;
		dfs(1,0);
		if(flag) ans=3;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	_(t);
	while(t--) work();
	return 0;
}
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5

1
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

2
4 3
1 3
1 4
3 4
4 3
1 3
1 4
3 4
*/
