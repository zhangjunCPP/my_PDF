#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	constexpr int N=3e5+5;
	int n;
	std::vector<int> G[N];
	int siz[N],son[N],fa[N];
	void init_siz_dfs(int u){
		siz[u]=1;
		for(int v:G[u]){
			if(v!=fa[u]){
				fa[v]=u;
				init_siz_dfs(v);
				siz[u]+=siz[v];
				if(siz[v]>siz[son[u]]) son[u]=v;
			}
		}
	}
	int tmp_siz[N],all,rt,max_part;
	void re_calc_rt(int u,int fa){
		tmp_siz[u]=1;
		int now=0;
		for(int v:G[u]){
			if(v!=fa){
				re_calc_rt(v,u);
				tmp_siz[u]+=tmp_siz[v];
				if(tmp_siz[v]>now) now=tmp_siz[v];
			}
		}
		now=std::max(now,all-tmp_siz[u]);
		if(now<max_part) max_part=now,rt=u;
	}
	bool is_link(){
		if(G[1].size()!=1u||G[n].size()!=1u||G[1][0]!=2||G[n][0]!=n-1) return false;
		for(int i=2;i<n;++i)
			if(G[i].size()!=2u||(std::min(G[i][0],G[i][1])!=i-1)) return false;
		return true;
	}
	void _main_(){
		std::scanf("%d",&n);
		for(int i=2,u,v;i<=n;++i)
			std::scanf("%d%d",&u,&v),G[u].emplace_back(v),G[v].emplace_back(u);
		if(G[1].size()==n-1u){
			std::puts("2");
			for(int i=2;i<=n;++i) std::puts("1");
			return;
		}
		if(is_link()){
			for(int i=1;i<=n;++i){
				int x=i-1,y=n-i;
				if(x<y) std::printf("%d\n",i+(y>>1));
				else std::printf("%d\n",i-(x>>1));
			}
			return;
		}
		init_siz_dfs(1);
		for(int i=1;i<=n;++i){
			if(siz[son[i]]<n-siz[i]){
				all=n-siz[i],max_part=0x3f3f3f3f;
				re_calc_rt(fa[i],i);
			}
			else{
				all=siz[son[i]],max_part=0x3f3f3f3f;
				re_calc_rt(son[i],i);
			}
			std::printf("%d\n",rt);
		}
		return;
	}
}
signed main(){
	_fre_("balance",1,1);
	return QL::_main_(),0;
}
