#include <cstdio>
constexpr int N=10;
int v[N],a[N],n,ans,p[N],Ch;
template<typename T>
constexpr inline T ab(T&&x){
	return x<0?-x:x;
}
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline bool check(const int&l,const int&r){
	if(l+1==r)return ab(a[l]-a[l-1])==1||ab(a[l]-a[r])==1;
	if(a[l+1]>a[l]){
		for(int i=l+1;i<r;i++)if(a[i]-a[i-1]!=1)return true;
		return ab(a[l]-a[l-1])==1||ab(a[r-1]-a[r])==1;
	}
	for(int i=l+1;i<r;i++)if(a[i]-a[i-1]!=-1)return true;
	return ab(a[l]-a[l-1])==1||ab(a[r-1]-a[r])==1;
}
void dfs(const int&x){
	if(x>n){
		int i;
		for(i=1;i<=n;i+=p[i]){
			if(check(i,i+p[i]))break;
		}
		if(i>n)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=true;
			a[x]=i;
			dfs(x+1);
			v[i]=false;
		}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	static int i;
	r(n);
	*a=-1;
	a[n+1]=-1;
	for(i=1;i<=n;i++)r(p[i]);
	dfs(1);
	w(ans);
	return 0;
}
