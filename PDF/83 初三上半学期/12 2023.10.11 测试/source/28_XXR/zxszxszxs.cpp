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
#define N 500005
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
int n,m;
int ans[N];
int nxt[N];
int las[N];
int vis[N];
int a[N];
int bl[N];
struct st{
	int l,r,tim;
	bool operator < (const st& oth)const{
		if(bl[l]!=bl[oth.l])return bl[l]<bl[oth.l];
		else return r<oth.r;
	}
}q[N];
int ask(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(vis[a[i]]==0)cnt++;
		vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	return cnt;
}
int ret[N];
void f(){
	int l=1,r=0,nw=0;
	for(int i=1;i<=m;i++){
		if(q[i].l==0)continue;
//		ret[q[i].tim]=ask(q[i].l,q[i].r);
		while(l>q[i].l){if(++vis[a[--l]]==1)nw++;}
		while(r<q[i].r){if(++vis[a[++r]]==1)nw++;}
		while(l<q[i].l){if(--vis[a[l++]]==0)nw--;}
		while(r>q[i].r){if(--vis[a[r--]]==0)nw--;}
		ret[q[i].tim]=nw;
//		cout<<l<<','<<r<<"::\n";
//		for(int i=1;i<=n;i++)cout<<vis[i]<<'|';
//		puts("");
	}
}
signed main(){
//	freopen("manage.in","r",stdin);
	freopen("ex_manage3.in","r",stdin);
	freopen("manage.out","w",stdout);
	read(n);
	read(m);
	int blk=(int)ceil(n/sqrt(m));
	for(int i=1;i<=m;i++){
		read(a[i]);
		nxt[las[a[i]]]=i;
		las[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		bl[i]=(i+blk-1)/blk;
		if(i+1>=nxt[i])continue;
		q[i]={i+1,nxt[i]-1,i};
	}
	ans[n]=ask(1,m);
	sort(q+1,q+m+1);
	f(); 
	for(int i=1;i<=m;i++){
		if(i+1>=nxt[i])continue;
		ans[ret[i]]++;
	}
	for(int i=n-1;i;i--)ans[i]+=ans[i+1];
	for(int i=1;i<=n;i++){
		if(i!=n)printf("%d ",ans[i]);
		else printf("%d",ans[i]);
	}
	return 0;
}
/*
4 6
2 1 2 2 1 4
manage
5 3 3 3
*/
