#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int minn[124755];
int dp[124755][505];//满足 已经减少了i根，当前平行线群有j根 所需要的最少木棒数
void Freopen(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
}
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	Freopen();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=1;minn[0]=1;
	for(register int i=1;i<=124750;++i){
		dp[i][0]=minn[i]=0x3f3f3f3f;
		int x=min(500,i);
		for(register int j=1;j<=x;++j){
			dp[i][j]=dp[i-j][j-1]+1;
			minn[i]=min(minn[i],dp[i][j]);
			dp[i][0]=min(dp[i][0],dp[i][j]+1);
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n*(n-1)/2<m)puts("0");
		else if(n*(n-1)/2==m)puts("1");
		else printf("%d\n",(minn[n*(n-1)/2-m]<=n));
	}
}
