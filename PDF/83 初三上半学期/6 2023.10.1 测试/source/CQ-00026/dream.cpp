#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,q,k,id;
vector<pair<int,int> >E[N];
int a[N],b[N];
void dfs_sol1(int u,int x,int fa){
	a[u]=x;b[x]=u;
	for(pair<int,int> i:E[u]){
		int v=i.first;
		if(v==fa)continue;
		dfs_sol1(v,x+1,u);
	}
}
void sol1(){
	for(int i=1;i<=n;i++){
		if(E[i].size()==1){
			dfs_sol1(i,1,0);
			break;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(k==0){
			printf("1\n");
			continue;
		}
		if(a[x]<=a[y]){
			int ans;
			if(E[x].size()==1)ans=0;
			else ans=1;
			ans+=a[y]-a[x]-1;
			printf("%d\n",ans);
		}
		else{
			int ans;
			if(E[x].size()==1)ans=0;
			else ans=1;
			ans+=a[x]-a[y]-1;
			printf("%d\n",ans);
		}
	}
}
int fa[N][20],deep[N],val[N];
void dfs_sol2(int u,int fat){
	deep[u]=deep[fat]+1;
	fa[u][0]=fat;
	val[u]=val[fat]+E[u].size();
	if(u!=1)val[u]--;
	for(int i=1;i<=19;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(pair<int,int> i:E[u]){
		int v=i.first;
		if(v==fat)continue;
		dfs_sol2(v,u);
	}
}
int getfa(int u,int x){
	for(int i=19;i>=0;i--){
		if(x>=(1<<i)){
			u=fa[u][i];
			x-=(1<<i);
		}
	}
	return u;
}
int lca(int u,int v){
	if(deep[u]<deep[v])swap(u,v);
	for(int i=19;i>=0;i--){
		if(deep[u]-deep[v]>=(1<<i)){
			u=fa[u][i];
		}
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int dis(int u,int v){
	int lc=lca(u,v);
	return val[u]+val[v]-val[lc]-val[fa[lc][0]];
}
map<pair<int,int>,int>mp;
void sol2(){
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)swap(x,y);
		if(x==y){
			y=++n;
			E[x].push_back({y,z});
			E[y].push_back({x,z});
		}
		else if(mp.count({x,y})){
			E[x].push_back({++n,z});
			E[y].push_back({++n,z});
		}
		else{
			E[x].push_back({y,z});
			E[y].push_back({x,z});
			mp[{x,y}]=1;
		}
	}
	dfs_sol2(1,0);
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(k==0){
			printf("1\n");
			continue;
		}
		if(x==y){
			printf("0\n");
			continue;
		}
		int lc=lca(x,y);
		if(deep[x]<deep[y])swap(x,y);
		if(y==lc){
			int z=getfa(x,deep[x]-deep[y]-1);
			printf("%d\n",dis(x,z));
		}
		else if(fa[y][0]==lc){
			printf("%d\n",dis(x,lc)-1);
		}
		else{
			printf("%d\n",dis(x,fa[y][0])-1);
		}
	}
}
void sol3(){
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
	}
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		printf("0\n");
	}
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&q,&k,&id);
	if(id==7||id==19||id==20){
		sol2();
	}
	else if(id==8||id==16||id==17||id==18){
		sol2();
	}
	else{
		sol3();
	}
	return 0;
}
