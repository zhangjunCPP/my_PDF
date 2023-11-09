#include<bits/stdc++.h>
#define _fre(s,b) (b+1)&&(freopen(s".in","r",stdin),0),(b+1&&b)&&(freopen(s".out","w",stdout),0)
constexpr int N=100005,K=505;
using ll=long long;
int n,k,T[N],num[K];
ll cost[K],one;
struct edge{
	int ver;
	ll cost;
	edge():ver{},cost{}{}
	edge(int V,ll C):ver{V},cost{C}{}
	bool operator<(const edge&e)const{
		return cost>e.cost;
	}
};
std::vector<edge> G[N<<2];
ll sum[N<<2];
int idx[N];
void build(int p,int l,int r){
	if(l==r) return void(idx[l]=p);
	const int mid=(l+r)>>1;
	G[p].emplace_back(p<<1,0);
	G[p].emplace_back(p<<1|1,0);
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
class link{
protected:
	int L,R,x,val;
	void f(int p,int l,int r){
		if(L<=l&&r<=R) return void(G[x].emplace_back(p,val));
		const int mid=(l+r)>>1;
		if(L<=mid&&R>mid) f(p<<1,l,mid),f(p<<1|1,mid+1,r);
		else L<=mid?f(p<<1,l,mid):f(p<<1|1,mid+1,r);
	}
public:
	link(int l,int r,int p,int v):L{l},R{r},x{p},val{v}{f(1,0,n);}
};
void dij(){
	static std::priority_queue<edge> Q;
	__builtin_memset(sum,0x3f,sizeof sum);
	static bool used[N<<2]={};
	Q.emplace(idx[0],0),sum[idx[0]]=0;
	for(;!Q.empty();){
		int u=Q.top().ver;
		Q.pop();
		if(used[u]) continue;
		used[u]=1;
		for(edge e:G[u])
			if(sum[e.ver]>sum[u]+e.cost)
				Q.emplace(e.ver,sum[e.ver]=sum[u]+e.cost);
	}
}
signed main(){
	_fre("happy",1);
	std::scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) std::scanf("%d",&T[i]);
	for(int i=1;i<=k;++i) std::scanf("%d%lld",&num[i],&cost[i]);
	std::scanf("%lld",&one);
	build(1,0,n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			int l=i,r=std::upper_bound(T+1,T+n+1,T[i]+num[j]-1)-T-1;
			if(r<l||T[r]>T[i]+num[j]-1) continue;
			link(l,r,idx[i-1],cost[j]);
		}
		G[idx[i-1]].emplace_back(idx[i],one);
	}
	dij();
	for(int i=1;i<=n;++i) std::printf("%lld\n",sum[idx[i]]-sum[idx[i-1]]);
	return 0;
}
/*
amazing!graph!
too many edges...
lhz/bx/bx/bx 
*/
