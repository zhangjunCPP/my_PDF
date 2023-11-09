#include <cstdio>
#include <initializer_list>
int Ch,n,q,ax,ay,bx,by,ans,kx;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&...x){
	std::initializer_list<int>{(r(x),0)...};
}
template<typename T>
inline T ab(const T&x){
	return x<0?-x:x;
}
template<typename T>
inline T mi(const T&x,const T&y){
	return x<y?x:y;
}
inline int mi2(const int&x){
	return mi(x,n+1-x);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	r(n,q);
	while(q--){
		r(ax,ay,bx,by);
		ans=(kx=ab(ax-bx))+mi2(ab(ay-by));
		ans=mi(ans,mi2(ab(by-n+ay))+n+1-kx);
		w(ans);
		putchar(10);
	}
	return 0;
}
