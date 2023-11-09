#include<stdio.h>

template <typename dy> dy max(dy x,dy y){return x>y?x:y;}
template <typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=1e6+5;
struct dy{
	int v,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int n,m,ans,d[N],s[N],ci;
bool f[N],vis[N];
void dfs(int u,int dad){
	f[u]=1;s[ci++]=u;vis[u]=1;
//	if(ci>3){
////	f[u]=0;
//	ci--;return;}
//	printf(":%d\n",u);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(!f[v]) dfs(v,u);
		else if(v!=dad&&ci==3){
			int sum=0;
			for(int i=ci-1;s[i+1]!=v;i--){
//				printf("%d ",s[i]);
				sum+=d[s[i]];
			}
//			printf("\n");
			ans=max(sum-3,ans);
			f[u]=0;ci--;return ;
		}
	}
	f[u]=0;ci--;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		ans=0;scanf("%d%d",&n,&m);
		while(m--){
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
			d[u]++;d[v]++;
		}
		for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
		for(int i=1;i<=n;i++) {ans=max(ans,d[i]);d[i]=0;vis[i]=0;head[i]=0;}
		for(int i=1;i<=cnt;i++) edge[i].v=edge[i].next=0;
		printf("%d\n",ans);
	}
	return 0;
} 
