/*
开篇博弈！先跳为敬。
回来了，但样例真的凉心。
因为删除后要联通，所以只能删环。
无重边，至少是三元环。
能不能找出无向图所有环？不好弄。
那就上dfs生成树。
随便一条非树边，插上都是一个环。
难点是可能会俩非树边造多环。
但是我们在环上切一刀，一定弄掉一个非树边的环。
所以我认为可以乱搞。
那读入这么多不就成了锤子……
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
	template<typename _Tp>
	void uwrite(_Tp x){
		if(x>9) uwrite(x/10);
		putchar((x%10)|48);
	}
	template<typename _Tp>
	void write(_Tp x){(x<0&&(putchar('-'),x=-x)),uwrite(x);}
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args &&...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
	constexpr int N=1e5+5;
	int n,m,k;
	char Force[N];
	void _main_(){
		read(n,m,k);
		std::scanf("%s",Force+1);
		for(int i=1,u,v;i<=m;++i) read(u,v);
		int d=m-(n-1)+1,x=1;
		static constexpr char winner[]{"GP"};
		for(;--d;) if(++x>k) x=1;
		std::putchar(winner[Force[x]=='G']);
		return std::putchar('\n'),void();
	}
}
signed main(){
	_fre_("game",1,1);
	int T;
	for(read(T);--T;) MAIN::_main_();
	return MAIN::_main_(),0;
}
