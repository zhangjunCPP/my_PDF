#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace MAIN{
	using ll=long long;
	constexpr int N=1e5+5,M=1e6+5,LOG=19,mod=998244353;
	int n,m,q,test_id,s[N];
	std::vector<int> G[N];
	int fa[LOG][N],dep[N];
//	int z[LOG][N],o[LOG][N];
//	int zd[LOG][N],op[LOG][N];
	int fac[M],inv[M];
	void dfs(int u){
		dep[u]=dep[fa[0][u]]+1;
		for(int v:G[u]) if(v!=fa[0][u])
			fa[0][v]=u,dfs(v);
//		z[0][u]=!s[u];
//		o[0][u]=s[u];
//		zd[0][u]=u==1||(!s[u]&&s[u]!=s[fa[0][u]]);
//		op[0][u]=u==1||(s[u]&&s[u]!=s[fa[0][u]]);
		for(int k=1;k<LOG;++k){
			fa[k][u]=fa[k-1][fa[k-1][u]];
//			z[k][u]=z[k-1][u]+z[k-1][fa[k-1][u]];
//			o[k][u]=o[k-1][u]+o[k-1][fa[k-1][u]];
//			zd[k][u]=zd[k-1][u]+zd[k-1][fa[k-1][u]];
//			op[k][u]=op[k-1][u]+op[k-1][fa[k-1][u]];
		}
	}
	int LCA(int u,int v){
		if(dep[u]<dep[v]) u^=v^=u^=v;
		for(int k=LOG-1;~k;--k) if(dep[fa[k][u]]>=dep[v]) u=fa[k][u];
		if(u==v) return u;
		for(int k=LOG-1;~k;--k) if(fa[k][u]!=fa[k][v]) u=fa[k][u],v=fa[k][v];
		return fa[0][u];
	}
	int find(int u,int v){
		for(int k=LOG-1;~k;--k)
			if(dep[fa[k][u]]>dep[v]) u=fa[k][u];
		return u;
	}
	int calc(int u,int v,int f[LOG][N]){
		int ret=0;
		for(int k=LOG-1;~k;--k)
			if(dep[fa[k][u]]>=dep[v]) ret+=f[k][u],u=fa[k][u];
		return ret;
	}
	int qpow(ll a,int x){
		int ret=1;
		for(;x;x>>=1,a=a*a%mod) if(x&1) ret=ret*a%mod;
		return ret;
	}
	int C(int n,int m){
		return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
	}
	int qry(int u,int v){
		static int q1[N],q2[N];
		int t1=0,t2=0;
		int lca=LCA(u,v);
		int ret=C(m,2*(dep[u]+dep[v]-dep[lca]*2+1));
		while(u!=lca) q1[++t1]=u,u=fa[0][u];
		while(v!=lca) q2[++t2]=v,v=fa[0][v];
		static int q[N];
		int t=0;
		for(int i=1;i<=t1;++i) q[++t]=q1[i];
		for(int i=t1-1;i;--i) q[++t]=q2[i];
		for(int i=1;i<=t;){
			int j=i;
			for(;j<=t&&s[q[j]]==s[q[i]];++j);
			--j;
			if(j!=i) ret=1ll*ret*qpow(2,j-i)%mod;
			i=j+1;
		}
		return ret;
//		int ret=1;
//		int lca=LCA(u,v);
//		int x=find(u,lca),y=find(v,lca);
//		int cnt[2]={};
//		cnt[0]=calc(u,x,z)-calc(u,find(u,x),zd)+calc(v,y,z)-calc(v,find(v,y),zd);
//		cnt[1]=calc(u,x,o)-calc(u,find(u,x),op)+calc(v,y,o)-calc(v,find(v,y),op);
////		std::printf("%d %d %d %d %d %d %d\n",lca,x,y,calc(u,x,z),calc(v,x,z),cnt[0],cnt[1]);
//		++cnt[s[lca]];
//		if(s[x]==s[y]){
//			if(s[lca]!=s[y]) ----cnt[s[x]];
//		}
//		else{
//			if(s[lca]==s[x]) --cnt[s[y]];
//			else --cnt[s[x]];
//		}
//		ret=qpow(2,cnt[0]+cnt[1]);
//		std::printf("%d %d %d %d\n",cnt[0],cnt[1],ret,C(m,2*(dep[u]+dep[v]-dep[lca]*2+1)));
//		return 1ll*ret*C(m,2*(dep[u]+dep[v]-dep[lca]*2+1))%mod;
	}
	void _main_(){
		std::scanf("%d%d%d",&n,&m,&test_id);
		fac[0]=inv[0]=1;
		for(int i=1;i<=m;++i) fac[i]=1ll*fac[i-1]*i%mod;
//		inv[m]=qpow(fac[m],mod-2);
//		for(int i=m-1;i;--i) inv[i]=inv[i+1]*(i+1ll)%mod;
		for(int i=0;i<=m;++i) inv[i]=qpow(fac[i],mod-2);//,std::printf("%d %d\n",fac[i],inv[i]);
//		std::printf("%d\n",C(6,2));
		for(int i=1;i<=n;++i) std::scanf("%d",&s[i]);
		for(int i=2,u,v;i<=n;++i)
			std::scanf("%d%d",&u,&v),G[u].emplace_back(v),G[v].emplace_back(u);
		dfs(1);
		std::scanf("%d",&q);
		for(int u,v;q--;)
			std::scanf("%d%d",&u,&v),std::printf("%d\n",qry(u,v));
		return;
	}
}
signed main(){
	_fre_("umi",1,1);
	return MAIN::_main_(),0;
}
