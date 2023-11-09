#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace MAIN{
	constexpr int N=1e5+5,M=2e5+5,Q=25,mod=1e9+7;
	using ll=long long;
	int n,m,q,k,test_id;
	struct edge{
		int ver,cost;
		edge():ver{},cost{}{}
		edge(int _ver,int _cost):ver{_ver},cost{_cost}{}
	};
	std::vector<edge> G[N];
	std::vector<int> H[N];
	ll dis[N];
	void dij(int s){
		static bool used[N];
		memset(used+1,0,sizeof(bool)*n);
		memset(dis+1,0x3f,sizeof(ll)*n);
		static std::priority_queue<std::pair<ll,int>> q;
		q.emplace(dis[s]=0ll,s);
		for(int u;!q.empty();){
			u=q.top().second,q.pop();
			if(used[u]) continue;
			used[u]=true;
			for(edge e:G[u])
				if(dis[e.ver]>dis[u]+e.cost)
					q.emplace(-(dis[e.ver]=dis[u]+e.cost),e.ver);
		}
	}
	void _main_(){
		std::scanf("%d%d%d%d%d",&n,&m,&q,&k,&test_id);
		for(int i=1,u,v,w;i<=m;++i){
			std::scanf("%d%d%d",&u,&v,&w);
			G[u].emplace_back(v,w);
			G[v].emplace_back(u,w);
		}
		if(k==0){
			for(int i=1,s,t;i<=q;++i){
				static int que[N],head,tail;
				static int f[N],ind[N];
				std::scanf("%d%d",&s,&t);
				dij(s);
				if(dis[t]==0x3f3f3f3f){
					std::puts("0");
					continue;
				}
				for(int i=1;i<=n;++i) H[i].clear(),f[i]=0;
				for(int u=1;u<=n;++u)
					for(edge e:G[u])
						if(dis[e.ver]==dis[u]+e.cost) H[u].emplace_back(e.ver),++ind[e.ver];
				f[que[head=tail=0]=s]=1;
				for(int u;head<=tail;)
					for(int v:H[u=que[head++]])
						if(f[v]=(f[v]+f[u])%mod,--ind[v]==0) que[++tail]=v;
				std::printf("%d\n",f[t]);
			}
			return;
		}
		return;
	}
}
signed main(){
	_fre_("dream",1,0);
	return MAIN::_main_(),0;
}
