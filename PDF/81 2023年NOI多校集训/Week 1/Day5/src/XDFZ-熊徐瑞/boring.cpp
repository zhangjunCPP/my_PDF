//using namespace std;
//#include<bits/stdc++.h>
#include<cstdio>
//#include<string.h>
//#include<string>
//#include<iostream>
//#include<utility>
//#include<algorithm>
#define REG register
#define INL inline
#define MAX(x,y) (x<y?y:x)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x<0?-x:x)
#define N 100005
#define int __int128
#define LL long long
#define INF 1145141919
#define EPS 0.00001
#define P 998244353 
template<typename T>INL T Max(REG T x,REG T y){return MAX(x,y);}
template<typename T>INL T Min(REG T x,REG T y){return MIN(x,y);}
template<typename T>INL T Abs(REG T x){return ABS(x);}
template<typename T>INL void Swap(REG T&x,REG T&y){x^=y^=x^=y;}
template<typename T>INL int Gcd(REG T x,REG T y){while(y^=x^=y^=x%=y);return x;}
template<typename T>
INL void read(REG T&x){
x=0;REG char c=getchar();/*REG T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/} 
int lg[N]={0};
int l[N][30]={0};
int n=0,q=0,a[N]={0};
class fun1{
	public:
	void ini(){
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<=n;i++)l[i][0]=a[i];
		for(int j=1;j<=25;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				int a=l[i][j-1],b=l[i+(1<<(j-1))][j-1];
				l[i][j]=a/Gcd(a,b)*b;
			}
		}
	}
	int main(){
		read(n);
		read(q);
		for(int i=1;i<=n;i++)
			read(a[i]);
		ini();
		for(int i=1;i<=q;i++){
			int k;
			read(k);
			int sum=1;
			for(int j=1;j<=k;j++){
				int x,y;
				read(x);
				read(y);
				int aa=l[x][lg[y-x+1]],bb=l[y-(1<<lg[y-x+1])+1][lg[y-x+1]];
				int num=aa/Gcd(aa,bb)*bb;
				sum=sum/Gcd(num,sum)*num;
			}
			printf("%lld\n",(LL)(sum%P));
		}
		return 0;
	}
};
signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout); 
	fun1 x;
	return x.main();
}

