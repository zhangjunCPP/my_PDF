#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	using ll=long long;
	constexpr int N=30;
	int n,a[N];
	int opt[N];
	int ans[N];
	ll delta=0x3f3f3f3f;
	void dfs(int p,ll x,ll y,ll z){
		if(p==n+1){
			auto tmp=std::max({x,y,z})-std::min({x,y,z});
			if(tmp<delta){
				delta=tmp;
				__builtin_memcpy(ans,opt,sizeof(int)*(n+1));
			}
			return;
		}
		opt[p]=1,dfs(p+1,x+a[p],y,z);
		opt[p]=2,dfs(p+1,x,y+a[p],z);
		opt[p]=3,dfs(p+1,x,y,z+a[p]);
	}
	int id[N];
	void output(){
		for(int i=1;i<=n;++i) std::printf("%d ",ans[i]);
	}
	void make_one(){
		ll heap[4]={};
		for(int i=1;i<=n;++i){
			int t=std::min({1,2,3},[&heap](int x,int y){
				return heap[x]<heap[y];
			});
			heap[t]+=a[id[i]];
			ans[id[i]]=t;
		}
	}
	struct ts{
		int it[N];
		int top;
		ll val;
		void add(int x){
			it[++top]=x;
			val+=a[x];
		}
		void make(){
			std::sort(it+1,it+top+1,[](int x,int y){
				return a[x]<a[y];
			});
		}
		int find(ll x){
			return std::lower_bound(it+1,it+top+1,x,[](int x,int y){
				return a[x]<a[y];
			})-it;
		}
		void del(int t){
			val-=a[it[t]];
			for(int i=t;i<top;++i) it[i]=it[i+1];
		}
	};
	void check_ans(){
		ll all={};
		ts heap[4]={};
		for(int i=1;i<=n;++i) heap[ans[i]].add(i);
		for(int t:{1,2,3}) heap[t].make();
		ll each=all/3;
		while(std::clock()<2700){
//		for(int T=1;T<=1000&&std::clock()<2700;++T){
			int t=std::max({1,2,3},[&heap](int x,int y){
				return heap[x].val<heap[y].val;
			});
			if(heap[t].val==each) return;
			else{
				ll delta=heap[t].val-each;
				assert(delta>0);
				int p=heap[t].find(delta);
				int _=std::min({1,2,3},[&heap](int x,int y){
					return heap[x].val<heap[y].val;
				});
				heap[t].del(p);
				heap[_].add(p);
				heap[_].make();
			}
		}
	}
	void _main_(){
		std::scanf("%d",&n);
		for(int i=1;i<=n;++i) std::scanf("%d",&a[i]);
		if(n<=15){
			dfs(1,0,0,0);
			return output();
		}
		for(int i(1);i<=n;++i) id[i]=i;
		std::sort(id+1,id+n+1,[](int x,int y){
			return a[x]>a[y];
		});
		make_one();
		check_ans();
		output();
		return;
	}
}
signed main(){
	_fre_("treasure",1,1);
	return QL::_main_(),0;
}
