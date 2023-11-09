#include<bits/stdc++.h>
#define _fre_(f,x,y) \
{ \
	if(x) std::freopen(f".in","r",stdin); \
	if(y) std::freopen(f".out","w",stdout); \
}
namespace QL{
	constexpr int N=23,M=N*N/2;
	int n,m,q;
	std::array<std::pair<int,int>,M> E;
	std::vector<int> e;
	std::array<std::vector<std::pair<int,int>>,N> G;
	std::array<int,N> Q;
	std::array<bool,N> must;
	char sub[N];
	int ret,s;
	int valid(){
		for(int i=1;i<=n;++i)
			if(((s>>i)&1)&&__builtin_popcount(s&Q[i])<2) return 0;
		return 1;
	}
	constexpr int mod=998244353;
	int qpow(long long a,int x){
		int ret=1;
		for(;x>>=1;a=a*a%mod) if(x&1) ret=ret*a%mod;
		return ret;
	}
	void dfs(unsigned p){
		if(p==e.size()){
			ret+=valid();
			return;
		}
		if(e.size()>=25&&valid()){
			ret+=qpow(2,e.size()-p+2);
			return;
		}
		dfs(p+1);
		int a=Q[E[e[p]].first],b=Q[E[e[p]].second];
		Q[E[e[p]].first]|=1<<E[e[p]].second;
		Q[E[e[p]].second]|=1<<E[e[p]].first;
		dfs(p+1);
		Q[E[e[p]].first]=a,Q[E[e[p]].second]=b;
	}
	int qry(){
		e.clear();
		std::fill_n(Q.begin()+1,n,0);
		std::fill_n(must.begin()+1,n,false);
		s=0;
		for(int i=1;i<=n;++i){
			if(sub[i]=='1'){
				s|=1<<i;
				int cnt=0;
				for(auto it:G[i])
					if(sub[it.first]=='1'){
						++cnt;
						if(!must[it.second]) e.emplace_back(it.second);
					}
				if(cnt<2) return 0;
				else if(cnt==2){
					for(auto it:G[i])
						if(sub[it.first]=='1'){
							if(!must[it.second]) e.pop_back(),must[it.second]=true;
							Q[E[it.second].first]|=1<<E[it.second].second;
							Q[E[it.second].second]|=1<<E[it.second].first;
						}
				}
			}
		}
		for(auto itr=e.begin();itr!=e.end();)
			if(must[*itr]) itr=e.erase(itr);
			else ++itr;
		if(e.empty()) return 1;
		std::sort(e.begin(),e.end());
		e.erase(std::unique(e.begin(),e.end()),e.end());
		ret=0;
		dfs(0);
		return ret;
	}
	signed _main_(){
		std::scanf("%d%d",&n,&m);
		std::fill_n(G.begin()+1,n,std::vector<std::pair<int,int>>());
		for(int u,v,i=1;i<=m;++i){
			std::scanf("%d%d",&u,&v);
			G[u].emplace_back(v,i);
			G[v].emplace_back(u,i);
			E[i]={u,v};
		}
		std::scanf("%d",&q);
		for(int i=1;i<=q;++i){
			std::scanf("%s",sub+1);
			std::printf("%d\n",qry());
		}
		return 0;
	}
}
signed main(){
	 _fre_("big",1,1);
	return QL::_main_();
}
/*
状压？ 
都>=2是困难的，所以<2应该是相对简单的。
也许是大力容斥。 
这个方向的复杂度不是很对得上。 
考虑点集内每一个点，只有两条边的，这两条边必选。
超过两条呢？
没有必选，C(n,2)*2^(n-2)
有一条，C(n-1,1)*2^(n-2)
不少于两条 ，2^(n-get)
直接算，会重吗？显然会 
不管了，暴力。 
*/ 
