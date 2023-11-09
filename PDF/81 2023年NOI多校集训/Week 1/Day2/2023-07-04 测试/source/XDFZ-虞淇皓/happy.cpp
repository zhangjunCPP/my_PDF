#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10,K=510;
int n,k,t[N],num[K],cost[K],one,sum[N];
signed main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld%lld",&num[i],&cost[i]);
	}
	scanf("%lld",&one);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+one;
		for(int j=1;j<=k;j++){
			int x=lower_bound(t+1,t+n+1,t[i]-num[j]+1)-t;
			sum[i]=min(sum[i],sum[x-1]+cost[j]);
		}
		printf("%lld\n",sum[i]-sum[i-1]);
	}
	return 0;
}
