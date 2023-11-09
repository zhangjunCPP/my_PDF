#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	void _main_(){
		int a,b;
		std::scanf("%d%d",&a,&b);
		for(int i=1;i<a;++i) std::putchar('0');
		for(int i=1;i<b;++i) std::putchar('1');
		return;
	}
}
signed main(){
	_fre_("code",1,1);
	return QL::_main_(),0;
}
