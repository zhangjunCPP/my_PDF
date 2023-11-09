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
constexpr int N=200005;
std::vector<int> G[N];
int n,m;
bool vis[N],used[N],on[N];
std::vector<int> ring[N];
int tot;
bool ins[N];
int sta[N],top;
int dfn[N],low[N],ti;
void dfs(int u,int fr){
	for(int i=G[u].size()-1,v;~i;--i){
		if(!ins[v=G[u][i]]&&!used[v]&&v!=fr) dfs(v,u);
		G[u].pop_back();
	}
	if(ins[u]){
		ring[++tot].emplace_back(u);
		vis[u]=1,used[u]=1;
		while(sta[top]!=u)
			ins[sta[top]]=0,used[sta[top]]=1,ring[tot].emplace_back(sta[top--]);
		return;
	}
	ins[sta[++top]=u]=1;
}
signed main(){
#ifndef LOCAL
	_fre("hamilton");
#endif
	io.read(n,m);
	for(int i=1;i<=n;++i)
		G[i].emplace_back(i+n),G[i+n].emplace_back(i);
	for(int i=1,u,v;i<=m;++i){
		io.read(u,v);
		G[u+n].emplace_back(v);
		G[v].emplace_back(u+n);
	}
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,0);
	bool ans=1;
	for(int i=1;i<=n;++i) ans&=used[i];
	if(!ans) return io.write("NO"),0;
	io.write("YES");
	for(int i=1;i<=tot;++i){
		io.write('\n',ring[i].size());
		for(int it:ring[i]) if(it<=n) io.write(' ',it);
	}
	return 0;
}