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
int n;
struct st{
	bitset<505> b;
	bool operator < (const st& oth)const{
		for(int i=1;i<=n;i++){
			if(b[i]!=oth.b[i])return b[i]>oth.b[i];
		}
		return 0;
	}
};
char str[N];
st b;
set<st> s;
void dfs2(st b){
//	cout<<b.b<<endl; 
	if(s.find(b)!=s.end())return ;
	s.insert(b);
	for(int i=1;i<=n-2;i++){
		if(b.b[i]==b.b[i+1]&&b.b[i]==1&&b.b[i+2]==0){
			st nb=b;
			nb.b[i+2]=1;
			nb.b[i]=0;
			dfs2(nb);
		}
	}
	for(int i=2;i<=n-1;i++){
		if(b.b[i]==b.b[i+1]&&b.b[i]==1&&b.b[i-1]==0){
			st nb=b;
			nb.b[i-1]=1;
			nb.b[i+1]=0;
			dfs2(nb);
		}
	}
}
int ans=0;
void dfs1(int u){
	if(u==n+1){
		s.clear();
		dfs2(b);
		ans+=s.size();
		return ;
	}
	if(str[u]=='?'){
		b.b[u]=0;
		dfs1(u+1);
		b.b[u]=1;
		dfs1(u+1);
	}else{
		b.b[u]=str[u]-'0';
		dfs1(u+1);
	}
}
signed main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	read(n);
	scanf("%s",str+1);
	dfs1(1);
	printf("%d",ans);
	return 0;
}
