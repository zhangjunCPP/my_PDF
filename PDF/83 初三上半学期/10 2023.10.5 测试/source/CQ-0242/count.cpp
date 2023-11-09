/* 
离谱题目。
极大的 n 与极多的 T，以及及其诡异的时空。矩快？
不如不太可能有什么好的做法。
可以 MIM+hash 再分段抢一下前三个点。
然后还有个跑不怎么满的 n^3 玩意儿，分解质因数，2^(sum{t}) 的答案然后求和，注意完全平方数要 -1。
然后可以考虑换顺序，处理一堆质数出来。
然后我们筛他一堆质数，来凑合数，这东西 n^2。
暂时不写，只是略优 MIM。
其实我们不关系 x 是怎么得到的，只关心 x 含有的素数个数，这个 sum{t} 的最大值是 70 左右。
但是我们需要 sum{t} 出现的次数，也就是这么多个质数能凑出来多少个 n^2 以内的数。
其实这一坨东西还是 n^2 的。
暴力暴力！
上面想错了，还有两个 <=n 不好满足。
 */
#include<bits/stdc++.h>
namespace IO{
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):ch&15);
	}
	template<typename _Tp>
	void uwrite(_Tp x){
		if(x>9) uwrite(x/10);
		putchar((x%10)|48);
	}
	template<typename _Tp>
	void write(_Tp x){x<0&&(putchar('-'),x=-x),uwrite(x);}
	void write(char ch){putchar(ch);}
	void write(char *str){printf("%s",str);}
	void write(const char *str){printf("%s",str);}
}
#define _fre_(file,in,out) { \
	if(in) std::freopen(file".in","r",stdin); \
	if(out) std::freopen(file".out","w",stdout); \
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args ...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
	using ll=long long;
	ll n;
	// ll pri[1000000],tot;
	// template<ll N>
	// void get_prime(){
	// 	static std::bitset<N+5> v;
	// 	for(int i=2;i<=N;++i){
	// 		if(!v[i]) pri[++tot]=i;
	// 		for(int j=1;j<=tot&&pri[j]*i<=N;++j){
	// 			v[i*pri[j]]=1;
	// 			if(i%pri[j]==0) break;
	// 		}
	// 	}
	// }
	namespace solve1{
		int cnt[100000005];
		void _main_(){
			int ans=0;
			for(int i=1;i<=n*n;++i) cnt[i]=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j) ++cnt[i*j];
			for(int i=1;i<=n*n;++i) ans+=cnt[i]*cnt[i];
			write(ans,'\n');
		}
	}
	namespace solve2{
		void _main_(){
			return;
		}
	}
	void _main_(){
		read(n);
		return solve1::_main_();
		// if(n<=1000) return solve1::_main_();
		// else return solve2::_main_();
	}
}
signed main(){
#ifndef FRANXX
	_fre_("count",1,1);
#endif
	int T;
	read(T);
	// MAIN::get_prime<1000000>();
	while(--T) MAIN::_main_();
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined -DFRANXX -o code count.cpp
./code < "count/count1.in"
 */