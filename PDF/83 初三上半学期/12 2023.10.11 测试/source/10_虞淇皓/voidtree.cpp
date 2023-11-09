#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,q,p[N],op,a[N],dfn[N],k_dfn;
vector<pair<int,long long> >E[N];
inline void decode(int &l,int &r,int &k,int lstans){
	lstans%=19260817;
	l^=lstans;l=(l%n+n)%n+1;
	r^=lstans;r=(r%n+n)%n+1;if(l>r)swap(l,r);
	k^=lstans;
	k=(k%min(r-l+1,100))+1;
}
void dfs_dfn(int u,int fa){
	dfn[u]=++k_dfn;
	for(pair<int,int>i:E[u]){
		int v=i.first;
		if(v==fa)continue;
		dfs_dfn(v,u);
	}
}
int deep[N],father[N],top[N],son[N],siz[N];
ll ds[N];
void dfs_sp1(int u,int fa){
	father[u]=fa,deep[u]=deep[fa]+1,siz[u]=1;
	for(pair<int,int>i:E[u]){
		int v=i.first,w=i.second;
		if(v==fa)continue;
		ds[v]=ds[u]+w;
		dfs_sp1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs_sp2(int u){
	if(son[u]){
		int v=son[u];
		top[v]=top[u];
		dfs_sp2(v);
	}
	for(pair<int,int>i:E[u]){
		int v=i.first;
		if(top[v])continue;
		top[v]=v;
		dfs_sp2(v);
	}
}
int lca(int x,int y){
	int fx=top[x],fy=top[y];
	while(fx!=fy){
		if(deep[fx]<deep[fy]){
			swap(x,y);swap(fx,fy);
		}
		x=father[fx];
		fx=top[x];
	}
	if(deep[x]>deep[y])swap(x,y);
	return x;
}
ll dis(int u,int v){
	int lc=lca(u,v);
	return ds[u]+ds[v]-2*ds[lc];
}
int tree[N],k_tree,vis[N];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
ll get_voidtree(){
	sort(tree+1,tree+k_tree+1,cmp);
	int len=k_tree;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=k_tree;i++)vis[tree[i]]=1;
	for(int i=1;i<len;i++){
		int lc=lca(tree[i],tree[i+1]);
		if(vis[lc])continue;
		tree[++k_tree]=lc;
		vis[lc]=1;
	}
	sort(tree+1,tree+k_tree+1,cmp);
	ll ans=0;
	for(int i=1;i<k_tree;i++){
		ans+=dis(lca(tree[i],tree[i+1]),tree[i+1]);
	}
	return ans;
}
signed main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	int id;
	scanf("%d%d%d",&id,&op,&n);
	for(int i=1;i<n;i++){
		int x,y;ll z;scanf("%d%d%lld",&x,&y,&z);
		E[x].push_back({y,z});E[y].push_back({x,z});
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		a[p[i]]=i;
	}
	dfs_sp1(1,0);
	top[1]=1;dfs_sp2(1);
	if(id==1||id==2||id==17||id==18||id==3||id==4){
		ll lans=0;
		for(int i=1;i<=q;i++){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			if(op)decode(l,r,k,lans); 
			k_tree=0;
			for(int i=l;i<=r;i++)tree[++k_tree]=p[i];
			lans=get_voidtree();
			printf("%lld\n",lans);
		}
	}
	else if(id==15||id==16){
		ll lans=0;
		k_tree=0;
		for(int i=1;i<=n;i++){
			tree[++k_tree]=p[i];
		}
		lans=get_voidtree();
		for(int i=1;i<=q;i++){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%lld\n",lans);
		}
	}
	else if(id==9||id==10){
		ll lans=0;
		for(int i=1;i<=q;i++){
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			lans=0;
			for(int j=l;j<=r;j++){
				for(int jj=j+1;jj<=r;jj++){
					lans=max(lans,dis(p[j],p[jj]));
				}
			}
			printf("%lld\n",lans);
		}
	}
	else{
		ll lans=0;
		for(int i=1;i<=q;i++){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			if(op)decode(l,r,k,lans); 
			k_tree=0;
			for(int i=max(l,r-k+1);i<=r;i++)tree[++k_tree]=p[i];
			lans=get_voidtree();
			printf("%lld\n",lans);
		}
	}
	return 0;
}
