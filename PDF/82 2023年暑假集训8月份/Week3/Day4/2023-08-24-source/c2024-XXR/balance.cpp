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
int n;
int t[N<<1],las[N<<1],fir[N],num;
void add(int u,int v){
t[++num]=v;las[num]=fir[u];fir[u]=num;
t[++num]=u;las[num]=fir[v];fir[v]=num;}
int siz[N],lar[N];
int rt;
void zx(int u,int fa,int all){
	siz[u]=1;
	lar[u]=0;
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == fa)continue;
		zx(t[i],u,all);
		siz[u]+=siz[t[i]];
		lar[u]=Max(lar[u],siz[t[i]]);
	}
	lar[u]=Max(lar[u],all-siz[u]);
	if(lar[u]<lar[rt])rt=u;
}
int b[N];
void dfs(int u,int fa){
	siz[u]=1;
	lar[u]=0;
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == fa)continue;
		if(u==rt)b[t[i]]=t[i];
		else b[t[i]]=b[u];
		dfs(t[i],u);
		siz[u]+=siz[t[i]];
		lar[u]=Max(lar[u],siz[t[i]]); 
	}
//	lar[u]=Max(lar[u],n-siz[u]);
}
int son1,son2;
int f(int u,int v){
	if(v==rt)Swap(u,v);
	if(u==rt){
		if(b[v]==son1)return Max(siz[son2],siz[son1]-siz[v]);
		else return siz[son1];
	}
	return Max(Max(lar[u],lar[v]),n-siz[u]-siz[v]);
}
int r0,r1,r2;
int siz2[N],lar2[N];
void zx2(int u,int fa,int all,int& rt){
	siz2[u]=1;
	lar2[u]=0;
	for(int i=fir[u];i;i=las[i]){
		if(t[i] == fa)continue;
		zx2(t[i],u,all,rt);
		siz2[u]+=siz2[t[i]];
		lar2[u]=Max(lar2[u],siz2[t[i]]);
	}
	lar2[u]=Max(lar2[u],all-siz2[u]);
	if(lar2[u]<lar2[rt])rt=u;
}
void solve1(){
	lar[0]=INF;
	zx(1,0,n);
	dfs(rt,0);
	for(int i=fir[rt];i;i=las[i])
		if(siz[t[i]]>siz[son1])son2=son1,son1=t[i];
		else if(siz[t[i]]>son2)son2=t[i];
	for(int i=1;i<=n;i++){
		int mn=rt;
		for(int j=1;j<=n;j++){
			if(b[i]==b[j])continue;
			if(f(i,j)<f(i,mn))mn=j;
		}
		printf("%d\n",mn);
	}
}
void solve2(){
	lar[0]=INF;
	zx(1,0,n);
	dfs(rt,0);
	for(int i=1;i<=n;i++)if(lar[i]==rt&&rt!=i)r0=i;
	for(int i=fir[rt];i;i=las[i])
		if(siz[t[i]]>siz[son1])son2=son1,son1=t[i];
		else if(siz[t[i]]>son2)son2=t[i];
	lar2[0]=INF;
	zx2(son1,rt,siz[son1],r1);
	zx2(son2,rt,siz[son2],r2);
	for(int i=1;i<=n;i++){
		int mn=rt;
		if(i==rt)mn=rt%n+1; 
		int j;
		j=rt;{
			if(b[i]!=b[j]&&f(i,j)<f(i,mn))mn=j;
		}
		if(r0){
			j=r0;{
				if(b[i]!=b[j]&&f(i,j)<f(i,mn))mn=j;
			}
		}
		j=r1;{
			if(b[i]!=b[j]&&f(i,j)<f(i,mn))mn=j;
		}
		j=r2;{
			if(b[i]!=b[j]&&f(i,j)<f(i,mn))mn=j;
		}
		printf("%d\n",mn);
	}
}
signed main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	read(n);
	for(int i=1,x,y;i<n;i++)
		read(x),read(y),add(x,y);
//	if(n<=5000){
//		solve1();
//		return 0;
//	}
	solve2();
    return 0;
}
/*
10
9 8
7 6
6 5
2 1
3 10
3 7
2 9
4 2
9 3
*/
