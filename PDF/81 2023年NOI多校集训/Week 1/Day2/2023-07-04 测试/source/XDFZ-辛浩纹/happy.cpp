#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+4;
int T[maxn];
int n,k,num[504],cost[504],one;
long long dp[maxn];
int find(int x){
	int l=0,r=n,mid,ans=-1;
	while(l<=r){
		mid=(l+r)/2;
		if(T[mid]<=x){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	for(int i=1;i<=k;++i)scanf("%d%d",&num[i],&cost[i]);
	scanf("%d",&one);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]+one;
		for(int j=1;j<=k;++j){
			int start=T[i]-num[j]+1;
			int id=find(max(0,start));
			if(id!=-1){
				dp[i]=min(dp[i],dp[id]+cost[j]);
			}
		}
		printf("%lld\n",dp[i]-dp[i-1]); 
	}
	return 0;
}
