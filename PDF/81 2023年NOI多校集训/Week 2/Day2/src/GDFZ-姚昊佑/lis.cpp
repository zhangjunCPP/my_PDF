#include<bits/stdc++.h>
using namespace std;
const int maxn=4010;
int n;
int cnt,ans=1e9+7,head[maxn],dep[maxn],fa[maxn][20];
int a[maxn];
int ss[maxn][maxn];
vector<int> vec[maxn]; 
struct edge{
	int nxt,to;
}e[maxn<<1];
inline void add(int u,int v){
	e[++cnt]={head[u],v};
	head[u]=cnt;
}
inline void dfs1(int u,int fa1,int k){
	dep[u]=dep[fa1]+1;
	fa[u][0]=fa1;
	if(k)	vec[k].push_back(u);
	for(int i=1;i<20;i++)	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa1)	continue;
		if(!fa1)	dfs1(t,u,t);
		else	dfs1(t,u,k);
	}
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])	x=fa[x][i];
	}
	if(x==y)	return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
inline int work(int x,int y,int u){
	int lis[maxn],dp[maxn],siz=0,lca=LCA(x,y);
	for(int i=x;i!=lca;i=fa[i][0])	lis[++siz]=a[i];
	for(int i=y,j=dep[x]+dep[y]-2*dep[lca]+1;i!=lca;i=fa[i][0],j--)	lis[j]=a[i];
	lis[++siz]=a[lca];
	siz=dep[x]+dep[y]-2*dep[lca]+1;
	for(int i=1;i<=siz;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(lis[i]>lis[j])	dp[i]=max(dp[i],dp[j]+1);
		}
	}
	return dp[siz];
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs1(1,0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				ss[i][j]=work(i,j,1);
//				printf("%d %d %d\n",i,j,ss[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	vec[j].clear();
		dfs1(i,0,0);
		int max1=0;
		for(int j=head[i];j;j=e[j].nxt){
			int t=e[j].to;
			for(int x=0;x<vec[t].size();x++){
				for(int y=0;y<vec[t].size();y++){
					if(x==y)	continue;
					max1=max(max1,ss[vec[t][x]][vec[t][y]]);
				}
			}
		}
		ans=min(ans,max1);
	}
	printf("%d",ans);
}
