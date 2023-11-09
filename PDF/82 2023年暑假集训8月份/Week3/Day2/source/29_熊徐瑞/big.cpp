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
int n,m,q;
int vis[N];
int cnt[N];
struct st{int x,y;};
st e[N];
signed main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
		read(e[i].x),read(e[i].y);
	read(q);
	for(int i=1;i<=q;i++){
		int ans=0;
		char c=getchar();
		while(c<'0'||'1'<c)c=getchar();
		for(int j=1;'/'<c&&c<'2';j++,c=getchar())
			vis[j]=(c^'0');
		for(int b=0;b<(1<<m);b++){
			for(int i=1;i<=n;i++)cnt[i]=0; 
			int fl=0;
			for(int i=1;i<=m;i++){
				if((b&(1<<(i-1)))!=0){
					if(!(vis[e[i].x]&&vis[e[i].y])){
						fl=1;
						break;
					}
					cnt[e[i].x]++;
					cnt[e[i].y]++;
				}
			}
			if(fl)continue;
			for(int i=1;i<=n;i++){
				if(cnt[i]<2&&vis[i]){
					fl=1;
					break;
				}
			}
			if(fl)continue;
			ans++;
		}
		printf("%d\n",ans);
	}
    return 0;
}
/*
5 8
1 2
2 3
3 4
4 1
1 5
2 5
3 5
4 5
2
01111
11110
*/
