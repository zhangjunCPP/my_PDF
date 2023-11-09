#include<bits/stdc++.h>
using namespace std;
//499122177
#define p 998244353
int m,n,ans;
int a[20],pre[20];
int dp[(1<<16)+5][20];//使用状态为i的时候,最后一个是j的方案数
int popcount(int x){
	int ret=0;
	while(x){
		x-=(x&-x);
		++ret;
	}
	return ret;
}
void Freopen(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i+=a[i]){
		for(int j=1;j<a[i];j++)if(a[i]!=a[i+j])
			return puts("0"),0;
		a[n++]=a[i];
	}
	pre[0]=a[0];for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<(1<<m);i++){
		int nxt=lower_bound(pre,pre+n,popcount(i))-pre;
		if(pre[nxt]!=popcount(i))continue;
		int len=a[nxt];
		if(nxt==0){
			for(int j=0;j<m;j++)if(i>>j&1){
				if(j-len+1>=0&&((((((1<<(j+1))-1)^((1<<(j-len+1))-1))))&i)==(((((1<<(j+1))-1)^((1<<(j-len+1))-1)))))
					dp[i][j]=1;
				if(j+len-1<m&&(((((1<<(j+len))-1)^((1<<j)-1)))&i)==(((1<<(j+len))-1)^((1<<j)-1)))
					dp[i][j]=1;
			}
		}
		else if(len!=1){
			for(int j=0,x;j<m;j++)if(i>>j&1){
				if(j-len+1>=0&&((((((1<<(j+1))-1)^((1<<(j-len+1))-1))))&i)==(((((1<<(j+1))-1)^((1<<(j-len+1))-1))))){
					x=(((((1<<(j+1))-1)^((1<<(j-len+1))-1))));
					for(int k=0;k<m;k++)if(!(x>>k&1)&&!(k==j-len))
						dp[i][j]=(dp[i][j]+dp[i^x][k])%p;
				}
				if(j+len-1<m&&(((((1<<(j+len))-1)^((1<<j)-1)))&i)==(((1<<(j+len))-1)^((1<<j)-1))){
					x=((((1<<(j+len))-1)^((1<<j)-1)));
					for(int k=0;k<m;k++)if(!(x>>k&1)&&!(k==j+len))
						dp[i][j]=(dp[i][j]+dp[i^x][k])%p;
				}
			}	
		}
		else{
			for(int j=0;j<m;j++)if(i>>j&1){
				for(int k=0;k<m;k++)if(k!=j-1&&k!=j+1&&(i>>k&1))
					dp[i][j]=(dp[i][j]+dp[i^(1<<j)][k])%p;
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++)
		ans=(ans+dp[(1<<m)-1][i])%p;
	printf("%d",ans);
}
/*for(int j=0;j<=m;j++)if(dp[i][j]){
				for(int k=0,x;k<m;k++)if(k!=j-1&&k!=j+1){
					if(k+len-1<m&&!( (x=(((1<<(k+len))-1)^((1<<k)-1))) & i ))dp[i|x][k+len-1]=(dp[i|x][k+len-1]+dp[i][j])%p;
					if(k-len+1>0&&!( (x=(((1<<(k+1))-1)^((1<<(k-len+1))-1))) & i ))dp[i|x][k-len+1]=(dp[i|x][k-len+1]+dp[i][j])%p;
				}
			}*/