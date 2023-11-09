/*
t1
任意两条边共用至少一个端点
又没有重边自环
那就是两条边必须共用一个端点 
这是个什么呢？
 
所以我们只能包含一个点的所有出边
极特殊的，三元环合法 

考虑怎么处理三元环
n有1e6，空间只有500mb，邻接矩阵显然不现实
但我们可以直接dfs啊 

突然意识到
图不一定联通
这对我们来说还是有影响
三元环要改，不然
1
5 4
1 2
3 4
4 5
5 3 
ans=3

读入量较大，开个快读 
*/
#include<bits/stdc++.h>
using namespace std;
inline int re(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
const int N=1e6+10;
bool vis[N],f1,f3;
int cnt,first[N];
struct Edge{
	int u,v,nex;
}a[N<<1];
void add(int u,int v){
	a[++cnt]={u,v,first[u]};
	first[u]=cnt;
}
int ans,fa[N];
void dfs(int u){
	if(ans>=3)return;
	vis[u]=1;
	for(int i=first[u];i;i=a[i].nex){
		if(ans>=3)return;
		int v=a[i].v;
		if(!vis[v]){
			fa[v]=u;
			dfs(v);
		}
		else if(fa[fa[u]]==v)ans=max(ans,3);
	}
}
int n,m,i,d[N],x,y;
void work(){
	n=re();
	m=re();
	cnt=ans=f1=0;
	for(i=1;i<=n;++i)first[i]=d[i]=vis[i]=0;
	for(i=1;i<=m;++i){
		x=re();
		y=re();
		add(x,y),add(y,x);
		++d[x],++d[y];
		if(y!=x+1||m!=n-1)f1=1;
		if(y!=x%n+1||m!=n)f3=1;
	}
	for(i=1;i<=n;++i)ans=max(ans,d[i]);
	if(ans<3&&f1&&f3){
		for(i=1;i<=n;++i){
			if(d[i]!=2)continue;
			int x=i,y=a[first[x]].v,z=a[a[first[x]].nex].v;
			if(d[y]!=2)continue;
			if(d[z]!=2)continue;
			if(a[first[y]].v==z||a[a[first[y]].nex].v==z)ans=max(ans,3);
		}
	}
	printf("%d\n",ans);
}
int T;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--)work(); 
	return 0;
}
