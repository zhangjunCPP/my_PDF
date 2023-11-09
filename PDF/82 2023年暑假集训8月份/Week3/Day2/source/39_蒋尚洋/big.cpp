//这种东西,如果说我反演?
//如果钦定a1,a2,a3,...度数<=1怎么做?
//那么使用了几条导出子图的边和几条去其他点的边
//其他点的方案数好说,就是每条边选/不选:2^n
//问题在于使用了几条
//欸不对啊内部边只能是一条边
//a---b
//这样
//能否考虑DP求出
//不会了不会了,打暴力 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
int G[30],n,m;
//namespace bf{
//	ll g[1<<19],val[1<<19],nlink[1<<19][25];//nlink:s中的点不连u(且度数<=1);val:s中的点乱连自己内部;g:度数<=1
//	ll calc(int subs){
//		ll ans=0;g[0]=1;
//		val[0]=1;
//		for(int s=1;s<(1<<n);s++){
//			int u=__builtin_ffs(s);
//			
//		}
//		for(int s=1;s<(1<<n);s++)
//		if((s|subs)==subs){
//			int u=__builtin_ffs(s),frs=s^(1<<u-1);
//			val[s]=(val[frs]<<__builtin_popcount(G[u]&s))%mod;
//			for(int v=1;v<=n;v++)nlink[s][v]=nlink[frs][v];
//			for(int v=1;v<=n;v++)//这里的v原来是可以多个连u的,但是现在只能一个
//			if(frs>>v-1&1)(g[s]+=g[frs^(1<<v-1)])%=mod;
//			g[s]=(g[frs]*__builtin_popcount(G[u]&(subs^s)))%mod;
//		}
//		for(int s=subs;s;s=s-1&subs)
//		(ans+=(__builtin_popcount(s)&1?mod-1:1)*g[s]%mod*val[subs^s])%=mod;
//		return ans;
//	}
//}
//namespace bf{
//	ll g[1<<10],nlink[1<<10][1<<10],val[1<<10];
//	ll calc(int subs){
//		ll ans=0;g[0]=1;
//		val[0]=1;
//		for(int s=1;s<(1<<n);s++)
//		if((s|subs)==subs){
//			int u=__builtin_ffs(s),frs=s^(1<<u-1);
//			val[s]=(val[frs]<<__builtin_popcount(G[u]&s))%mod;
//			for(int v=1;v<=n;v++)//这里的v原来是可以多个连u的,但是现在只能一个
//			if(frs>>v-1&1)(g[s]+=g[frs^(1<<v-1)])%=mod;
//			g[s]=(g[frs]*__builtin_popcount(G[u]&(subs^s)))%mod;
//		}
//		for(int s=subs;s;s=s-1&subs)
//		(ans+=(__builtin_popcount(s)&1?mod-1:1)*g[s]%mod*val[subs^s])%=mod;
//		return ans;
//	}
//}
namespace bf{
	struct edge_t{int u,v;}e[100];
	ll calc(int s){
		int tot=0,ans=0;
		for(int u=1;u<=n;u++)
		for(int v=1;v<u;v++)
		if((s>>u-1&1)&&(s>>v-1&1)&&(G[u]>>v-1&1))
		e[++tot]={u,v};
		for(int es=0;es<(1<<tot);es++){
			int deg[20]{};
			for(int i=1;i<=tot;i++)
			if(es>>i-1&1)deg[e[i].u]++,deg[e[i].v]++;
			int x=1;
			for(int i=1;i<=n;i++)
			if(s>>i-1&1)x&=deg[i]>=2;
			ans+=x;
		}return ans;
	}
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	cin>>n>>m;
	for(int u,v;m--;)scanf("%d%d",&u,&v),G[u]|=1<<v-1,G[v]|=1<<u-1;
	int q;cin>>q;
	for(char str[30];q--;){
		scanf("%s",str);int s=0;
		for(int i=0;i<n;i++)s|=str[i]-'0'<<i;
		printf("%lld\n",bf::calc(s));
	} 
	return 0;
}
