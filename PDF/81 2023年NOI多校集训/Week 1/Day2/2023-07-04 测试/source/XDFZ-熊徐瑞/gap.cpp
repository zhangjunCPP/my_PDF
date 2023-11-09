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
int n,a[N];
int pl[N];
int used[N];
int cnt; 
int check(int*a,int*b){
	for(int i=1;i<=n;i++){
		
		int l1=i-1,r1=i+1;
		for(;l1>=1&&a[l1]==a[l1+1]-1;l1--);
		for(;r1<=n&&a[r1]==a[r1-1]+1;r1++);
		l1++,r1--;
		
		int l2=i-1,r2=i+1;
		for(;l2>=1&&a[l2]==a[l2+1]+1;l2--);
		for(;r2<=n&&a[r2]==a[r2-1]-1;r2++);
		l2++,r2--;
		
		if(Max(r1-l1+1,r2-l2+1)!=b[i])return 0;
//		if(a[1]==1&&a[2] == 2&&a[3] == 3&&a[4] == 5&&a[5] == 4&&a[6]==6){
//			if(i == 5)cout<<l<<','<<r<<','<<up<<endl;
//		} 
	}
	return 1;
}
void f(int nw){
	if(nw == n+1){
		
		if(check(pl,a)){
			cnt++;
		if(debug){
			for(int i=1;i<=n;i++)cout<<pl[i]<<' ';
			puts("");
		}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		pl[nw]=i;
		used[i]=1;
		f(nw+1);
		used[i]=0;
	}
	used[pl[nw]]=0;
	pl[nw]=0;
}
signed main(){
	if(!debug){
		freopen("gap.in","r",stdin);
		freopen("gap.out","w",stdout);
	}
	else
		puts("------------------debug------------------"); 
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	f(1);
	printf("%lld",cnt);
    return 0;
}
/*
10 2
13 45 46 60 103 115 126 150 256 516
90 45
450 100
20
*/
