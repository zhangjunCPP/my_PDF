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
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
貌似可以直接dp 
这道题可转化为合并元素
二分答案试试,用序列中的最小值去找合并的数
考虑和两边的数合并,有后效性
最大值要么不合并,要么和最小值合并,分类讨论
和最小值合并也可以看成,最大值不合并
那么我们的目标就是让最小值最大,似乎可以dp做
dp[i][0/1]表示前i个元素第i个元素与i-1是否合并的最小值 
但是可能生成新的最大值... 
*/
int n,a[200005],b[200005],ans=2e9+1;
void dfs(int k,int mx,int mn){
	if(mx-mn>=ans)
		return ;
	if(k>n){
		ans=min(ans,mx-mn);
		return ;
	}
	dfs(k+1,max(mx,a[k]),min(mn,a[k]));
	if(k<n)
		dfs(k+2,max(mx,a[k]+a[k+1]),min(mn,a[k]+a[k+1]));
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=18)
		dfs(1,0,2e9);
	else{
		int mx=0,mn=1e9;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		work(mx-mn);
	}
	work(ans);
	return 0;
}
