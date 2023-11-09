/*
同向的不受影响。
变色龙不变，只变色。
维护每条变色龙的颜色段吗？
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
constexpr int N=100005;
struct One{
	int d,c;
	bool t;
};
One d[N];
int n;
signed main(){
	_fre_("chameleon",1,1);
	read(n);
	for(int i=1;i<=n;++i){
		static char s[5];
		read(d[i].d,d[i].c,s);
		d[i].t=*s=='D';
	}
	return 0;
}
/*
g++ -std=c++14 -O2 -o code -Wall -Wextra -fsanitize=address,undefined chameleon.cpp
./code < chameleon/ex_chameleon1.in
*/