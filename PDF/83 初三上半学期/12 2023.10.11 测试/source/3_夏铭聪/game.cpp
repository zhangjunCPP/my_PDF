#include<stdio.h>

const int N=1e5+5;
struct dy{
	int v,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int n,m,k;
char an[1005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	an['P']='G';an['G']='P';
	int T;scanf("%d",&T);
	while(T--){
		char s[N]={};
		scanf("%d%d%d%s",&n,&m,&k,s);
		for(int i=1;i<=m;i++){
			int u,v;scanf("%d%d",&u,&v);
//			add(u,v);add(v,u);
		}
		printf("%c\n",an[s[(m-n+1)%k]]);
//		for(int i=1;i<=n;i++) head[i]=0;
	}
	return 0;
}

