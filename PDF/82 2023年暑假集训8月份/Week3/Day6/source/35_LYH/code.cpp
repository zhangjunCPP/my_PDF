#include <cstdio>
#include <initializer_list>
int a,b,Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	r(a,b);
	if(a>b)a^=b^=a^=b;
	b-=--a;
	while(b--)putchar(48);
	while(a--)putchar(49);
	return 0;
}
