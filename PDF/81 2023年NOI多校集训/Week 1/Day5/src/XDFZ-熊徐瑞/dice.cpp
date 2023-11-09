//using namespace std;
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
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
int n,k;
int a[10];
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout); 
	read(n);
	read(k);
	for(int i=1;i<=6;i++)
		for(int j=0;j<3;j++)
			if(i&(1<<j))
				a[i]+=(k<<(j*6));
	puts("Yes");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++)printf("%d ",a[(i+j)%6+1]);
		puts("");
	}
    return 0;
}

