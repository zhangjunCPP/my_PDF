#include <cstdio>
#include <initializer_list>
using ll=long long;
constexpr int N=100010,M=998244353;
int s[N],ch,n,m,data_id,q,x,y,i,hd[N],to[N<<1],nxt[N<<1],tot=1,fa[N],top[N],siz[N],son[N],dep[N];
ll fac[N*10],inv[N*10];
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48);
	x=ch&15;
	while((ch=getchar())>47)x=(x<<1)+(x<<3)+(ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){
	std::initializer_list<int>{(r(x),0)...};
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
inline void add(const int&x,const int&y){
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
}
inline ll pow(ll a,int b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%M;
		a=a*a%M;
		b>>=1;
	}
	return s;
}
void dfs1(const int&x){
	siz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(!siz[to[i]]){
			dep[to[i]]=dep[x]+1;
			fa[to[i]]=x;
			dfs1(to[i]);
			siz[x]+=siz[to[i]];
			if(siz[to[i]]>siz[son[x]])son[x]=to[i];
		}
}
void dfs2(const int&x){
	if(son[x]){
		top[son[x]]=top[x];
		dfs2(son[x]);
		for(int i=hd[x];i;i=nxt[i])
			if(!top[to[i]]){
				top[to[i]]=to[i];
				dfs2(to[i]);
			}
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline ll C(const int&n,const int&m){
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	r(n,m,data_id);
	for(i=1;i<n;i++){
		r(x,y);
		add(x,y);
	}
	for(i=1;i<=n;i++)r(s[i]);
	for(i=2;i<=m;i++)fac[i]=fac[i-1]*i%M;
	inv[m]=pow(fac[m],M-2);
	for(i=m-1;i>1;i--)inv[i]=inv[i+1]*(i+1)%M;
	dfs1(1);
	top[1]=1;
	dfs2(1);
	r(q);
	while(q--){
		r(x,y);
		i=dep[x]+dep[y]-(dep[lca(x,y)]<<1)+1;
		w(15);
	}
//	w(C(3,2));
	
	return 0;
}
