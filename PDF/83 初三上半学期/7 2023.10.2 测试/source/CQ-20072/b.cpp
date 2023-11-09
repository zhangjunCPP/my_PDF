#include <cstdio>
#include <algorithm>
using ll=long long;
constexpr int N=1000010;
int n,a[N],i,j,ans,Ch;
ll s;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	r(n);
	for(i=1;i<=n;i++)r(a[i]); 
	std::sort(a+1,a+n+1);
	s=a[1];
	for(i=2;i<=n;i++){
		s+=a[i];
		while(a[j]<=s/i)j++;
		if(i-j+1>ans)ans=i-j+1;
	}
	w(ans);
	return 0;
}
