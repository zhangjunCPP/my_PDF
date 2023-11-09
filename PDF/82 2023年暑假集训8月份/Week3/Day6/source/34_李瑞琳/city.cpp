#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2e5+10;
int n,k,c[N],head[N],cnt,deg[N],fa[N],siz[N],dep[N],st[N][20],res,ans;
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	int rx=find(x),ry=find(y);
	if(rx==ry)return;
	if(siz[rx]>siz[ry])swap(rx,ry);
	fa[rx]=ry,siz[ry]+=siz[rx];
}
void dfs(int u,int f){
	st[u][0]=f,dep[u]=dep[f]+1;
	for(int i=1;i<20;++i)st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u);
	}
}
int get(int u,int k){
	for(int i=19;~i;--i)
		if(dep[st[u][i]]>=k)u=st[u][i];
	return u;
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	v=get(v,dep[u]);
	if(u==v)return u;
	for(int i=19;~i;--i)
		if(st[u][i]!=st[v][i])u=st[u][i],v=st[v][i];
	return st[u][0];
}
void chain_merge(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int lca=LCA(x,y),u=x,v=y;
	while(u!=lca){
		if(c[u]!=c[x])++res;
		merge(c[u],c[x]),u=st[u][0];
	}
	while(v!=lca){
		if(c[v]!=c[y])++res;
		merge(c[v],c[y]),v=st[v][0];
	}
	if(c[lca]!=c[x])++res,merge(c[lca],c[x]);
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read(),k=read(),ans=2e9;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u),++deg[u],++deg[v];
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<=n;++i){
		res=0;
		for(int j=1;j<=k;++j)fa[j]=j,siz[j]=1;/*fa[col]*/
		for(int j=1;j<=n;++j){
			if(i==j||c[i]!=c[j])continue;
			chain_merge(i,j);	
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
/*
12 4
7 9
1 3
4 6
2 4
10 12
1 2
2 10
11 1
2 8
5 3
6 7
3
1
1
2
4
3
3
2
2
3
4
4
*/
