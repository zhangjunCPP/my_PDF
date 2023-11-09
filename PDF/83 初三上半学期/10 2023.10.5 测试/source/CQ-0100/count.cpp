#include <cstdio>
#include <initializer_list>
int Ch,T,n,ans;
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
inline void BF(const int&n){
	int a,b,c;
	ans=0;
	for(a=1;a<=n;a++){
		for(b=1;b<=n;b++){
			for(c=1;c<=n;c++){
				if(a*b%c==0&&a*b<=n*c){
					// printf("%d %d %d %d\n",a,b,c,a*b/c);
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	 freopen("count.in","r",stdin);
	 freopen("count.out","w",stdout);
	r(T);
	while(T--){
		r(n);
		BF(n);
	}
	return 0;
}
