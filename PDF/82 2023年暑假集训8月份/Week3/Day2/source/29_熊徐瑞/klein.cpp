using namespace std;
#include<bits/stdc++.h>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<iostream>
//#include<utility>
//#include<algorithm>
#define REG
#define INL
#define MAX(x,y) (x<y?y:x)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x<0?-x:x)
#define N 3005
#define LL long long
#define LD long double
//#define int LL
constexpr bool debug=false,test=false;
constexpr double EPS=(1e-9);
#ifdef int
constexpr int INF=1211081101201201140;
#else
constexpr int INF=1145141919;
#endif
template<typename T>INL T Max(REG T x,REG T y){return MAX(x,y);}
template<typename T>INL T Min(REG T x,REG T y){return MIN(x,y);}
template<typename T>INL T Abs(REG T x){return ABS(x);}
template<typename T>INL void Swap(REG T&x,REG T&y){x^=y^=x^=y;}
template<typename T>INL T Gcd(REG T x,REG T y){while(y^=x^=y^=x%=y);return x;}
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
void read(REG T&x){
x=0;REG char c=getchar();/*REG T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/}
template<typename T>
void write(T x){if(x<0){x=-x;putchar('-');}
if(x>9){write(x/10);}putchar(x%10|48);}
int n,q;
int mob(int ax,int ay,int bx,int by){
	return Abs((n-ay+1)-by)+n-Abs(ax-bx);
	//观察柿子发现不需要判断走上还是下，因为ab可交换 
}
signed main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	read(n);
	read(q);
	n++;//////////////////////////////////////
	for(int i=1;i<=q;i++){
		int ax,ay,bx,by;
		read(ax);
		read(ay);
		read(bx);
		read(by);
		ax++,ay++,bx++,by++;/////////////////////
		int ans=Abs(ax-bx)+Abs(ay-by);//圆盘
		ans=Min(ans,n-Abs(ay-by)+Abs(ax-bx));//环
		ans=Min(ans,mob(ax,ay,bx,by));//莫比乌斯环
		ans=Min(ans,(n-ay+1)+mob(ax,1,bx,by));
		ans=Min(ans,ay+mob(ax,n,bx,by));
		printf("%d\n",ans);
	}
    return 0;
}
/*
10 5
1 9 10 1
7 4 5 4
1 1 3 1
6 6 0 2
10 2 6 1 
*/ 
