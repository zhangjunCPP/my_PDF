#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16;
int n;
bool col[N];
struct node { int u,v,id; }eg[N];
int ans;
void dfs(int now) {
	if(now>=n) { ans++; return ; }
	int u=eg[now].u,v=eg[now].v;
	if(!col[u]&&!col[v]) {
		col[u]=true; dfs(now+1); col[u]=false;
		col[v]=true; dfs(now+1); col[v]=false;
	} else dfs(now+1);
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d%d",&eg[i].u,&eg[i].v), eg[i].id=i;
	dfs(1); printf("%d",ans);
	return 0;
} 
/*
7
7 2
7 6
1 2
7 5
4 7
3 5
*/
