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
#define M 1000005
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
int ask(int x){
	if(x<=1)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
int main(){
//	int cnt=0;
//	for(int i=2;i*i<=100005;i++){
//		if(ask(i))cnt++,cout<<i<<',';
//	}
//	puts("\n---------------------------");
//	cout<<cnt;
	int cnt=0;
	for(int i=0;i<=500;++i)
		for(int k=1;i+k<=500&&i*k<=100000;++k)cnt++;
	cout<<cnt;
    return 0;
}
/*
2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313
*/
