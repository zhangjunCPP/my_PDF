/*
啥也不说了
打暴力 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=5e5+10;
int first[N],cnt;
struct Edge{
	int u,v,w,nex;
}a[M<<1];
void add(int u,int v,int w){
	a[++cnt]={u,v,w,first[u]};
	first[u]=cnt;
}
int x,y,ans,m;
void dfs(int u,int num){
	if(u==y)ans=max(ans,num);
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v,w=a[i].w;
		if(num*w<=m)dfs(v,num*w);
	}
}
int n,q,i;
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(i=2;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y,i);
		add(y,x,i);
	}
	while(q--){
		ans=-1;
		scanf("%d%d",&x,&y);
		dfs(x,1);
		printf("%d\n",ans);
	}
	return 0;
}


