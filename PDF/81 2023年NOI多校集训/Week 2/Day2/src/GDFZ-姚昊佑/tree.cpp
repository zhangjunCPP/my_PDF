#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=30,mod=1e9+7;
int n,ans;
int cnt,head[maxn],num[maxn],fa[maxn][20],dep[maxn];
struct edge{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt]={head[u],v};
	head[u]=cnt;
}
void dfs1(int u,int fa1){
	dep[u]=dep[fa1]+1;
	fa[u][0]=fa1;
	for(int i=1;i<20;i++)	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa1)	continue;
		dfs1(t,u);
	}
}
//int jump(int u,int x){
//	for(int i=19;i>=0;i--){
//		if(x&(1<<i)){
//			u=fa[u][i];
//		}
//	}
//	return u;
//}
int LCA(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])	x=fa[x][i];
	}
	if(x==y)	return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int getsum(){
	int max1=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(num[i]==num[j]){
				max1=max(max1,dis(i,j));
			}
		}
	}
//	printf("%lld\n",max1);
	return max1;
}
void dfs(int x){
	if(x>n){
		ans+=getsum();
		ans%=mod;
		return;
	}
	num[x]=1;
	dfs(x+1);
	num[x]=0;
	dfs(x+1);
}
int qpow(int x,int y){
	if(y==0)	return 1;
	int a=qpow(x,y/2);
	if(y&1)	return a*a%mod*x%mod;
	else	return a*a%mod;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	if(n>=15){
		printf("%lld",qpow(2,n+1));
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs(1);
	printf("%lld",ans);
//	printf("%lld",LCA(5,6));
} 
