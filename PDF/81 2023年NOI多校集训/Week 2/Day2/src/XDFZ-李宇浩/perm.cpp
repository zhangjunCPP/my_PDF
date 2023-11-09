#include <cstdio>
#include <initializer_list>
using ll=long long;
int n,i,f_la1=2,f_la2=1,f,ans,m,Ch;
ll fac=2,inv;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename... Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline ll pow(ll a,int b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%m;
		a=a*a%m;
		b>>=1;
	}
	return s;
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	r(n,m);
	inv=pow(2,m-2);
	for(i=3;i<=n;i++){
		fac=fac*i%m;
		f=ll(i-1)*f_la2%m+f_la1;
		if(f>=m)f-=m;
		ans^=(fac-f+m)*inv%m;
		f_la2=f_la1;
		f_la1=f;
	}
	w(ans);
	return 0;
}
//70-100