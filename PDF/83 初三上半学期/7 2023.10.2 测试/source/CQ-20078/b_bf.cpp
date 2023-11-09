#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) std::freopen(file".in","r",stdin); \
	if(out) std::freopen(file".out","w",stdout); \
}
namespace IO{
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'&&ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch&15);
		sign&&(x=-x);
	}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
namespace MAIN{
	constexpr int N=1e6+5;
	using ll=long long;
	int n,arr[N];
	ll sum[N];
	namespace solve1{
		bool check(int d,int u){
			for(int st=d+1,ed=d+u;ed<=n;++st,++ed)
				if(1ll*arr[st]*(d+u)>sum[ed]-sum[st-1]+sum[d]) return true;
			return false;
		}
		void _main_(){
			int ans=0;
			for(int siz=2;siz<=n;++siz){
				int l=0,r=siz-1;
				for(int mid;l<r;){
					mid=(l+r+1)>>1;
					if(check(siz-mid,mid)) l=mid;
					else r=mid-1;
				}
				if(ans<l) ans=l;
			}
			std::printf("%d",ans);
		}
	}
	void _main_(){
		read(n);
		for(int i=1;i<=n;++i) read(arr[i]);
		std::sort(arr+1,arr+n+1);
		for(int i=1;i<=n;++i) sum[i]=sum[i-1]+arr[i];
		return solve1::_main_();
		return;
	}
}
signed main(){
	_fre_("b",0,0);
	return MAIN::_main_(),0;
}
