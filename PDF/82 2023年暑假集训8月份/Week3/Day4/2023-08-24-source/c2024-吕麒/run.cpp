#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) freopen(file".in","r",stdin); \
	if(out) freopen(file".out","w",stdout); \
}
namespace QL{
	using ll=long long;
	int p;
	ll s;
	std::pair<int,int> find(){
		for(int w=1;(w<<1)<p;++w){
			int h=(p-(w<<1))>>1;
			ll pos=1ll*h*w;
			if(pos==s) return {w,h};
			else if(pos>s&&w+h-1<=s) return {w,h};
		}
		return {-1,-1};
	}
	void impossible_out(){
		std::printf("Impossible");
		return;
	}
	void go(int st,int ed){
		for(int i=st;i<=ed;++i) std::putchar('2');
	}
	void simple_out(int w,int h){
		go(1,w);
		std::putchar('3');
		go(2,h);
		std::putchar('3');
		go(2,w);
		std::putchar('3');
		go(2,h);
		return; 
	}
	void only_down_out(int w,int h,int down){
		int prim=w-down;
		go(1,prim);
		std::putchar('3');
		go(2,h-1);
		std::putchar('1');
		go(2,down);
		std::putchar('3');
		std::putchar('3');
		go(2,w);
		std::putchar('3');
		go(2,h);
	}
	void only_cut_out(int w,int h,int cut){
		go(1,w-1);
		std::putchar('3');
		go(2,cut);
		std::putchar('1');
		std::putchar('3');
		go(2,h-cut);
		std::putchar('3');
		go(2,w);
		std::putchar('3');
		go(2,h);
	}
	void hard_out(int w,int h,int down,int cut){
		if(cut==0) return only_down_out(w,h,down);
		else if(down==0) return only_cut_out(w,h,cut);
		else{
			int prim=w-down-1;
			go(1,prim);
			std::putchar('3');
			go(2,cut);
			std::putchar('1');
			std::putchar('3');
			go(2,h-1-cut);
			std::putchar('1');
			go(2,down);
			std::putchar('3');
			std::putchar('3');
			go(2,w);
			std::putchar('3');
			go(2,h);
		}
	}
	void _main_(){
		std::scanf("%d%lld",&p,&s);
		if(p&1) return impossible_out();
		int w,h;
		std::tie(w,h)=find();
		if(w==-1&&h==-1) return impossible_out();
		else if(1ll*w*h==s) return simple_out(w,h);
		else{
			ll rest=1ll*w*h-s;
			int down=rest/(h-1);
			int cut=rest-down*(h-1);
			return hard_out(w,h,down,cut);
		}
		return;
	}
}
signed main(){
	_fre_("run",1,1);
	return QL::_main_(),0;
}
