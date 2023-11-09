#include<stdio.h>
#include<time.h>
#include<bitset>
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
#define LL long long
#define INF 1145141919
#define EPS 0.00001
template<typename T>INL T Max(REG T x,REG T y){return MAX(x,y);}
template<typename T>INL T Min(REG T x,REG T y){return MIN(x,y);}
template<typename T>INL T Abs(REG T x){return ABS(x);}
template<typename T>INL void Swap(REG T&x,REG T&y){x^=y^=x^=y;}
template<typename T>INL void Gcd(REG T x,REG T y){while(y^=x^=y^=x%=y);return x;}
template<typename T>
INL void read(REG T&x){
x=0;REG char c=getchar();/*REG T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/}
std::bitset<100020>f[520];
void xxr(int a,int b){
	f[0][0]=1;
	for(int i=0;i<=a;++i)
		for(int k=1;i+k<=a&&i*k<=b;++k)
			f[i+k]|=(f[i]<<(i*k));
}
int fa[N],fb[N];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout); 
	int q;
	read(q);
	int a=0;
	int b=0;
	for(int i=1;i<=q;++i){
		read(fa[i]);
		read(fb[i]);
		a=Max(a,fa[i]);
		b=Max(b,fb[i]);
	}
	xxr(a+5,b+5);
	for(int i=1;i<=q;++i){
		putchar(f[fa[i]][fb[i]]+'0');
		puts("");
	} 
    return 0;
}
/*
f(x,0)

f(x,y)=>f(x+k,y+kx)

1
500 100000
*/
