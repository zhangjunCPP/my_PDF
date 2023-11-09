#include <cstdio>
#include <initializer_list> 
int n,m,T,k,x,y,Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){
	std::initializer_list<int>{(r(x),0)...};
}
int main(){
//#undef LYH_LOCAL
#ifndef LYH_LOCAL
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
#endif
	r(T);
	while(T--){
		r(n,m,k);
		if(Ch!=10)while(getchar()!=10);
		x=(m+1-n)%k+1;
		while(x--)y=getchar();
		putchar(y=='P'?'G':'P');
		putchar(10);
		while(getchar()!=10);
		while(m--)r(x,y);
	}
	return 0;
}
