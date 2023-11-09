#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
int n,k,col[N];
vector<int> eg[N];
void add(int u,int v) {
	eg[u].push_back(v); 
	eg[v].push_back(u);
}
struct DS{
	int fa[N],siz[N];
	void init() { 
		for(int i=1;i<=n;i++) fa[i]=col[i]+n;
		for(int i=1;i<=k;i++) fa[i+n]=i+n,siz[i+n]=1;
	}
	int get(int x) { return x==fa[x] ? x : fa[x]=get(fa[x]); }
	void us(int u,int v) { u=get(u); v=get(v); if(u!=v) fa[u]=v,siz[v]+=siz[u],siz[u]=0; }
}ds;
int fa[N][30],dep[N];
void dfs(int u,int dad) {
	fa[u][0]=dad; dep[u]=dep[dad]+1;
	for(int i=1;i<=25;i++) fa[u][i]=fa[ fa[u][i-1] ][i-1];
	for(int i=0;i<(int)eg[u].size();i++) {
		int v=eg[u][i];
		if(v==dad) continue;
		dfs(v,u);
	}
}
int LCA(int u,int v) {
	if( dep[u]<dep[v] ) swap(u,v);
	for(int i=23;i>=0;i--) if( dep[fa[u][i]]>=dep[v] ) u=fa[u][i];
	if(u==v) return v;
	for(int i=23;i>=0;i--) if( fa[u][i]!=fa[v][i] ) u=fa[u][i], v=fa[v][i];
	return fa[u][0];
}
vector<int> co[N];
void hb(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	int now=u;
	while(now!=v) {
		if( ds.get(now)!=ds.get(u) ) ds.us( now,u );
//		printf(" jcnvjkdnjkvnf   ");
		now=fa[now][0];
//		cout<<now<<" "<<v<<"  fgv  \n";
	}
	if( ds.get(u)!=ds.get(v) ) ds.us(v,u);
}
int lca[N];
bool vip[N];
int ans=0x3f3f3f3f;
void dfs(int ccc){
	vip[ccc]=true;
	for(int j=0;j<(int)co[ccc].size();j++) {
//		cout<<ccc<<" "<<co[ccc][j]<<" "<<lca[ccc]<<endl;
		hb( co[ccc][j],lca[ccc] );
	}
//	for(int i=1;i<=k;i++) if( ds.get(ccc)==ds.get(i) && !vip[i] ) printf("%d         %d \n",ccc,i);
	for(int i=1;i<=k;i++) {
		if( ds.get(ccc)==ds.get(i) && !vip[i] ) dfs(i);
	}
}
signed main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++) {
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;i++) scanf("%d",&col[i]), co[ col[i] ].push_back(i);
	ds.init();
	dfs(1,0);
	for(int i=1;i<=k;i++) {
		if( (int)co[i].size()==1 ) { puts("0"); return 0; }
		lca[i]=co[i][0];
		for(int j=1;j<(int)co[i].size();j++) {
			int u=co[i][j];
			lca[i]=LCA(u,lca[i]);
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++) vip[j]=false;
		ds.init(); dfs(i);
//		cout<<i<<" "<<ds.siz[ ds.get(i)  ]<<"\n";
		ans=min( ans,ds.siz[ ds.get(i) ]-1 );
	}
	printf("%d",ans);
	return 0;
}
