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
#define N 1000005
#define LL long long
#define LD long double
#define int LL
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
int t[N],las[N],fir[N],c[N],num;
void add(int u,int v,int w){
t[++num]=v;las[num]=fir[u];fir[u]=num;c[num]=w;
t[++num]=u;las[num]=fir[v];fir[v]=num;c[num]=w;}
struct st{
	int u,v,s;
	bool operator < (const st& x)const{return (u==x.u?(v==x.v?s<x.s:v<x.v):u<x.u);}
};
map<st,int> mp; 
int dfs(int u,int v,int sum){
	int re=-1;
	if(u==v)re=1;
	if(mp.find({u,v,sum})!=mp.end())return mp[{u,v,sum}];
	for(int i=fir[u];i;i=las[i]){
		if(c[i]*sum>m)continue;
		int x=dfs(t[i],v,sum*c[i]); 
		re=Max(re,x*c[i]);
	}
	if(re>0)mp[{u,v,sum}]=re;
	return re;
}
signed main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=2;i<=m;i++){
		int x,y;
		read(x);
		read(y);
		add(x,y,i);
	}
	for(int i=1;i<=q;i++){
		int u,v;
		read(u);
		read(v);
		printf("%lld\n",dfs(u,v,1));
	}
	return 0;
}
/*
4 5 10
1 2
2 3
3 4
4 1

1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
*/
