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
inline void work(ll k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
有可能是dp,但我觉得贪心也是可做的吧...
我们考虑把所有的能量先加进去(假设现在能量为sum[i]),然后把一个i变成稳定态的贡献就是-sum[i]
从小到大排序贪心?这不太现实
区间长度<=14,这个性质有什么用
还是考虑dp,设dp[l][r]表示区间[l,r]的最大值 
那么dp[i][j]=dp[i+1][j]+val1(val1就是[i,i+7]互相怎么贡献,就是多少个贡献给i,多少个被贡献) 
这样的dp就没有考虑顺序的影响,是错误的
正难则反?先把所有贡献加上,那么就把看成减去权值,第一个数据就把我Hack掉了?
可能是网络流? 
长度小于等于7的去dfs 
还是正难则反,假设i被val[i]覆盖,那么释放i就会得到val[i]的贡献 
*/
int n,l[1005],r[1005],vis[1005],col[1005],a[1005],f;
ll dp[1005][1005],c[1005],ans;
void dfs(int now){
	if(now>n){
		ll sum=0;
		for(int i=1;i<=n;i++){
			col[i]=0;
		}
		for(int i=1;i<=n;i++){
			col[a[i]]=1; 
			for(int j=l[a[i]];j<=r[a[i]];j++){
				if(!col[j])
					sum+=c[a[i]];
			}
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[now]=i;
			vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		l[i]=read();
		r[i]=read();
		c[i]=read();
		if(l[i]!=r[i])
			f=1;
	}
	if(!f){
		work(0);
		return 0;
	}
	if(n<=10){
		dfs(1);
		work(ans);
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int k=j+i-1;
			dp[j][k]=dp[j+1][k];
			for(int p=j+1;p<=k&&p<=j+7;p++){
				if(p>r[j]){
					if(l[p]<=j)
						dp[j][k]+=c[p];
				}
				else{
					if(c[p]>c[j]&&l[p]<=j)
						dp[j][k]+=c[p];
					else
						dp[j][k]+=c[j];
				}
			}
		}
	}
	work(dp[1][n]);
	return 0;
}
