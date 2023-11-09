#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=5e5+5,MAXM=4e3+5,INF=0x3f3f3f3f;
int n,a[MAXN];
int tot=0,head[MAXN];
struct Edge{
	int to,nxt;Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){}
}edge[MAXN<<1];
inline void Add(int u,int v){edge[++tot]=Edge(v,head[u]);head[u]=tot;}

int del,maxn,cnt[MAXM],lis[MAXM][MAXM];
void dfs(int u,int fath){
	if(a[u]>lis[u][cnt[u]])lis[u][++cnt[u]]=a[u];
	else*lower_bound(lis[u]+1,lis[u]+cnt[u]+1,a[u])=a[u];
	maxn=max(maxn,cnt[u]);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;if(v==fath||v==del)continue;
		cnt[v]=cnt[u];
		for(int j=0;j<=cnt[u];j++)lis[v][j]=lis[u][j];
		dfs(v,u);
	}
}
int solve(int x){
	del=x;maxn=0;
	for(int i=1;i<=n;i++)if(del!=i){
		lis[i][cnt[i]=0]=-INF;dfs(i,0);
	}
	return maxn;
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);Add(u,v);Add(v,u); 
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int minn=n;
	for(int i=1;i<=n;i++)minn=min(minn,solve(i));
	printf("%d\n",minn);
	return 0;
}
