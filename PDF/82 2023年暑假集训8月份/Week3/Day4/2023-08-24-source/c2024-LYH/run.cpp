#include <cstdio>
#include <initializer_list>
using ll=long long;
int p,Ch,i,x;
ll s,now;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
inline void w(char x){putchar(x);}
inline void w(const char*x){while(*x)putchar(*x++);}
inline void Print(int s){
	while(s--)w(50);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	r(p,s);
	if(p&1){
		w("Impossible");
		return 0;
	}
	p>>=1;
	if(s<p-1||s>ll(p>>1)*((p>>1)+(p&1))){
		w("Impossible");
		return 0;
	}
	for(i=1;i*ll(p-i)<s;i++);
	// printf("%d %d\n",i,p-i);
	now=ll(i)*(p-i);
	Print(i);
	w(49);
	x=now-s;
	Print(p-i-x-1);
	w(49);
	if(x){
		w(51);
		Print(x-1);
		w(49);
		Print(i-2);
	}
	else Print(i-1);
	w(49);
	Print(p-i-1);
	return 0;
}
