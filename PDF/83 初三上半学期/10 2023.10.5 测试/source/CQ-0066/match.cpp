#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,ans;
int head[N],cnt,d[N];
struct node{
	int nxt,v;
}tree[N<<1];
void add(int u,int v){
	tree[++cnt]={head[u],v},head[u]=cnt,++d[u];
	tree[++cnt]={head[v],u},head[v]=cnt,++d[v];
}
int depth[N];
void dfs(int x,int fa){
	depth[x]=depth[fa]+1;
	for(int i=head[x],y;i;i=tree[i].nxt){
		if(!depth[y=tree[i].v]) dfs(y,x);
		else if(abs(depth[x]-depth[y])==2) ans=max(ans,3);
	}
}
void Init(){
	cnt=1,ans=0;
	for(int i=1;i<=n;++i) head[i]=d[i]=depth[i]=0;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),Init();
		for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),add(u,v);
		for(int i=1;i<=n;++i) ans=max(ans,d[i]);
		dfs(1,0);
		printf("%d\n",ans);
	}


	return 0;
}
