#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[200001],a[200001],c[400001];
bool check(int mid){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) dp[j]=1e16;
		dp[0]=c[i];
		for(int j=1;j<=n;j++){
			if(a[j]>=c[i]) dp[j]=min(dp[j],max(a[j],dp[j-1]));
			if(j>=1&&a[j-1]+a[j]>=c[i]) dp[j]=min(dp[j],max(a[j-1]+a[j],dp[j-2]));
		}
		if(dp[n]-c[i]<=mid) return true;
	}
	return false;
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),c[++m]=a[i];
	for(int i=1;i<n;i++) c[++m]=a[i]+a[i+1];
	sort(c+1,c+1+m);
	m=unique(c+1,c+1+m)-c-1;
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(!check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}
