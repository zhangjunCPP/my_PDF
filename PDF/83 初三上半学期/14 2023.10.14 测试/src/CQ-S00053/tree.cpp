#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,MOD=998244353;
int n,fa[N];
int head[N],cnt;
struct node{
	int nxt,v,id;
}tree[N<<1];
void addd(int u,int v,int id){
	tree[++cnt]={head[u],v,id},head[u]=cnt;
	tree[++cnt]={head[v],u,id},head[v]=cnt;
}
int dp[N][3],f[N],g[N];
void add(int &x,int y){ x+=y; if(x>=MOD) x-=MOD; }
int ad(int x,int y){ x+=y; if(x>=MOD) x-=MOD; return x; }
void po(int &x,int y){ x=1ll*x*y%MOD; }
void dfs(int x,int fr){
	dp[x][0]=dp[x][2]=1;// 0;son;fa;e;l
	int num=0,now=1;
	for(int i=head[x],y;i;i=tree[i].nxt) if((y=tree[i].v)!=fa[x]){
		fa[y]=x,dfs(y,tree[i].id);
		po(dp[x][0],ad(f[y],dp[y][2]));
		if(fr<tree[i].id) po(dp[x][2],ad(dp[y][0],dp[y][1]));
		else po(dp[x][2],ad(dp[y][2],f[y]));
		
		po(dp[x][1],ad(dp[y][0],dp[y][1])),add(dp[x][1],1ll*now*ad(dp[y][0],g[y])%MOD);
		po(f[x],ad(dp[y][0],dp[y][1])),po(g[x],ad(dp[y][0],dp[y][1]));
		if(tree[i].id<fr) add(f[x],1ll*now*ad(dp[y][0],g[y])%MOD);
		else add(g[x],1ll*now*ad(dp[y][0],g[y])%MOD);
		
		po(now,ad(dp[y][2],f[y]));
		++num;
	}
}
struct use{
	int u,v;
}cn[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;++i) scanf("%d%d",&cn[i].u,&cn[i].v);
	for(int i=n-1;i;--i) addd(cn[i].u,cn[i].v,i);
	dfs(1,0);
	printf("%d\n",ad(dp[1][0],dp[1][1]));
	return 0;
}	
