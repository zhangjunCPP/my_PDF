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
	void _main_(){
		return;
	}
}
signed main(){
#ifndef FRANXX
	_fre_("",1,1);
#endif
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined -DFRANXX -o code temp.cpp
./code < "temp/temp1.in"
 */