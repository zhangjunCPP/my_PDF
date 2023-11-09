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
int vis[N];
int c[N];
int a[N];
int k;
int solve(){
	queue<int> q;
	int cnt=0;
	int nw=k;
	for(int i=1;i<=m;i++)vis[a[i]]=c[a[i]]=0;
	for(int i=1;i<=m;i++){
		if(vis[a[i]]==0){
			cnt++;
//			cout<<i<<"::";
			if(nw==0){
				int t=q.front();
				q.pop();
				while(c[t]){
					c[t]--;
					t=q.front();
					q.pop();
				}
				vis[t]=0;
			}else nw--;
			vis[a[i]]=1;
			q.push(a[i]);
		}else{
			c[a[i]]++;
			q.push(a[i]);
		}
	}
//	puts("");
	return cnt;
}
signed main(){
//	freopen("manage.in","r",stdin);
////	freopen("ex_manage4.in","r",stdin);
//	freopen("manage.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)read(a[i]);
	for(k=1;k<=n;k++){
		if(k!=n)printf("%d ",solve());
		else printf("%d",solve());
	}
	return 0;
}
/*
4 6
2 1 2 2 1 4
manage
5 3 3 3
*/
