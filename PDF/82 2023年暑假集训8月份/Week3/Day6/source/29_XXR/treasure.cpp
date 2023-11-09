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
#define int LL
#define M ((n+2)>>1) 
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
int a[N];
LL p[N];
int n;
struct st2{
	LL x;
	int s[3];
	bool operator <(const st2& v)const{
//		if(s[0]+s[1]+s[2]!=v.s[0]+v.s[1]+v.s[2])return s[0]+s[1]+s[2]<v.s[0]+v.s[1]+v.s[2];
		return (s[0]==v.s[0]?(s[1]==v.s[1]?s[2]<v.s[2]:s[1]<v.s[1]):s[0]<v.s[0]);
	}
	st2 operator -(const st2& v)const{
		return {0,{s[0]-v.s[0],s[1]-v.s[1],s[2]-v.s[2]}};
	}
};
struct st{
	LL x;
	int c(){
		int y=x;
		int cnt[3]={};
		for(int i=1;i<=n;i++)
			cnt[y%3]+=a[i],y/=3;
		return Max(Max(cnt[0],cnt[1]),cnt[2])-Min(Min(cnt[0],cnt[1]),cnt[2]);
	}
};
st ans={0};
void meijuziji(){
	for(st i={0};i.x<p[n];i.x++)
		if(i.c()<ans.c())ans=i;
}
set<st2> s;
void zhe_ban_sou_suo(st2 x,int nw){
	if(nw==M+1){
		s.insert(x);
		return ;
	}
	for(int i=0;i<=2;i++){
		st2 y=x;
		y.x+=p[nw-1]*i,y.s[i]+=a[nw];
		zhe_ban_sou_suo(y,nw+1);
	}
}
int pj;
st2 xxr;
void zhe_ban_sou_suo2(st2 x,int nw){
	if(nw==n+1){
		set<st2>::iterator it=s.lower_bound(xxr-x);
		set<st2>::iterator it2=it; 
		if(it!=s.end()){
			st2 y=*it;
			st z={y.x+x.x};
			if(z.c()<ans.c())ans=z;
		}
		if(++it2!=s.end()){
			st2 y=*it2;
			st z={y.x+x.x};
			if(z.c()<ans.c())ans=z;
		}
		for(int i=1;i<=10;i++){
			if(it!=s.begin()){
				it--;
				st2 y=*it;
				st z={y.x+x.x};
				if(z.c()<ans.c())ans=z;
			}
			if(++it2!=s.end()){
				st2 y=*it2;
				st z={y.x+x.x};
				if(z.c()<ans.c())ans=z;
			}
			if(ans.c()==0){
				for(int i=1;i<=n;i++)printf("%lld ",ans.x/p[i-1]%3+1);
				exit(0);
			}
		} 
//		/*
//		*/
		return ;
	}
	for(int i=0;i<=2;i++){
		st2 y=x;
		y.x+=p[nw-1]*i,y.s[i]+=a[nw]; 
		zhe_ban_sou_suo2(y,nw+1);
	}
}
signed main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	read(n);
	p[0]=1;
	for(int i=1;i<=n;i++)
		read(a[i]),p[i]=p[i-1]*3;
	if(n<=15){
		meijuziji();
	}
	else{
		for(int i=1;i<=n;i++)pj+=a[i];
		pj/=3;
		xxr={0,{pj,pj,pj}};
		zhe_ban_sou_suo({0,{}},1);
		zhe_ban_sou_suo2({0,{}},M+1);
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans.x/p[i-1]%3+1);
	return 0;
}
/*
6
1 0 4 5 1 4

13
1 1 4 5 1 4 1 9 1 9 8 1 0
*/
