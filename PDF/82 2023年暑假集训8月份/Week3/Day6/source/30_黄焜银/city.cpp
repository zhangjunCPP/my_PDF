/*
t4
枚举1~k，依次作为首都
设当前枚举到i 
我们将i的所有连通块之间夹的路径上的城市合并到i 
然后继续做 
菊花图非常简单
链的情况…… 
 
卧槽没有菊花图
玩尼玛，打暴力 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,INF=0x7fffffff;
int fa[N];
int first[N],cnt;
struct Edge{
	int u,v,nex;
}a[N<<1];
void add(int u,int v){
	a[++cnt]={u,v,first[u]};
	first[u]=cnt;
}
void prework(int u,int dad){
	fa[u]=dad;
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(v!=dad)prework(v,u);
	}
}
int rd[N],cn,col[N],coll[N];
bool need[N];
void dfs(int u,int sd,bool f){
	rd[++cn]=col[u];
	if(col[u]==sd){
		if(!f)f=1;
		else for(int i=1;i<=cn;++i)need[rd[i]]=1;
		cn=0;
	}
	if(fa[u])dfs(fa[u],sd,f);
}
int n,k,i,x,y,d[N],j,anss=INF,ans;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&k);//小心k重名
	for(i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		++d[x],++d[y];
	} 
	for(i=1;i<=n;++i)scanf("%d",coll+i);
	for(i=1;i<=k;++i){
		for(j=1;j<=n;++j)col[j]=coll[j];
		ans=0;
		cn=INF;
		while(cn>1&&ans<anss){
			for(j=1;j<=n;++j)if(col[j]==i){prework(j,0);break;}
			for(j=1;j<=k;++j)need[j]=0;
			for(j=1;j<=n;++j)if(d[j]==1)cn=0,dfs(j,i,0);
			need[i]=1;
	//		for(j=1;j<=k;++j)printf("%d ",need[j]);putchar(10);
			for(j=1;j<=k;++j)if(need[j])++cn;
			ans+=cn-1;
			for(j=1;j<=n;++j)if(need[col[j]])col[j]=i;
		}
		anss=min(anss,ans);
	}
	printf("%d",anss);
	return 0;
}
/*
4 2
1 2
2 3
3 4
1 2 2 1
*/

