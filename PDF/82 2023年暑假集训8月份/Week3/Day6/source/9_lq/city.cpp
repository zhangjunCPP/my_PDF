#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	constexpr int N=2e5+5,K=2e5+5,Log=20;
	std::array<std::vector<int>,N> G;
	std::array<std::vector<int>,K> C;
	int n,k;
	int col[K];
//	int fa[Log][N];
//	int dep[N];
//	int dfn[N],idx;
//	int siz[N],son[N],top[N];
//	void dfs(int u){
//		siz[u]=1;
//		for(int v:G[u]){
//			if(v!=fa[0][u]){
//				dep[v]=dep[u]+1;
//				fa[0][v]=u;
//				dfs(v);
//				siz[u]+=siz[v];
//				if(siz[v]>siz[son[u]]) son[u]=v;
//			}
//		}
//		for(int k=1;k<Log;++k)
//			fa[k][u]=fa[k-1][fa[k-1][u]];
//	}
//	void dfs(int u,int tp){
//		top[u]=tp;
//		dfs(son[u],tp);
//		for(int v:G[u]) if(!top[v]) dfs(v,v);
//	}
//	int rt[K];
//	int jump_all(std::vector<int> v){
//		if(v.empty()) return 0;
//		int t=0x3f3f3f3f;
//		for(int it:v) t=std::min(t,dep[it]);
//		for(int &it:v){
//			if(dep[it]>t){
//				for(int k=Log-1;~k;--k){
//					if(dep[fa[k][it]]>=t) it=fa[k][it];
//				}
//			}
//		}
//		for(int k=Log-1;~k;--k){
//			bool flag=false;
//			int lst=0;
//			for(int it:v){
//				if(lst!=0) flag|=it!=lst;
//				lst=it;
//			}
//			if(flag){
//				for(int &it:v){
//					it=fa[k][it];
//				}
//			}
//		}
//		return fa[0][v.back()];
//	}
//	struct Sgt{
//		std::set<std::pair<int,int>> S[N<<2];
//		void build(int p,int l,int r){
//			S[p].clear();
//			if(l==r) return;
//			int mid=(l+r)>>1;
//			build(p<<1,l,mid);
//			build(p<<1|1,mid+1,r);
//		}
//		void merge(std::set<std::pair<int,int>> &S,std::set<std::pair<int,int>> s){
//			for(auto it:s) S.emplace(it);
//		}
//		void upd(int p,int l,int r,int x,std::set<std::pair<int,int>> &s){
//			merge(S[p],s);
//			if(l==r) return;
//			int mid=(l+r)>>1;
//			if(x<=mid) upd(p<<1,l,mid,x,s);
//			else upd(p<<1|1,mid+1,r,x,s);
//		}
//	}tr;
//	std::set<std::pair<int,int>> split(int u,int v){
//		std::set<std::pair<int,int>> s;
//		while(top[u]!=top[v]){
//			if(dep[top[u]]<dep[top[v]]) std::swap(u,v);
//			s.emplace(dfn[top[u]],dfn[u]);
//			u=fa[0][top[u]];
//		}
//		if(dep[u]<dep[v]) std::swap(u,v);
//		s.emplace(dfn[v],dfn[u]);
//		return s;
//	}
	struct Sgt{
		int min[N<<2],max[N<<2];
		void build(int p,int l,int r){
			min[p]=n+1,max[p]=0;
			if(l==r) return;
			int mid=(l+r)>>1;
			build(p<<1,l,mid);
			build(p<<1|1,mid+1,r);
		}
		void upd(int p,int l,int r,int x,int mi,int mx){
			min[p]=std::min(min[p],mi);
			max[p]=std::max(max[p],mx);
			if(l==r) return;
			int mid=(l+r)>>1;
			if(x<=mid) upd(p<<1,l,mid,x,mi,mx);
			else upd(p<<1|1,mid+1,r,x,mi,mx);
		}
		std::pair<int,int> qry(int p,int l,int r,int L,int R){
			if(L<=l&&r<=R) return {min[p],max[p]};
			std::pair<int,int> ret={n+1,0};
			int mid=(l+r)>>1;
			if(L<=mid){
				auto it=qry(p<<1,l,mid,L,R);
				ret.first=std::min(ret.first,it.first);
				ret.second=std::max(ret.second,it.second);
			}
			if(R>mid){
				auto it=qry(p<<1|1,mid+1,r,L,R);
				ret.first=std::min(ret.first,it.first);
				ret.second=std::max(ret.second,it.second);
			}
			return ret;
		}
	}tr;
	std::vector<int> L;
	void list(int t,int l){
		L.emplace_back(t);
		for(auto it:G[t]){
			if(it!=l) return list(it,t);
		}
	}
	int st[K],ed[K];
	int id[N];
	struct qry{
		int l,r;
		qry():l{},r{}{}
		qry(int _l,int _r):l{_l},r{_r}{}
	};
	std::vector<qry> Q;
	constexpr int Bl=333;
	void _main_(){
		std::scanf("%d%d",&n,&k);
		std::fill_n(G.begin()+1,n,std::vector<int>());
		std::fill_n(C.begin()+1,k,std::vector<int>());
		for(int i=2,u,v;i<=n;++i){
			std::scanf("%d%d",&u,&v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		{
			L.emplace_back(0);
			int t=0;
			for(int i=1;i<=n&&!t;++i) if(G[i].size()==1u) t=i;
			list(t,0);
			for(int i=1;i<(int)L.size();++i) id[L[i]]=i;
		}
		std::memset(st,0x3f,sizeof st);
		std::memset(ed,0xcf,sizeof ed);
		for(int i=1;i<=n;++i){
			std::scanf("%d",&col[i]),C[col[i]].emplace_back(i);
			st[col[i]]=std::min(st[col[i]],i);
			ed[col[i]]=std::max(ed[col[i]],i);
		}
		for(int i=1;i<=n;++i){
			tr.upd(1,1,n,id[i],st[col[i]],ed[col[i]]);
		}
		for(int i=1;i<=k;++i){
			auto range=tr.qry(1,1,n,st[i],ed[i]);
			Q.emplace_back(range.first,range.second);
		}
		std::sort(Q.begin(),Q.end(),[](qry x,qry y){
			return x.l/Bl==y.l/Bl?(x.r<y.r):(x.l/Bl<y.l/Bl);
		});
		int ans=0x3f3f3f3f;
		{
			static int cnt[K],now;
			auto ins=[](int x){
				if(++cnt[x]==1) ++now;
			};
			auto del=[](int x){
				if(--cnt[x]==0) --now;
			};
			int l=1,r=0;
			for(auto rg:Q){
				while(l>rg.l) ins(col[L[--l]]);
				while(r<rg.r) ins(col[L[++r]]);
				while(l<rg.l) del(col[L[l++]]);
				while(r>rg.r) del(col[L[r--]]);
				ans=std::min(ans,now);
			}
		}
		std::printf("%d\n",ans);
//		dfs(1),dfs(1,1);
//		for(int i=1;i<=k;++i)
//			rt[i]=jump_all(C[i]);
//		for(int i=1;i<=n;++i){
//			auto s=split(i,rt[col[i]]);
//			tr.upd(1,1,n,dfn[i],s);
//		}
		return;
	}
}
signed main(){
	_fre_("city",1,1);
	return QL::_main_(),0;
}
