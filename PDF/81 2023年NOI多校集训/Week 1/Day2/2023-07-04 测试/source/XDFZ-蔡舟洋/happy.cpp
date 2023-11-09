#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k;
int t[N],m[N],c[N];
int one;
long long dp[N];
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=k;i++)scanf("%d%d",&m[i],&c[i]);
	scanf("%d",&one);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+one;
		for(int j=1;j<=k;j++){
			int tmp=lower_bound(t+1,t+1+n,max(0,t[i]-m[j]+1))-t;
			dp[i]=min(dp[i],dp[tmp-1]+c[j]);
		}
		printf("%lld\n",dp[i]-dp[i-1]);
	}
	return 0;
}
