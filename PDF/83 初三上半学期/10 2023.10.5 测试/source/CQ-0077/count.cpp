#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pb push_back
#define pii pair<ll,ll>
const ll N=1e6+5,mod=998244353,inf=0x3f3f3f3f,INF=1e18;
ll n;
ll ans[N],res;
signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		if(n<=1000) {
			for(int i=1;i<=n;i++) 
				for(int j=1;j<=n;j++) 
					ans[i*j]++;
			res=0;
			for(int i=1;i<=n*n;i++) res+=ans[i]*ans[i],ans[i]=0;
			printf("%lld\n",res);
		}
	}
	return 0;
}
