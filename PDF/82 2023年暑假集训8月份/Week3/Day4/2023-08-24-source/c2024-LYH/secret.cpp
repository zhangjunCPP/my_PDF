#include <cstdio>
#include <initializer_list>
constexpr int M=65535;
int T,k,Ch,i;
unsigned x,y,s;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	r(T);
	while(T--){
		r(k);
		if(k==1){
			r(x,y);
			i=y;
			s=0;
			while(i--)s=(s*256+x)%M;
		}
		else return 0;
	}
	return 0;
}
