#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace MAIN{
	constexpr int N=55,K=505;
	int n,m,k;
	struct edge{
		int ver,cost;
		edge():ver{},cost{}{}
		edge(int _ver,int _cost):ver{_ver},cost{_cost}{}
	};
	std::vector<edge> G[N];
	int r[N][N];
	using ll=long long;
	void _main_(){
		std::scanf("%d%d%d",&n,&m,&k);
		memset(r,-1,sizeof r);
		for(int u,v,w,i=1;i<=m;++i)
			std::scanf("%d%d%d",&u,&v,&w),G[u].emplace_back(v,w),r[v][u]=w;
		{
			struct node{
				ll val;
				std::basic_string<int> path;
				node():val{},path{}{}
				node(ll _val,std::basic_string<int> _path):val{_val},path{_path}{}
				bool operator<(const node &it)const{return val>it.val||(val==it.val&&path>it.path);}
			};
			static std::set<node> S[N];
			static std::priority_queue<node> q;
			std::basic_string<int> st{};
			st+=1;
			q.emplace(0,st);
			for(;int(S[n].size())!=k&&!q.empty();){
				ll d=q.top().val;
				std::basic_string<int> p=q.top().path;
				int u=p.back();
				q.pop();
				if(int(S[u].size())==k) continue;
				S[u].emplace(d,p);
				for(edge e:G[u])
					if(p.find(e.ver)==std::basic_string<int>::npos) q.emplace(d+e.cost,p+e.ver);
			}
			if(int(S[n].size())!=k) return std::puts("-1"),void();
			std::printf("%d\n",int((st=S[n].begin()->path).size()));
			for(int it:st) std::printf("%d ",it);
		}
		return;
	}
}
signed main(){
	_fre_("bar",1,1);
	return MAIN::_main_(),0;
}
