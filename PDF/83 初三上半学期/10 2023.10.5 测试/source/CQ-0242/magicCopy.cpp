/* 
没什么思路。
n=10 可以暴搜；n=20 开始就不会。
然后还会一个性质点，l[i]=r[i]=i，弱智吧……
关键点在于 l[i]~r[i] 包含 i 且极小。
可以不可以反悔贪心涅？
又或者这么说，一个点只和前后至多七个点有关。
一个点自我牺牲，则后面若干次贡献拿不到。
先假定所有贡献都拿得到，但也不好弄。
影响最小的点不会早死，是吗？
或者说，当前点死了收益最大，死当前点？也不。
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
	void write(char *str){puts(str);}
	void write(const char *str){puts(str);}
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
	constexpr int N=1e3+5;
	int n,l[N],r[N],c[N];
	ll ans;
	void dfs(int p){
		static int light[N]={};
		static int alive[N]={};
		if(p==n+1){
			ll pos=0;
			for(int i=1,it;i<=n;++i)
				for(int j=l[it=light[i]];j<=r[it];++j)
					if(alive[j]>i) pos+=c[it];
			if(ans<pos) ans=pos;
			return;
		}
		for(int i=1;i<=n;++i) if(!alive[i])
			alive[light[p]=i]=p,dfs(p+1),alive[i]=0;
	}
	void _main_(){
		read(n);
		bool f4=true;
		for(int i=1;i<=n;++i) read(l[i],r[i],c[i]),f4&=(l[i]==i&&r[i]==i);
		// if(n==1) return write('0');
		// else if(f4) return write('0');
		// else if(n<12) return dfs(1),write(ans);
		// else{
			static bool light[N]={};
			for(int i=1;i<=n;++i){
				static auto calc_sum=[](int i){
					ll sum=-c[i];
					for(int j=l[i];j<=r[i];++j) if(!light[j]) sum+=c[i];
					return sum;
				};
				int cs=0;
				ll mx=0;
				for(int j=1;j<=n;++j){
					if(!light[j]){
						ll sum=calc_sum(j);
						for(int k=std::max(1,j-15);k<=std::min(n,j+15);++k) if(!light[k]&&l[k]<=j&&j<=r[k]) sum-=c[k];
						if(cs==0||sum>mx) mx=sum,cs=j;
					}
				}
				assert(cs!=0);
				ans+=calc_sum(cs);
				// write(cs,' ',calc_sum(cs),'\n');
				light[cs]=true;
			}
			write(ans);
		// }
		return;
	}
}
signed main(){
#ifndef FRANXX
	_fre_("magic",1,1);
#endif
	return MAIN::_main_(),write('\n'),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined -DFRANXX -o code magic.cpp
./code < "magic/magic1.in"
 */