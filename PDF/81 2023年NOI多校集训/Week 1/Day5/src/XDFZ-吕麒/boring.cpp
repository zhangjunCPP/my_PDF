#include<iostream>
#include<numeric>
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
constexpr int N=100005,mod=998244353;
using ll=long long;
auto qpow=[](ll a,int x){
	int ret=1;
	for(;x;x>>=1,a=a*a%mod) if(x&1) ret=ret*a%mod;
	return ret;
};
auto inv=[](ll x){
	return qpow(x,mod-2);
};
int n,q,a[N];
signed main(){
#ifndef LOCAL
	_fre("boring");
#endif
	io.read(n,q);
	for(int i=1;i<=n;++i) io.read(a[i]);
	for(;q--;){
		static int k,l[N],r[N],p[N];
		io.read(k);
		for(int i=1;i<=k;++i) io.read(l[i],r[i]);
		ll ans=1;
		for(int i=1;i<=k;++i){
			ll it=1;
			for(int j=l[i];j<=r[i];++j)
				it=it*a[j]%mod;
			for(int x=l[i];x<r[i];++x)
				for(int y=x+1;y<=r[i];++y)
					it=it*inv(std::gcd(a[x],a[y]))%mod;
				// g=std::gcd(g,(ll)a[j]),it=it*inv(g)%mod;
			p[i]=it,ans=ans*it%mod;
		}
		for(int x=1;x<k;++x)
			for(int y=x+1;y<=k;++y)
				ans=ans*inv(std::gcd(p[x],p[y]))%mod;
		io.writeln(ans);
	}
	return 0;
}
/*
不会lcm（悲
好像是取模后求gcd的问题
*/