using namespace std;
#include<bits/stdc++.h>
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
#define N 500005
#define int long long
#define INF 1145141919
#define EPS 0.00001
#define LB(x) ((x)&(-(x)))
template<typename T>INL T Max(REG T x,REG T y){return MAX(x,y);}
template<typename T>INL T Min(REG T x,REG T y){return MIN(x,y);}
template<typename T>INL T Abs(REG T x){return ABS(x);}
template<typename T>INL T lb(REG T x){return LB(x);}
template<typename T>INL void Swap(REG T&x,REG T&y){x^=y^=x^=y;}
template<typename T>INL void Gcd(REG T x,REG T y){while(y^=x^=y^=x%=y);return x;}
template<typename T>
INL void read(REG T&x){
x=0;REG char c=getchar();/*REG T fl=1;*/
while(c<'0'||c>'9'){/*if(c == '-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}/*x*=fl;*/}
int n,a[N];
int com[N];
int dp[N];
int lg[N];
int st[N][30];
void ini(){
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)st[i][0]=(1<<a[i]);
	for(int j=1;j<=25;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=(st[i][j-1]|st[i+(1<<(j-1))][j-1]);
}
int stk[N],top;
int las[N];
void fun1(){
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++){
		int zy=(1<<a[i]);
		for(int j=i-1;j>=0;j--){
			int x=zy,cnt=0;
			while(x&1){
				cnt++;
				x>>=1;
			}
			if(cnt+dp[j]>dp[i]){
				dp[i]=cnt+dp[j];
				com[i]=j;
			}
//			cout<<i<<","<<j<<"::"<<zy<<":"<<cnt<<','<<dp[j]<<':'<<dp[i]<<endl;
			zy|=(1<<a[j]);
		}
//		cout<<com[i]<<' ';
	}
//	puts("");
	int u=n;
	while(u){
		u=com[u];
		stk[++top]=u+1;
	}
	printf("%lld %lld\n",dp[n],top);
	while(top)
		printf("%lld ",stk[top--]);
}
void fun2(){
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=20;i++)las[i]=1;
	ini();
	for(int i=1;i<=n;i++){
		for(int k=0;k<=20;k++){
			int j=las[k]-1;
			int x=(st[j+1][lg[i-j]]|st[i-(1<<lg[i-j])+1][lg[i-j]]),cnt=0;
			while(x&1){
				cnt++;
				x>>=1;
			}
			if(cnt+dp[j]>=dp[i]){
				dp[i]=cnt+dp[j];
				com[i]=j;
			}
			if(las[k]<i){
				int j=las[k];
				int x=(st[j+1][lg[i-j]]|st[i-(1<<lg[i-j])+1][lg[i-j]]),cnt=0;
				while(x&1){
					cnt++;
					x>>=1;
				}
				if(cnt+dp[j]>=dp[i]){
					dp[i]=cnt+dp[j];
					com[i]=j;
				}
			}
			if(las[k]+1<i){
				int j=las[k]+1;
				int x=(st[j+1][lg[i-j]]|st[i-(1<<lg[i-j])+1][lg[i-j]]),cnt=0;
				while(x&1){
					cnt++;
					x>>=1;
				}
				if(cnt+dp[j]>=dp[i]){
					dp[i]=cnt+dp[j];
					com[i]=j;
				}
			}
//			cout<<i<<","<<j<<"::"<<zy<<":"<<cnt<<','<<dp[j]<<':'<<dp[i]<<endl;
//			zy|=(1<<a[j]);
		}
		las[a[i]]=i;
//		cout<<i<<','<<com[i]<<' ';///////////////////////////////////////////////////////////
//		if(com[i]<com[i-1])while(1); 
	}
//	puts("");////////////////////////////////////////////////////////////////////////////////
	int u=n;
	while(u){
		u=com[u];
		stk[++top]=u+1;
	}
	printf("%lld %lld\n",dp[n],top);
	while(top)
		printf("%lld ",stk[top--]);
}
signed main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	read(n);
	if(n<=1000)fun1();
	else fun2(); 
    return 0;
}
/*
dp[i]=MAX(dp[j]+mex{i~j})
*/
