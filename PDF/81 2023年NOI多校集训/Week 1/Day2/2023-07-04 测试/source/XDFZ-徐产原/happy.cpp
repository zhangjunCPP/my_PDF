#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,once;
int t[100005],num[105],cost[105];
ll dp[100005];
void Freopen(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&num[i],&cost[i]);
	scanf("%d",&once);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+once;
		for(int j=1;j<=m;j++){
			int k=lower_bound(t+1,t+i,t[i]-num[j]+1)-t;
			dp[i]=min(dp[i],dp[k-1]+cost[j]);
		}
	}
	for(int i=1;i<=n;i++)printf("%lld\n",dp[i]-dp[i-1]);
}