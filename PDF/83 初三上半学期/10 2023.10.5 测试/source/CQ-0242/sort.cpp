/**
这不是快排吗？
某种意义上这个题也是在让我们根据数据算复杂度？
很好，他知道卡快排。
不仅如此，这个阴间的选点也很让人难受。
有序序列已经记忆化算好了
感觉上是维护原来序列的若干个单调段，因为时间瓶颈在划分。
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
	constexpr int N=7e5+5;
	using ll=long long;
	int n,arr[N];
	ll ans;
	ll f_calc(int n){
		static ll note[N];
		if(n<=1) return 0;
		else if(note[n]!=0) return note[n];
		else if(n&1) return note[n]=(f_calc(n>>1)<<1)+n;
		else return note[n]=f_calc(n>>1)+f_calc((n>>1)-1)+n;
	}
	bool is_sorted(int l,int r){
		bool up=true,down=true;
		for(int i=l;i<r&&(up||down);++i) up&=arr[i]<arr[i+1],down&=arr[i]>arr[i+1];
		return up||down;
	}
	void sort_calc(int l,int r){
		if(l>=r) return;
		if(is_sorted(l,r)) return ans+=f_calc(r-l+1),void();
		int pivot=arr[l+((r-l)>>1)];
		// std::fprintf(stderr,"%d %d %d %d\n",l,r,l+((r-l)>>1),pivot);
		static int Liko[N],Roy[N];
		int tx=0,ty=0;
		ans+=r-l+1;
		// std::fprintf(stderr,"sq: ");
		// for(int i=l;i<=r;++i) std::fprintf(stderr,"%d ",arr[i]);
		// std::fprintf(stderr,"\n");
		for(int i=l;i<=r;++i)
			if(arr[i]<pivot) Liko[++tx]=arr[i];
			else if(arr[i]>pivot) Roy[++ty]=arr[i];
		for(int i=1;i<=tx;++i) arr[l+i-1]=Liko[i];
		arr[l+tx]=pivot;
		for(int i=1;i<=ty;++i) arr[l+tx+i]=Roy[i];
		sort_calc(l,l+tx-1),sort_calc(l+tx+1,r);
	}
	void _main_(){
		read(n);
		for(int i=1;i<=n;++i) read(arr[i]);
		if(is_sorted(1,n)) return write(f_calc(n));
		else return sort_calc(1,n),write(ans);
	}
}
signed main(){
#ifndef FRANXX
	_fre_("sort",1,1);
#endif
	return MAIN::_main_(),0;
}
/* 
g++ -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined -DFRANXX -o code sort.cpp
./code < "sort/sort1.in"
 */