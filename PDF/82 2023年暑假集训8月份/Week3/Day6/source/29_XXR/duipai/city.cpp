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
#define N 400005 
#define LL long long
#define LD long double
//#define int LL
//#define double LD
//#define P
#ifdef _WIN32
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#elif _WINDOWS_
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#else
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
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
int t[N],las[N],fir[N],num=1;
void add(int u,int v){
t[++num]=v;las[num]=fir[u];fir[u]=num;
t[++num]=u;las[num]=fir[v];fir[v]=num;}
int nw;
int f[N];
int siz[N];
int find(int x){return (f[x]==x?x:f[x]=find(f[x]));}
vector<int> v[N];
int col[N];
int n,k;
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		if(siz[fx]<siz[fy])f[fx]=fy,siz[fy]+=siz[fx];
		else f[fy]=fx,siz[fx]+=siz[fy];
	}
}
int fl[N];
void ask(int id,int cnt){
	if(cnt==nw){
		for(int i=1;i<=n;i++)f[i]=i;
		for(int u=1;u<=n;u++)
			if(fl[col[u]])
				for(int i=fir[u];i;i=las[i])
					if(fl[col[t[i]]])
						merge(u,t[i]);
		for(int i=1;i<=k;i++){
			if(!fl[i])continue;
			for(int j=0;j<(int)v[i].size()-1;j++)
				if(find(v[i][j])!=find(v[i][j+1]))return ;
		}
		printf("%d",nw-1);
		exit(0); 
	}
	if(id==k+1)return ;
	ask(id+1,cnt);
	fl[id]=1;
	ask(id+1,cnt+1);
	fl[id]=0;
}
signed main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);
		read(y);
		add(x,y);
	}
	for(int i=1;i<=n;i++){
		read(col[i]);
		v[col[i]].push_back(i);
	}
	for(nw=1;nw<=k;nw++){
		for(int j=1;j<=n;j++)f[j]=j,fl[j]=0;
		ask(1,0);
	}
	
    return 0;
}

