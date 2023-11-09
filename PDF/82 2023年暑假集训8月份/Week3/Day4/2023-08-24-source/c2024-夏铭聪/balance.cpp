#include<stdio.h>

template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=3e5+5;
struct dy{
    int v,next;
}edge[N<<1];
int head[N],cnt=1;
void add(int u,int v){
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n,size[N],mx=0x3f3f3f3f,zx;
void dfs(int u,int dad){
	size[u]=1;int ma=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=dad)
		{
			dfs(v,u);
			size[u]+=size[v];
			ma=max(ma,size[v]);
		}
	}
	ma=max(ma,n-size[u]+1);
	if(ma<mx){mx=ma;zx=u;}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	scanf("%d",&n);bool f1=1,f2=1;
	for(int i=1,u,v;i<=n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		if(u!=i||v!=i+1) f1=0;
		if(u!=1||v!=i+1) f2=0;
	}
	if(f1)
	{
		for(int i=1;i<=n;i++)
			if(i-1>n-i) printf("%d\n",1+(i-1)/2);
			else printf("%d\n",n-(n-i)/2);
	}
	if(f2)
	{
		for(int i=1;i<=n;i++)
			if(i!=1) puts("1");
			else puts("2");
	}
	else
	{
		dfs(1,0);
		for(int i=1;i<=n;i++) printf("%d\n",zx);
	}
    return 0;
}