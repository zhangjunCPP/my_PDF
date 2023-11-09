#include <cstdio>
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	return 0;
}
