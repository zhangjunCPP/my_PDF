#include <cstdio>
#include <initializer_list>
constexpr int N=200010,INF=0x3fffffff;
int n,a[N],i,j,L,R,mid,mi0[N],mi1[N],Min=INF,la,la2,Ch,ans=INF,f[N][21][2],flag=1;
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
template<typename T>
inline T mi(const T&x,const T&y){
	return x<y?x:y;
}
template<typename T>
inline T ma(const T&x,const T&y){
	return y<x?x:y;
}
void dfs(const int&&x,const bool&&flag,const int&Min,const int&Max){
	if(Max-Min>=ans)return;
	if(x>n){
//		printf("%d %d\n",Min,Max);
		ans=Max-Min;
		return;
	}
	if(flag){
		if(x!=n)dfs(x+1,1,mi(Min,a[x-1]),ma(Max,a[x-1]));
		dfs(x+1,0,mi(Min,a[x-1]+a[x]),ma(Max,a[x-1]+a[x]));
	}
	else{
		dfs(x+1,0,mi(Min,a[x]),ma(Max,a[x]));
		if(x!=n)dfs(x+1,1,Min,Max);
	}
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	r(n,a[1]);
	if(a[1]>10)flag=0;
	if(n<3){
		putchar(48);
		return 0;
	}
	for(i=2;i<=n;i++){
		r(a[i]);
		if(a[i]>10)flag=0;
	}
//	if(flag){
//		for(i=2;i<=n;i++){
//			for(j=1;j<=20;j++){
//			}
//		}
//	}
//	if(n<=18){
		dfs(1,0,INF,0);
		w(ans);
		return 0;
//	}
	la2=mi1[0]=mi0[0]=INF;
	la=mi1[1]=mi0[1]=a[1];
	for(i=2;i<=n;i++){
		mi0[i]=mi(la,a[i]);
		mi1[i]=mi(la2,a[i]+a[i-1]);
		la2=la;
		la=ma(mi0[i],mi1[i]);
		if(a[i]<Min)Min=a[i];
	}
//	printf("%d %d\n",Min,la);
	L=Min;
	R=la+1;
	return 0;
}
