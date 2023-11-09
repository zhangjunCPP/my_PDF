#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pb push_back
#define pii pair<ll,ll>
const ll N=5e5+5,mod=998244353,inf=0x3f3f3f3f,INF=1e18;
int n,l[N],r[N],c[N];
ll f[1<<22];
signed main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	int flag0=0,flag6=0,flag7=0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&l[i],&r[i],&c[i]);
		if(r[i]-l[i]>0)flag0=1;
		if(l[i]!=max(i-6,1)||r[i]!=min(i+6,n)||c[i]!=1) flag6=1;
		if(l[i]!=max(i-7,1)||r[i]!=min(i+7,n)||c[i]!=1) flag7=1;
	}
	if(n<=20) {
		for(int i=1;i<(1<<n);i++) {
			for(int j=0;j<n;j++) {
				if(i&(1<<j)) {
					int sum=r[j+1]-l[j+1]+1;
					for(int k=l[j+1]-1;k<=r[j+1]-1;k++) {
						if(i&(1<<k)) sum--;
					}
					f[i]=max(f[i],f[i^(1<<j)]+1ll*sum*c[j+1]);
				}
			}
		}
		printf("%lld",f[(1<<n)-1]);
		return 0;
	}
	if(!flag0) {
		printf("0");
		return 0;
	}
	if(!flag6) {
		int ans=min(n*(n-1)/2,21)+max(n-7,0)*6;
		printf("%d",ans);
	}
	if(!flag7) {
		int ans=min(n*(n-1)/2,28)+max(n-8,0)*7;
		printf("%d",ans);
	}
	return 0;
}
