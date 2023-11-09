#include <cstdio>
int ch;
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48);
	x=ch&15;
	while((ch=getchar())>47)x=(x<<1)+(x<<3)+(ch&15);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	return 0;
}
