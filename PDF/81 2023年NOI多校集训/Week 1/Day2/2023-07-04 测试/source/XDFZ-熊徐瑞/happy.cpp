using namespace std;
#include<bits/stdc++.h>
#include<stdio.h>
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
#define K 505
#define int long long
#define INF 1145141919
#define EPS 0.00001
#define debug 0
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
int n,m;
int t[N];
int num[K],c[K];
int dp[N];
signed main(){
	if(!debug){
		freopen("happy.in","r",stdin);
		freopen("happy.out","w",stdout);
	}
	else
		puts("------------------debug------------------"); 
	read(n);
	read(m);
	for(int i=1;i<=n;i++)read(t[i]);
	for(int i=1;i<=m;i++){
		read(num[i]);
		read(c[i]);
	}
	num[++m]=1;
	read(c[m]);
	for(int i=1;i<=n;i++)dp[i]=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k>=1;k--){
				if(t[k]+num[j]-1<t[i])break;
				dp[i]=Min(dp[i],dp[k-1]+c[j]);
			}
		}
		if(debug)cout<<dp[i]<<','; 
		printf("%lld\n",dp[i]-dp[i-1]);
	}
    return 0;
}
/*
10 2
13 45 46 60 103 115 126 150 256 516
90 45
450 100
20
*/
