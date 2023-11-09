#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
}
inline void FRE(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
const int N=7e5+5;
int m;
int a[N];
int sum;
int ff[N];
inline void Sort(int n,int s[]){
	if(n<=1)return;
	int pp=s[(n+1)/2];
	int cnt1=0,cnt2=0;
	int f1[3001],f2[3001];
	for(int i=1;i<=n;++i){
		sum++;
		if(s[i]<pp){
			++cnt1;f1[cnt1]=s[i];
		}
		if(s[i]>pp){
			++cnt2;f2[cnt2]=s[i];
		}
	}
	Sort(cnt1,f1);
	Sort(cnt2,f2);
} 
int main(){
	FRE(); 
	m=rd();
	for(int i=1;i<=m;++i)a[i]=rd();
	Sort(m,a);
	wr(sum);
	return 0;
} 
/*
5
4 3 5 1 2

*/
