#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define pi pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAXN=1e6+5,MOD=1e9+7;
inline ll ksm(ll x,int y){ll mul=1;while(y){if(y&1)mul=mul*x%MOD;x=x*x%MOD;y>>=1;}return mul;}
int n;pi e[MAXN];
int tot=0,head[MAXN];
struct Edge{
	int to,nxt;Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){} 
}edge[MAXN<<1];
inline void Add(int u,int v){edge[++tot]=Edge(v,head[u]);head[u]=tot;}

namespace TreeChain{
	int fa[MAXN],siz[MAXN],son[MAXN],dep[MAXN],top[MAXN];
	void dfs1(int u,int fath){
		fa[u]=fath;dep[u]=dep[fath]+1;siz[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;if(v==fath)continue;
			dfs1(v,u);siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
	void dfs2(int u,int tp){
		top[u]=tp;if(!son[u])return;dfs2(son[u],tp);
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;if(v==fa[u]||v==son[u])continue;
			dfs2(v,v);
		}
	}
	inline int LCA(int u,int v){while(top[u]!=top[v]){if(dep[top[u]]<dep[top[v]])swap(u,v);u=fa[top[u]];}return dep[u]<dep[v]?u:v;}
	inline int dis(int u,int v){return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
}using namespace TreeChain;
namespace SolveA{
	inline bool checkA(){
		for(int i=1;i<n;i++){
			if(e[i].fi>e[i].se)swap(e[i].fi,e[i].se);
			if(e[i].fi!=i||e[i].se!=i+1)return false;
		}
		return true;
	}
	ll p[MAXN],s[MAXN];
	inline void solveA(){
		p[0]=1;for(int i=1;i<=n;i++)p[i]=(p[i-1]<<1)%MOD;
		for(int i=1;i<=n;i++)s[i]=(s[i-1]+i*p[i-1])%MOD;
		if(n<=1000){
			ll sum=(n-2+(n-1)*ksm(2,n-2))%MOD;
			for(int i=n-1;i>1;i--){
				sum+=max(i-1,n-i-1);
				for(int j=2;j<i;j++)
					sum=(sum+max(i-1,n-j)*ksm(2,i-j-1))%MOD;
			}
			printf("%lld\n",(sum<<1)%MOD);
		}else{
			ll sum=(n-2+(n-1)*ksm(2,n-2))%MOD;
			for(int i=n-1;i>1;i--){
				sum+=max(i-1,n-i-1);
				if(i-1<=n-i+1){
					sum=(sum+(n-i)*(p[i-2]-1)+s[i-2])%MOD;							// 2~i-1
				}else{
					sum=(sum+p[2*i-n-1]*((i-1)*(p[n-i-1]-1)%MOD+s[n-i-1]%MOD))%MOD;	// 2~n-i
					sum=(sum+(i-1)*(p[2*i-n-1]-1))%MOD;								// n-i+1~i-1 
				}
			}
			printf("%lld\n",(sum<<1)%MOD);
		}
		exit(0);
	}
}using namespace SolveA;
namespace SolveB{
	inline bool checkB(){
		for(int i=1;i<n;i++)if(e[i].fi^1&&e[i].se^1)return false;
		return true;
	}
	inline void solveB(){
		if(n==1)printf("0\n");
		else if(n==2)printf("2\n");
		else if(n==3)printf("12\n");
		else printf("%lld\n",ksm(2,n+1));
		exit(0);
	}
}using namespace SolveB;
namespace Solve1{
	inline int calc(int s){
		int maxn=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			if((s>>i-1&1)==(s>>j-1&1))maxn=max(maxn,dis(i,j));
		return maxn;
	}
	inline void solve1(){
		int sum=0;
		for(int i=0;i<(1<<n);i++)
			sum+=calc(i);
		printf("%d\n",sum);
		exit(0);
	}
}using Solve1::solve1;

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);solveA();
	for(int i=1;i<n;i++){
		scanf("%d%d",&e[i].fi,&e[i].se);
		Add(e[i].fi,e[i].se);Add(e[i].se,e[i].fi);
	}
	dfs1(1,0);dfs2(1,1);
	if(n<=10)solve1();
	if(checkB())solveB();
	if(checkA())solveA();
	return 0;
}
