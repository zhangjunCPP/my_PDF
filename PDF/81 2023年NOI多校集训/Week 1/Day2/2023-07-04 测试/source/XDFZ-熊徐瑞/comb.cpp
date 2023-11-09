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
#define N 500005
#define LL long long
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
int n,a[N];
int s[N];
int dp[N];
signed main(){
	if(!debug){
		freopen("comb.in","r",stdin);
		freopen("comb.out","w",stdout);
	}
	else
		puts("------------------debug------------------"); 
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=4;i<=n;i++){//4
		for(int a1=i-3;a1>=1;a1--){
			for(int a2=a1+1;a2<i-1;a2++){
				if(a[i]!=a[a2])continue;
				for(int a3=a2+1;a3<i;a3++){
					if(s[i])break;
					if(a[a1] == a[a3]){
						s[i]=a1;
						break;
					}
				}
				if(s[i])break;
			}
			if(s[i])break;
		}
	}
	int ans=0;
	for(int i=4;i<=n;i++){
		if(s[i]<=0)continue;
		dp[i]=4;
		for(int j=4;j<s[i];j++){
			if(s[j]<=0)continue;
			dp[i]=Max(dp[i],dp[j]+4);
		}
		ans=Max(ans,dp[i]);
	}
	printf("%d",ans);
    return 0;
}
/*
10 2
13 45 46 60 103 115 126 150 256 516
90 45
450 100
20
*/
