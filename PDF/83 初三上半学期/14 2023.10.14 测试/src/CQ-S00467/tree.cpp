#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
const int mod=998244353;
inline void Freopen(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
int n;
struct node{
	int u,v;
}e[MAXN<<1];
bool col[MAXN<<1],vis[MAXN<<1];
int ans; bool flag=false;
void dfs(int k){
	if(flag) ans++;
	if(k==n) return ;
	if(col[e[k].u]==0 && col[e[k].v]==0){
		col[e[k].u]=1; dfs(k+1); col[e[k].u]=0;
		flag=true;
		col[e[k].v]=1; dfs(k+1); col[e[k].v]=0;
		flag=true; 
	}
}
int main(){
	Freopen();
	scanf("%d",&n);
	bool flag1=true,flag2=true;
	for(int i=1;i<=n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
		e[i]={u,v}; 
		if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
		if(u!=1 || v!=i+1) flag1=false;
		if(u!=i || v!=i+1) flag2=false; 
	}
	if(flag1) return printf("%d",n),0;
	if(flag2) return printf("%d",n),0;
	sort(e+1,e+n,[](const node &x,const node &y){
		if(x.u==y.u) return x.v<y.v;
		return x.u<y.u;
	});
	dfs(1); printf("%d",ans);
	return 0;
} 
/*
5
1 2
1 3
1 4
1 5

5
1 2
2 3
3 4
4 5

7
7 2
7 6
1 2
7 5
4 7
3 5
*/
