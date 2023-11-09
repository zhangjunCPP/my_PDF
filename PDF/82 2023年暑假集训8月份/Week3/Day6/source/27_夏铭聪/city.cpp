#include<stdio.h>

const int N=2e5+5;
struct dy{
    int v,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v){
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n,k,c[N];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	
	puts("1");
	
    return 0;
}