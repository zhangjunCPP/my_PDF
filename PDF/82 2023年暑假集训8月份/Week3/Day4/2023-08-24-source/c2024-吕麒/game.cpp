#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	constexpr int N=200005;
	int n,v[N];
	std::multiset<int> S;
	std::stack<int> pos;
	std::vector<int> opt,sta[N];
	int id[N];
	void print(int now){
		for(int it:sta[now])
			if(it!=now) print(it);
		std::printf("%d ",sta[now].front());
	}
	void _main_(){
		std::scanf("%d",&n);
		for(int i=1;i<=n;++i)
			std::scanf("%d",&v[i]),S.emplace(v[i]),sta[i].emplace_back(i);
		long long ans=0;
		for(int i=n;i;--i){
			if(!pos.empty()&&v[i]==*--S.end()){
				ans+=1ll*v[i]*pos.size();
				while(!pos.empty())
					sta[i].emplace_back(pos.top()),pos.pop();
				sta[i].emplace_back(i);
				S.erase(S.find(v[i]));
				pos.emplace(i);
			}
			else{
				pos.emplace(i);
				S.erase(S.find(v[i]));
			}
		}
		if(!pos.empty()){
			int x=pos.top();
			pos.pop();
			ans+=1ll*v[x]*pos.size();
			while(!pos.empty())
				sta[x].emplace_back(pos.top()),pos.pop();
			sta[x].emplace_back(x);
		}
		std::printf("%lld\n",ans);
		print(1);
		return;
	}
}
signed main(){
	_fre_("game",1,1);
	return QL::_main_(),0;
}
