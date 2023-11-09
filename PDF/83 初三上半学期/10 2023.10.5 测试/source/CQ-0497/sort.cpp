#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
暴力是好写的 
*/ 
int n,a[700005],b[700005],flag,ans;
int solve(int l,int r){
	if(l>=r)
		return 0;
	int sum=r-l+1;
	int mid=(l+r)>>1;
	sum+=solve(l,mid-1);
	sum+=solve(mid+1,r);
	return sum;
}
void solve1(int l,int r){
	if(l>=r)
		return ;
	ans+=(r-l+1);
	int mid=(l+r)>>1,las=0;
	int num=l-1;
	for(int i=l;i<=r;i++){
		if(a[i]<a[mid])
			b[++num]=a[i];
	}
	las=num;
	b[++num]=a[mid];
	for(int i=l;i<=r;i++){
		if(a[i]>a[mid])
			b[++num]=a[i];
	}
	for(int i=l;i<=r;i++){
		a[i]=b[i];
	}
	solve1(l,las);
	solve1(las+2,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i)
			flag=1;
	}
	if(!flag){
		work(solve(1,n));
		return 0;
	}
	solve1(1,n);
	work(ans);
	return 0;
}
