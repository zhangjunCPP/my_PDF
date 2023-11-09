/* 
开幕雷击，显然很难。
T2、T4 看限制应该相对简单。
洛天依？不做！
我错了我回来了。
- d>sqrt(W)，则这类数的连积，BIT。
- d<=sqrt(W)
	- 存在 d，2^(c-1)-1
	- 否则，这 c 个数除去 d，然后互质的子集。
枚举 pd<=W(p<=W/d)，然后含 pd 的个数 t，则 (2^(c-t)-1)*(2^t-1)
不止。
 */
#include<bits/stdc++.h>
#define _fre_(file,in,out) (in&&(std::freopen(file".in","r",stdin))),(out&&(std::freopen(file".out","w",stdout)))
namespace IO{
	template<typename _Tp>
	void read(_Tp &&x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	void read(char *str){
		for(;(*str=getchar())==' '||*str=='\n';);
		for(;(*++str=getchar())!=' '&&*str!='\n';);
		*str='\0';
	}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
using ll=long long;
constexpr int N=2e5+5;
constexpr ll mod=998244353;
int n,q,a[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
ll qpow(ll a,int x){
	ll ret=1;
	for(;x;x>>=1,a=a*a%mod) if(x&1) ret=ret*a%mod;
	return ret;
}
void dfs(int p,int g,int r,ll &ans){
	if(g==1) return;
	if(p==r+1) return g&&(ans=ans*g%mod),void();
	dfs(p+1,gcd(g,a[p]),r,ans);
	dfs(p+1,g,r,ans);
}
signed main(){
	_fre_("ddickky",1,1);
	read(n,q);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1,l,r;i<=q;++i){
		read(l,r);
		ll ans=1;
		dfs(l,0,r,ans);
		std::printf("%lld\n",ans);
	}
	return 0;
}
/*
g++ -std=c++14 -O2 -o code -Wall -Wextra -fsanitize=address,undefined ddickky.cpp
./code < ddickky/ex_sub1.in
*/