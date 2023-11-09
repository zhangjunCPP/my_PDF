#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 1000005
#define LL long long
int cnt;
void srt(vector<int>a){
	if(a.size()-1<=1)return ;
	int x=a[(a.size())>>1];
//	cout<<x<<"::\n";
//	for(int i:a)
//		cout<<i<<' ';
//	puts("");
	vector<int>v1,v2;
	v1.push_back(0);
	v2.push_back(0);
	for(int i=1;i<(int)a.size();i++){
		cnt++;
//		cout<<a[i]<<','<<x<<":"<<(a[i]<x)<<endl;
		if(a[i]<x)v1.push_back(a[i]);
		if(a[i]>x)v2.push_back(a[i]);
	}
	srt(v1);
	srt(v2);
}
int n;
vector<int>a;
int main(){
	freopen("sort.in","r",stdin); 
	freopen("sort.out","w",stdout);
	read(n);
	a.push_back(0);
	for(int i=1,x;i<=n;i++)read(x),a.push_back(x);
	srt(a);
	printf("%d",cnt);
	return 0;
}
/*
5
4 3 5 1 2
*/ 
