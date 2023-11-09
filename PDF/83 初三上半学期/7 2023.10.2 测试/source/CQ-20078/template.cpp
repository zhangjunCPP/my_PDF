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
	}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(read(args),0)...};}
namespace MAIN{
	void _main_(){
		return;
	}
}
signed main(){
	_fre_("",0,0);
	return MAIN::_main_(),0;
}
