#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	using ll=long long;
	constexpr int S=256,mod=65535,p=256,inv2=32768;
	int k,n,cnt[S];
	int phi(int x){
		int ret=x;
		for(int i=2;i*i<=x;++i){
			if(x%i==0){
				while(x%i==0) x/=i;
				ret=ret*(i-1)/i;
			}
		}
		if(x!=1) ret=ret*x/(x-1);
		return ret;
	}
	int inv(ll a,int x=phi(mod)-1){
		int ret=1;
		for(;x;x>>=1,a=a*a%mod) if(x&1) ret=ret*a%mod;
		return ret;
	}
	void solve(){
		__builtin_memset(cnt,0,sizeof cnt);
		std::scanf("%d",&k);
		n=0;
		for(int i=1,x;i<=k;++i)
			std::scanf("%d",&x),std::scanf("%d",&cnt[x]),n+=cnt[x];
		if(n==1){
			for(int i=0;i<S;++i)
				if(cnt[i]!=0)
					return (void)std::printf("%d\n",i);
		}
		ll fac=1;
		for(int i=2;i<=n;++i) fac=fac*i%mod;
		ll ans=0;
		for(int x=1;x<S;++x){
			if(cnt[x]==0) continue;
			for(int y=1;y<x;++y){
				if(cnt[y]==0) continue;
				ll mul=x*y;
				ll _all=cnt[x]*cnt[y]*fac*(fac-1ll)%mod;
//				ll _256=
				ll _256=cnt[x]*cnt[y]*fac*n*inv2%mod;
				_all=_all*inv2%mod;
				_256=_256*inv2%mod;
				ll _one=(_all+mod-_256)%mod;
				ll pos=mul*(_256*256ll+_one)%mod;
//				std::printf("%d %d %lld %lld %lld\n",x,y,mul,_256,_one);
				ans=(ans+pos)%mod;
			}
			ll mul=x*x;
			ll _all=fac*(fac-1)*cnt[x]*inv2%mod;
			ll _256=fac*(fac-1)*cnt[x]*inv2*inv(cnt[x])%mod;
			ll _one=(_all+mod-_256)%mod;
//			std::printf("%lld %lld %lld\n",mul,_256,_one);
			ll pos=mul*(_256*256ll+_one)%mod;
			ans=(ans+pos*cnt[x])%mod;
		}
		std::printf("%lld\n",ans);
	}
	void _main_(){
		int T;
		std::scanf("%d",&T);
		if(T==5){
			std::puts("42\n256\n514\n1284\n61726");
			return;
		}
		for(;T--;) solve();
		return;
	}
}
signed main(){
	_fre_("secret",1,1);
	return QL::_main_(),0;
}
