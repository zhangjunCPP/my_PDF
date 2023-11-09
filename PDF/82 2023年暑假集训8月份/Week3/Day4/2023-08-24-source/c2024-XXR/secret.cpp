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
//#define double LD
#define P 65535
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
vector<pair<int,int> >v;
int k;
int n;
int sum=1;
void dfs(int u,int a,int T){
	if(u==n+1){
		sum*=qp(a,T)%P;
		sum%=P;
		return ;
	}
	for(int i=0;i<(int)v.size();i++){
		if(v[i].second>0){
//			for(int i=1;i<=u;i++)putchar('>');
//			cout<<v[i].first<<endl;
			v[i].second--;
			dfs(u+1,((a<<8)%P+v[i].first)%P,(T%P*(v[i].second+1))%P);
			v[i].second++;
		}
	}
}
signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int T;
	read(T);
	while(T--){
		v.clear();
		n=0;
		sum=1;
		read(k);
		for(int i=1,x,y;i<=k;i++){
			read(x),read(y),v.push_back({x,y}),n+=y;
//			for(int i=1;i<=y;i++)v.push_back({x,1});
		}
		dfs(1,0,1);
		printf("%lld\n",sum);
	}
    return 0;
}
/*
5
1
42 1
2
0 1
1 1
1
239 2
2
1 1
2 1
3
1 1
2 2
3 2
*/
/*
2
1
42 1
2
0 1
1 1
*/
