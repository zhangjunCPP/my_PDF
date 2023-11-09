using namespace std;
#include<bits/stdc++.h>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<iostream>
//#include<utility>
//#include<algorithm>
#define MAX(x,y) (x<y?y:x)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x<0?-x:x)
#define N 100005
#define LL long long
#define LD long double
//#define int LL
//#define double LD
//#define P
//#ifdef _WIN32
//#define getchar _getchar_nolock
//#define putchar _putchar_nolock
//#elif _WINDOWS_
//#define getchar _getchar_nolock
//#define putchar _putchar_nolock
//#else
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
//#endif
constexpr double EPS=(1e-9);
#ifdef int
constexpr int INF=1211081101201201140;
#else
constexpr int INF=1145141919;
#endif
template<typename T>T Max(T x,T y){return MAX(x,y);}
template<typename T>T Min(T x,T y){return MIN(x,y);}
template<typename T>T Abs(T x){return ABS(x);}
template<typename T>void Swap(T&x,T&y){x^=y^=x^=y;}
template<typename T>T Gcd(T x,T y){while(y^=x^=y^=x%=y);return x;}
#if(P)
template<typename T>
T qp(T a,T b){T sum=1;
while(b){if(b&1)sum=(sum*a)%P;a=(a*a)%P;b>>=1;}return sum;}
#else
template<typename T>
T qp(T a,T b){T sum=1;
while(b){if(b&1)sum*=a;a*=a;b>>=1;}return sum;}
#endif
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/}
template<typename T>
void write(T x){if(x<0){x=-x;putchar('-');}
if(x>9){write(x/10);}putchar(x%10|48);}
int p;
LL s;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(p);
	read(s);
	if(p&1){
		puts("Impossible");
		return 0;
	}
	p>>=1;
	for(LL i=2;i<=p&&i*i<=s;i++){
		//p/2-i=x+y
		//s=ix+y
		if((s-p+i)%(i-1)!=0)continue;
		LL x=(s-p+i)/(i-1);
		LL y=p-i-x;
		if(x<=0||y<0)continue;
		if(y==0){
			for(int j=1;j<=i;j++)putchar('2');
			putchar('1');
			for(int j=1;j<x;j++)putchar('2');
			putchar('1');
			for(int j=1;j<i;j++)putchar('2');
			putchar('1');
			for(int j=1;j<x;j++)putchar('2');
			return 0;
		}
		for(int j=1;j<=x;j++)putchar('2');
		putchar('1');
		for(int j=1;j<i;j++)putchar('2');
		putchar('1');
		for(int j=1;j<x;j++)putchar('2');
		putchar('1');
		for(int j=1;j<i-1;j++)putchar('2');
		putchar('3');
		for(int i=1;i<y;i++)putchar('2');
		putchar('1');
		putchar('1');
		for(int i=1;i<y;i++)putchar('2');
		if(x>=3)putchar('3');
		return 0;
	}
	if(p-1==s){
		for(int i=1;i<p;i++)putchar('2');
		putchar('1');
		putchar('1'); 
		for(int i=1;i<p-1;i++)putchar('2');
		putchar('1');
		return 0;
	}
	puts("Impossible");
	return 0;
}
//21211322211222
//22222222222222122222222222221122222232222222132222122222
