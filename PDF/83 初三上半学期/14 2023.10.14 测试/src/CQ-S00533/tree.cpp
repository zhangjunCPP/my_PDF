#include<bits/stdc++.h>
#define ll long long
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
初步思路:dp[i][0/1][0/1]表示第i条边a[i]是白/黑,b[i]是白/黑的方案数 
第1个捆绑是dfs
第4个捆绑就是考虑1前面有几个数,答案就是n
第5个捆绑就是线性dp,dp[i][0/1/2]表示前i条边,第i条边染a/b/不染有几种方案 
当现在就有40pts了 
2-SAT?肯定不是
考虑O(n^2)的做法,令dp[i][0/1/2],定义同上
直接往前面暴力扫描 
容易发现,一次二选一完了之后,肯定又是一次二选一,可以O(n^2)预处理出,选a/b后下一次二选一的位置 
*/ 
const ll mod=998244353;
int n,a[1000005],b[1000005],flag,flag1,co[1000005],vis[1000005],ans;
ll f[1000005][3];
void dfs(int now){
	if(now>=n){
		ans++;
		return ;
	}
	if(co[a[now]]||co[b[now]])
		dfs(now+1);
	else{
		co[a[now]]=1;
		dfs(now+1);
		co[a[now]]=0;
		co[b[now]]=1;
		dfs(now+1);
		co[b[now]]=0;
	} 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		a[i]=read();
		b[i]=read();
		if(a[i]!=1||b[i]!=i+1)
			flag=1;
		if(a[i]!=i||b[i]!=i+1)
			flag1=1;
	}
	if(!flag){
		work(n);
		return 0;
	}
	if(!flag1){
		f[1][0]=f[1][1]=1;
		for(int i=2;i<n;i++){
			f[i][0]=(f[i-1][0]+f[i-1][2])%mod;
			f[i][1]=(f[i-1][0]+f[i-1][2])%mod;
			f[i][2]=f[i-1][1];
		}
		work((f[n-1][0]+f[n-1][1]+f[n-1][2])%mod);
		return 0;
	}
	dfs(1);
	work(ans);
	return 0;
}
