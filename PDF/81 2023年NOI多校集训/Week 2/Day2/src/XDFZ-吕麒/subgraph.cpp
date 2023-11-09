#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
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
using ll=long long;
int n,m;
ll MV,NV,BV;
std::vector<int> R[N];
std::set<int> G[N],S;
int pre[N];
int get(int x){
	return x==pre[x]?x:pre[x]=get(pre[x]);
}
void merge(int x,int y){
	pre[get(x)]=get(y);
}
std::vector<int> T[N];
int kkk;
ll mxv=-0x3f3f3f3f3f3f3f3f,as;
void dfs(){
	static bool vis[1<<15]{};
	auto chk=[](int chos){
		bool r=0;
		if(vis[chos]) return r;
		for(int i=1;i<=n;++i) pre[i]=i,T[i].clear();
		for(int i=1;i<=n;++i)
			for(int j:R[i]) if((chos>>(i-1)&1)&&(chos>>(i-1)&1)) merge(i,j);
		for(int i=1;i<=n;++i) T[get(i)].emplace_back(i);
		for(int i=1;i<=n;++i){
			if(T[i].empty()) continue;
			bool f=1;
			int nv=0,mv=0,bv=0;
			for(int nd:T[i]){
				++nv;
				int tot=0;
				for(int ot:R[nd])
					if(get(ot)!=get(i)) ++bv;
					else ++mv,++tot;
				f&=tot>=kkk;
				if(!f) break;
			}
			if(!f) continue;
			mv/=2;
			ll pos=mv*MV-nv*NV+bv*BV;
			// if(kkk==1){
				// io.errorln(mv,' ',nv,' ',bv,' ',pos);
			// }
			r=1;
			if(pos>=mxv) mxv=pos,as=kkk;
		}
		return r;
	};
	__builtin_memset(vis,0,sizeof vis);
	for(int s=(1<<15)-1;s;--s){
		if(chk(s)){
			for(int t=s;t;t=(t-1)&s){
				vis[t]=1;
			}
		}
	}
}
signed main(){
#ifndef LOCAL
	_fre("subgraph");
#endif
	io.read(n,m,MV,NV,BV);
	for(int i=1,u,v;i<=m;++i)
		io.read(u,v),R[u].emplace_back(v),R[v].emplace_back(u);
	if(n<=15){
		for(kkk=1;kkk<=n;++kkk) dfs();
		io.write(as,' ',mxv);
		return 0;
	}
	ll max_val=-0x3f3f3f3f3f3f3f3f,ans=0;
	for(int i=1;i<=n;++i) S.emplace(i),G[i].insert(R[i].begin(),R[i].end());
	for(int k=1;k<=n&&!S.empty();++k){
		while(1){
			static int que[N],head,tail;
			head=1,tail=0;
			for(auto itr=S.begin();itr!=S.end();)
				if((int)G[*itr].size()<k) que[++tail]=*itr,itr=S.erase(itr);
				else ++itr;
			if(tail<head) break;
			for(int u;head<=tail;){
				for(int v:G[u=que[head++]]){
					if(G[v].find(u)!=G[v].end()) G[v].erase(u);
					if((int)G[v].size()<k&&S.find(v)!=S.end()) S.erase(que[++tail]=v);
				}
				G[u].clear();
			}
		}
		if(S.empty()) break;
		for(int it:S) pre[it]=it,T[it].clear();
		for(int it:S)
			for(int ot:G[it]) merge(ot,it);
		for(int it:S) T[get(it)].emplace_back(it);
		for(int it:S){
			if(T[it].empty()) continue;
			int nv=0,mv=0,bv=0;
			for(int nd:T[it]){
				++nv;
				for(int ot:R[nd])
					if(S.find(ot)==S.end()||get(ot)!=it) ++bv;
					else if(S.find(ot)!=S.end()&&get(ot)==it) ++mv;
			}
			mv/=2;
			ll pos=mv*MV-nv*NV+bv*BV;
			if(pos>=max_val) max_val=pos,ans=k;
			// if(k==14){
				// io.errorln(max_val,' ',pos,'\n');
			// }
		}
	}
	io.write(ans,' ',max_val);
	return 0;
}
/*
我不管，每道题我都要开
大力模拟，然而挂大样例
你不要慌，能搞
其实这个似乎是反着来更合适，但……懒
还是过不去大样例……
好，裸暴搜
我摆烂！
*/
