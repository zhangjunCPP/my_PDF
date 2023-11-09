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
set<pair<int,int> >s;
int n;
pair<int,int> a[N];
queue<int> q;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	int sum=0;
	for(int i=n;i>=1;i--)
		read(a[i].first),a[i].second=n-i+1,s.insert({i,a[i].first});
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int c=0;
	for(int i=1;i<=n;i++){
		set<pair<int,int> >::iterator it=s.find({n-a[i].second+1,a[i].first});
		if(it!=s.end()){
			int cnt=c;
			while(s.begin()!=it){
				cnt++;
				q.push(n-s.begin()->first+1);
				s.erase(s.begin());
			}
			c=0;
			sum+=cnt*(it->second);
			q.push(n-s.begin()->first+1);
			s.erase(s.begin());
			c++;
		}
	}
	printf("%lld\n",sum);
	while(q.size()){
		printf("%lld ",q.front());
		q.pop();
	}
    return 0;
}
/*
3
1 2 3
*/ 

