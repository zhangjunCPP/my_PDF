#include <cstdio>
#include <initializer_list>
using Acc_size_t=int;
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
int Ch;
bool Fh;
Acc_size_t Acc;
template<typename T>
inline void r(T&x){
	Fh=false;
	while((Ch=getchar())<48||Ch>57)Fh=Ch==45;
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
	if(Fh)x=-x;
}
inline void r(double&x){
	Fh=false;
	while((Ch=getchar())<48||Ch>57)Fh=Ch==45;
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=x*10+(Ch^48);
	if(Ch=='.'){
		Acc=1;
		while((Ch=getchar())<58&&Ch>47){
			x=x*10+(Ch^48);
			Acc*=10;
		}
		x/=Acc;
	}
	if(Fh)x=-x;
}
template<typename T>
inline void ur(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
inline void ur(double&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=x*10+(Ch^48);
	if(Ch=='.'){
		Acc=1;
		while((Ch=getchar())<58&&Ch>47){
			x=x*10+(Ch^48);
			Acc*=10;
		}
		x/=Acc;
	}
}
inline void r(char&x){
	while((x=getchar())<33);
}
inline void r(char*x){
	while((*x=getchar())<33);
	while((*++x=getchar())>32);
	*x=0;
}
template<typename...Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void uw(T&&x){
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
template<typename T>
inline void w(T x){
	if(x<0){
		putchar(45);
		x=-x;
	}
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
inline void w(char x){putchar(x);}
inline void w(const char*x){while(*x)putchar(*x++);}
template<typename...Ar>
inline void w(const Ar&...x){std::initializer_list<int>{(w(x),0)...};}
template<typename T>
constexpr inline T ma(const T&x,const T&y){
	return x>y?x:y;
}
template<typename T>
constexpr inline T mi(const T&x,const T&y){
	return x<y?x:y;
}
template<typename T>
constexpr inline T ab(T&&x){
	return x<0?-x:x;
}
template<typename T>
constexpr inline void sp(T&x,T&y){
	T t=x;
	x=y;
	y=t;
}
template<typename T>
constexpr T gcd(T x,T y){
	if(!x)return y;
	while(x^=y^=x^=y%=x);
	return y;
}
using ll=long long;
int main(){
	
	return 0;
}
