#include<iostream>
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
constexpr int N=10000005;
using ll=long long;
ll n,mod;
ll delta[N];
ll cnt[N];
signed main(){
#ifndef LOCAL
	_fre("perm");
#endif
	io.read(n,mod);
	delta[3]=1;
	for(int i=4;i<=n;++i) delta[i]=delta[i-1]*(i-2ll)%mod;
	cnt[3]=1;
	for(int i=4;i<=n;++i){
		if(i&1)
			cnt[i]=(cnt[i-1]+cnt[i-2]*(i-1ll)%mod+delta[i]*(i-2ll)%mod*((i-1ll)>>1)%mod)%mod;
		else
			cnt[i]=(cnt[i-1]+cnt[i-2]*(i-1ll)%mod+delta[i]*((i-2ll)>>1)%mod*(i-1ll)%mod)%mod;
	}
	ll ans=0;
	for(int i=1;i<=n;++i) ans^=cnt[i];
	io.write(ans);
	return 0;
}
/*
牛逼人物
考虑一下怎样一个排列能优秀
打了会儿表，没啥大头绪
但是这个肯定要求O(n)
你如果把1放在最前面，那相当于长度减去一
打了一个半小时的表
真有规律，6
除掉1，剩下一串放在最前面会成为等差数列
第i行的delta[i]=delta[i-1]*(i-2)
首项是往前面数两行的答案
牛逼人物
我去有除法！
完了，我不会逆元……
锅了，看不出来
我不信了
哦，溢出了
现在我们来推逆元吧！
想到了欧拉，但我也不会……
讲个笑话：
L*Q卡了一个小时的逆元，最后求不出来
然后拆柿子，发现有个int能存下的部分，必定有2的倍数
而他只除以2……
直接逆元都不要了，针不戳。
*/