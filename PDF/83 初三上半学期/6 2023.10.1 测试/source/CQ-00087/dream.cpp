#include <cstdio>
int ch,n,m,k,i;
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48);
	x=ch&15;
	while((ch=getchar())>47)x=(x<<1)+(x<<3)+(ch&15);
}
inline void solve0(){
}
inline void solve1(){
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	
	return 0;
}
