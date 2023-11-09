#include<bits/stdc++.h>
using namespace std;

const int maxn=4e5+5,inf=2e9;

int n,tot;
int a[maxn], t[maxn], dp[maxn];

int solve(int mx) {
	dp[1]=a[1];
	dp[2]=min(a[1],a[2]);
	if(a[1]+a[2]<=mx) dp[2]=a[1]+a[2];
	for(int i=3;i<=n;i++) {
		dp[i]=min(dp[i-1],a[i]);
		if(a[i-1]+a[i]<=mx) dp[i]=max(dp[i],min(dp[i-2],a[i-1]+a[i]));
	}
	return dp[n];
}

int main() {
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int mx=0,ans=inf; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i], mx=max(mx,a[i]);
	for(int i=1;i<=n;i++) if(a[i]>=mx) t[++tot]=a[i];
	for(int i=2;i<=n;i++) if(a[i]+a[i-1]>=mx) t[++tot]=a[i]+a[i-1];
	sort(t+1,t+tot+1); tot=unique(t+1,t+tot+1)-t-1;
	for(int i=1;i<=tot;i++) ans=min(ans,t[i]-solve(t[i]));
	cout<<ans<<'\n';
	return 0;
}
