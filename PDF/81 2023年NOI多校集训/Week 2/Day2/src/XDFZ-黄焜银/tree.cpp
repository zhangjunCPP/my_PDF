#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
int dep[N],fa[N][20];
int first[N],cnt;
struct Edge{
	int u,v,nex;
}a[N<<1];
void add(int u,int v){
	a[++cnt]={u,v,first[u]};
	first[u]=cnt;
}
void pre(int u,int dad){
	dep[u]=dep[dad]+1;
	fa[u][0]=dad;
	for(int k=1;k<=19;++k)fa[u][k]=fa[fa[u][k-1]][k-1];
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(v!=dad)pre(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=19;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dist(int x,int y){
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
int n,col[N],ans;
int check(){
	int res=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(col[i]==col[j])res=max(res,dist(i,j));
		}
	}
	return res;
}
void dfs(int now){
	if(now>n){
		ans=(ans+check())%mod;
		return;
	}
	col[now]=0;
	dfs(now+1);
	col[now]=1;
	dfs(now+1);
}
int i,x,y;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	pre(1,0);
	dfs(1);
	printf("%d",ans);
	return 0;
}


