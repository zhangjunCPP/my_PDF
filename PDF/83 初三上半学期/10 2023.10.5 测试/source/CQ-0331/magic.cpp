#include<bits/stdc++.h>
using namespace std;
int n,l[1001],r[1001],c[1001],vis[1001],a[1001];
long long ans,dp[1048577];
bool cmp(int x,int y){
	return c[x]<c[y];
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&l[i],&r[i],&c[i]);
	if(n<=20){
		for(int i=(1<<n)-1;i>=0;i--){
			for(int j=1;j<=n;j++){
				if(i>>(j-1)&1){
					int cnt=0;
					for(int k=l[j];k<=r[j];k++) if(k!=j&&(i>>(k-1)&1)) cnt++;
					dp[i^(1<<(j-1))]=max(dp[i^(1<<(j-1))],dp[i]+1ll*cnt*c[j]);
				}
			}
		}
		printf("%lld\n",dp[0]);
	}
	else{
		for(int i=1;i<=n;i++) a[i]=i;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=l[a[i]];j<=r[a[i]];j++) if(!vis[j]&&j!=a[i]) cnt++;
			ans+=1ll*cnt*c[a[i]];
			vis[a[i]]=1;
		}
		printf("%lld",ans);
	}
	return 0;
}
