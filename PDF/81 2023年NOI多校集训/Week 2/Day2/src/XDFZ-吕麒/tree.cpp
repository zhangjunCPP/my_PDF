#include<iostream>
#include<vector>
class IO{
protected:
	using reader=std::istream;
	using writer=std::ostream;
	using LIST=std::initializer_list<int>;
	reader&in;
	writer&out,&err;
public:
	IO():in{std::cin},out{std::cout},err{std::cerr}{
		in.tie(nullptr)->sync_with_stdio(false);
		out.tie(nullptr)->sync_with_stdio(false);
	}
	IO(reader&In,writer&Out,writer&Err):in{In},out{Out},err{Err}{
		in.tie(nullptr)->sync_with_stdio(false);
		out.tie(nullptr)->sync_with_stdio(false);
	}
	~IO(){}
	template<typename...Args>
	void read(Args&...args){void(LIST{(in>>args,0)...});}
	template<typename...Args>
	void write(Args&&...args){void(LIST{(out<<args,0)...});}
	template<typename...Args>
	void error(Args&&...args){void(LIST{(err<<args,0)...});}
	template<typename...Args>
	void writeln(Args&&...args){void(LIST{(out<<args,0)...}),out.put('\n');}
	template<typename...Args>
	void errorln(Args&&...args){void(LIST{(err<<args,0)...}),err.put('\n');}
}io;
#define _fre(s) {freopen(s".in","r",stdin),freopen(s".out","w",stdout);}
constexpr int N=1000005;
int n;
std::vector<int> G[N];
int dep[N],siz[N],son[N],fa[N],top[N];
void dfs(int u){
	siz[u]=1,son[u]=0;
	for(int v:G[u]){
		if(!dep[v]){
			dep[v]=dep[u]+1,fa[v]=u;
			dfs(v),siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
}
void dfs(int u,int tp){
	top[u]=tp;
	if(son[u]) dfs(son[u],tp);
	for(int v:G[u]) if(v!=son[u]&&v!=fa[u]) dfs(v,v);
}
auto lca=[](int x,int y){
	while(top[x]!=top[y])
		dep[top[x]]<dep[top[y]]?y=fa[top[y]]:x=fa[top[x]];
	return dep[x]<dep[y]?x:y;
};
auto dist=[](int x,int y){
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
};
int ans=0;
bool c[N];
void cc(int x){
	if(x==n+1){
		int mx=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				 if(c[i]==c[j]) mx=std::max(mx,dist(i,j));
			}
		}
		ans+=mx;
		return;
	}
	c[x]=0;
	cc(x+1);
	c[x]=1;
	cc(x+1);
}
signed main(){
#ifndef LOCAL
	_fre("tree");
#endif
	io.read(n);
	for(int i=2,u,v;i<=n;++i)
		io.read(u,v),G[u].emplace_back(v),G[v].emplace_back(u);
	dep[1]=1,dfs(1),dfs(1,1),cc(1);
	io.write(ans);
	return 0;
}
/*
链，菊花
就有点启发式合并啥的感觉了？
*/