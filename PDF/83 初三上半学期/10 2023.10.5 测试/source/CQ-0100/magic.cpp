#include <cstdio>
#include <initializer_list>
using ll=long long;
constexpr int N=1010;
int Ch,n,i,v[N],j;
ll ans;
struct ss{
	int L,R,k,x;
	bool operator<(const ss&b)const{
		// printf("cmp: %d %d\n",x,b.x);
		if(R>=b.x&&b.x>=L){
			if(b.L<=x&&x<=b.R)return k>b.k;
			return true;
		}
		else if(b.L<=x&&x<=b.R)return false;
		return k>b.k;
	}
}a[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
inline void sp(T&x,T&y){
	T t(x);
	x=y;
	y=t;
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	 freopen("magic.in","r",stdin);
	 freopen("magic.out","w",stdout);
	r(n);
	for(i=1;i<=n;i++){
		a[i].x=i;
		r(a[i].L,a[i].R,a[i].k);
		for(j=i-1;j&&a[j+1]<a[j];j--)sp(a[j+1],a[j]);
	}
	for(i=1;i<=n;i++){
		v[a[i].x]=true;
		// printf("%d\n",a[i].x);
		for(j=a[i].L;j<=a[i].R;j++)if(!v[j])ans+=a[i].k;
	}
	w(ans);
	return 0;
}
