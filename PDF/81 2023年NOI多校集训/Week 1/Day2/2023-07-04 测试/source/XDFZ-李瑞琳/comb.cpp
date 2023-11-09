#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=5e5+10;
int n,a[N],vis[N],dp[N][2][5],ans;
bool check(int pos){
	if(a[pos]==a[pos+2]&&a[pos+1]==a[pos+3])return true;
	return false; 
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	
	for(int i=1;i<=n;++i)
		if(check(i))vis[i]=1;
	for(int i=1;i<=n;++i){
		dp[i][0][0]=dp[i-1][0][0];
		dp[i][0][0]=max(dp[i][0][0],dp[i-1][1][4]);
		if(vis[i-1])dp[i][1][2]=max(dp[i][1][2],dp[i-1][1][1]);
		if(vis[i-2])dp[i][1][3]=max(dp[i][1][3],dp[i-2][1][1]);
		if(vis[i-3])dp[i][1][4]=max(dp[i][1][4],dp[i-3][1][1]);
		if(vis[i]){
			dp[i][1][1]=max(dp[i][1][1],max(dp[i-1][0][0]+1,max(dp[i-2][0][0]+1,dp[i-3][0][0]+1)));
			dp[i][1][1]=max(dp[i][1][1],max(dp[i-1][1][4]+1,max(dp[i-2][1][3]+1,dp[i-3][1][2]+1)));
		}
	}
	for(int i=0;i<=4;++i)ans=max(ans,max(dp[n][0][i],dp[n][1][i]));
	printf("%d\n",ans*4);
	return 0;
}
