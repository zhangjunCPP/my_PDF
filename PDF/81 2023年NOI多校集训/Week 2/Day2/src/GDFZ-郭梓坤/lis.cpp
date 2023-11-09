#include<bits/stdc++.h>
#define il inline
#define int long long
using namespace std;
const int N=5e5+5;
const int inf=1e9+7;

il int wrd(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)){x=x*10+c-48,c=getchar();}
	return x*f;
}

int n,cnt,head[N],a[N];

struct edge{
	int to,nxt;
}e[N<<1];

il void add(int u,int v){
	e[++cnt]={v,head[u]},head[u]=cnt;
}

int f[N][21],siz[N],dep[N],dfn[N],tot,mp[N];
int up[N],d[N];

int pos;

void dfs1(int u,int fa){
	dep[u]=dep[fa]+1,pos=max(pos,dep[u]),f[u][0]=fa,dfn[u]=++tot,mp[tot]=u;
	for(int i=1;i<21;++i) f[u][i]=f[f[u][i-1]][i-1];
	
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs1(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;--i){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;--i){
		if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}


signed main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	n=wrd();
	for(int i=1;i<n;++i){
		int u=wrd(),v=wrd();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i) a[i]=wrd();
	dfs1(1,0);
	
	return printf("%lld",max(1ll,pos-2)),0;
}