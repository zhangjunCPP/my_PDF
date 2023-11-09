#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k,t[100010],num[510],cost[510],p[510],one;
ll dp[100010];
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=k;i++)scanf("%d%d",&num[i],&cost[i]);
	cin>>one;
	fill_n(dp+1,n,1e17);//dp[0]=0
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+one;
		for(int j=1;j<=k;j++){
			while(t[p[j]+1]<t[i]-num[j]+1)p[j]++;
			dp[i]=min(dp[i],dp[p[j]]+cost[j]);
		}
	}
	for(int i=1;i<=n;i++)printf("%lld\n",dp[i]-dp[i-1]);
	return 0;
}
