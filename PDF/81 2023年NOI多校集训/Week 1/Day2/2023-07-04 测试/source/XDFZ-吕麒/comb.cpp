#include<bits/stdc++.h>
#define _fre(s,b) (b+1)&&(freopen(s".in","r",stdin),0),(b+1&&b)&&(freopen(s".out","w",stdout),0)
constexpr int N=500005;
int n,a[N];
namespace solve1{
	std::pair<int,int> p[N];
	int cnt[N];
	bool check(){
		bool flag=1;
		for(int i=1;i<=n&&flag;++i)
			if(++cnt[a[i]]>2) flag=0;
			else p[a[i]].first=p[a[i]].second,p[a[i]].second=i;
		return flag;
	}
	int MAIN(){
		std::pair<int,int> pos(-1,-1);
		bool ans=0;
		for(int i=1;i<=n;++i){
			if(pos!=std::make_pair(-1,-1)&&p[a[i]].second>pos.second)
				ans=1;
			if(p[a[i]].second!=i&&p[a[i]].second>pos.second)
				pos=p[a[i]];
			if(pos.second==i) pos=std::make_pair(-1,-1);
		}
		std::printf("%d",ans?4:0);
		return 0;
	}
}
signed main(){
	_fre("comb",0);
	std::scanf("%d",&n);
	for(int i=1;i<=n;++i) std::scanf("%d",&a[i]);
	if(solve1::check()) return solve1::MAIN();
	else return 0;
	return 0;
}
/*
too hard and meaningless
*/ 
