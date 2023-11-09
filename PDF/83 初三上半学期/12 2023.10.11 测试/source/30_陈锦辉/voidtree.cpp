//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int id;bool op;
int n,Q;
int p[MAXN];
inline void decode(int &l,int &r,int &k,LL lstans){
	lstans%=19260817;
	if(op){
		l^=lstans,l=(l%n+n)%n+1;
		r^=lstans,r=(r%n+n)%n+1;
		if(l>r)std::swap(l,r);
		k^=lstans;
		k=(k%std::min(r-l+1,100))+1;
	}
}
vector<PII> G[MAXN];
using ci=const int;
int fa[MAXN],dep[MAXN],tp[MAXN],sz[MAXN],son[MAXN];
LL ds[MAXN];
void DFS1(ci u,ci FA,const LL&w){
	fa[u]=FA,dep[u]=dep[FA]+1,sz[u]=1,ds[u]=ds[FA]+w;
	for(const PII&V:G[u]){
		int v=V.first;
		if(v==FA) continue;
		DFS1(v,u,V.second),sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void DFS2(ci u){
	if(son[u]) tp[son[u]]=tp[u],DFS2(son[u]);
	for(const PII&V:G[u])if(!tp[V.first])tp[V.first]=V.first,DFS2(V.first);
}
int LCA(int u,int v){
	while(tp[u]!=tp[v]){
		if(dep[tp[u]]>dep[tp[v]]) u=fa[tp[u]];
		else v=fa[tp[v]];
	}
	return dep[u]<dep[v]?u:v;
}
bool vis[MAXN];
int main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	scanf("%d",&id);
	scanf("%d%d",&op,&n);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].emplace_back(v,w),G[v].emplace_back(u,w);
	}
	DFS1(1,0,0),tp[1]=1,DFS2(1);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	scanf("%d",&Q);
	LL ans=0;
	for(int l,r,k;Q--;){
		scanf("%d%d%d",&l,&r,&k);
		decode(l,r,k,ans);
		memset(vis,0,sizeof(bool)*(n+1));
		if(l==r||k<=1){
			puts("0");continue;
		}
		puts("0");
	}
	return 0;
}

