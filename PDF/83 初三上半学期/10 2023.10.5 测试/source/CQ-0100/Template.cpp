#include <cstdio>
#include <initializer_list>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	
	return 0;
}