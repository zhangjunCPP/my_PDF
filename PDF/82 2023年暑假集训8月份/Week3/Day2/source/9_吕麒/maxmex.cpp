#include<bits/stdc++.h>
#define _fre_(f,x,y) \
{ \
	if(x) std::freopen(f".in","r",stdin); \
	if(y) std::freopen(f".out","w",stdout); \
}
namespace QL{
	constexpr int N=1e5+3;
	int n,a[N],q;
	namespace solve1{
		struct BIT{
			int c[N];
			void clear(int n){
				__builtin_memset(c,0,sizeof(int)*(n+1));
			}
			void upd(int x,int val){
				for(++x;x<N;x+=x&-x) c[x]+=val;
			}
			int qry(int x){
				int ret=0;
				for(++x;x;x-=x&-x) ret+=c[x];
				return ret;
			}
		};
		BIT tr;
		int cnt[N];
		int MAIN(){
			for(int k;q--;){
				std::scanf("%d",&k);
				for(int i=1;i<=k;++i)
					if(++cnt[a[i]]==1) tr.upd(a[i],1);
				auto work=[](){
					int l=0,r=n;
					for(int mid;l<r;){
						mid=(l+r+1)>>1;
						if(tr.qry(mid)<mid+1) r=mid-1; 
						else l=mid;
					}
					return l+1;
				};
				int ans=work();
				for(int l=2,r=k+1;r<=n;++r,++l){
					if(++cnt[a[r]]==1) tr.upd(a[r],1);
					if(--cnt[a[l-1]]==0) tr.upd(a[l-1],-1);
					if((ans=std::max(ans,work()))==k) break;
				}
				std::printf("%d\n",ans);
				__builtin_memset(cnt,0,sizeof(int)*(n+1));
				tr.clear(n);
			}
			return 0;
		}
	}
	signed _main_(){
		std::scanf("%d",&n);
		for(int i=1;i<=n;++i) std::scanf("%d",&a[i]);
		std::scanf("%d",&q);
		if(n*q<=1000000000) return solve1::MAIN();
		return 0;
	}
}
signed main(){
	 _fre_("maxmex",1,1);
	return QL::_main_();
}
/*
这题算不算涉政啊（？？？）
n,q,a分别做了限制，只要出题人有良心，就是先单再多值域有关。 
单测我可以拿一个区间扫过去，然后搞一下lg求mex。
多测就成了个 O(qnlgn)…… 能过掉 50pts 
考虑mex，我需要找到一个长度为k的区间使得0~k-1都有分布 
f(i,j,l,k)，i开始，长度为2^j，分布l~l+2^k……不是很科学
感觉是离线下来进行贪心的区间扩展 
先写个暴力，保底再缓缓，有点昏了 
暴力OK 
一段区间，对于k-1是不优的，那么对于k而言，它似乎也没有其他的更优
因为其他部分可以保证已有的比它大，而它扩展一个，最多只能填洞，比如把自己补满，就……
优了？？？
但是扫描已经是线性的了，只能从多测间关系来看。 
他这个区间中间部分至少得优过吧…… 
换个顺序，先枚举答案，这玩意儿具有单调性 
长度为k的存在最大答案d，那小于k的都不大于d
长度为k的凑不出d，那大于d的也凑不出
我们按k倒序，二分d，check
check复杂度O(n)，能降吗？ 
*/ 
