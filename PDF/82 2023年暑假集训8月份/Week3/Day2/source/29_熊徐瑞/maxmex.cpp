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
#define N 100005
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
int a[N];
int vis[N];
int st[N][25];
void ST(){
	for(int i=1;i<=n;i++)st[i][0]=(1<<(a[i]-1));
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)<=n;j++)
			st[j][i]=(st[j][i]|st[j+(1<<j)][i]);
}
signed main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
    read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
    read(q);
	for(int ijk=1;ijk<=q;ijk++){
		int k;
		read(k);
		int mx=0;
		for(int i=1;i+k-1<=n;i++){
			for(int i=0;i<=n;i++)vis[i]=0;
			for(int j=i;j<=i+k-1;j++)vis[a[j]]++;
			int ans=-1;
			while(vis[++ans]>0);
			mx=Max(ans,mx);
		}
		printf("%d\n",mx);
	}
	return 0;
}
/*
6
2 1 1 0 0 3
6
1
2
3
4
5
6
*/ 
