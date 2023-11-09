#include<bits/stdc++.h>
namespace IO{
	#define _fre_(file,in,out) { \
		if(in) std::freopen(file".in","r",stdin); \
		if(out) std::freopen(file".out","w",stdout); \
	}
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	template<typename _Tp>
	void write(_Tp x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar((x%10)|48);
	}
	void write(char ch){putchar(ch);}
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
	_fre_("",0,0);
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined template.cpp -o temp
./temp < "/mnt/hgfs/win_d/CQ-0766/temp_data/ex_temp1.in"
 */