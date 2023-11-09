#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	constexpr int N=45,K=256;
	int n,k;
	int s[N];
	int ans[K];
	int chk(){
		
	}
	void dfs(int p){
		if(chk()>k) return;
		if(p==n+1){
			++ans[chk()];
			return;
		}
		s[p]=0;
		dfs(p+1);
		s[p]=1;
		dfs(p+1);
	}
	void _main_(){
		std::scanf("%d%d",&n,&k);
		dfs(1);
		for(int i=1;i<=k;++i) std::printf("%d ",ans[i]);
		return;
	}
}
signed main(){
	_fre_("sequence",1,1);
	return QL::_main_(),0;
}
