#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,q,dp[1<<17],g[1<<17],a[20];
int gcd(int x,int y){
	if(!x||!y) return x+y;
	if(x<y) x^=y^=x^=y;
	return gcd(y,x%y);
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int s=1;s<(1<<n);++s){
		for(int i=1;i<=n;++i) if((s>>(i-1))&1){
			g[s]=gcd(g[s^(1<<(i-1))],a[i]);
			break;
		}
		dp[s]=g[s];
		for(int t=(s-1)&s;t;t=(t-1)&s) dp[s]=1ll*dp[s]*g[t]%MOD;
	}
	for(int i=1,l,r;i<=q;++i){
		scanf("%d%d",&l,&r);
		printf("%d\n",dp[(1<<r)-(1<<(l-1))]);
	}
	
	return 0;
}
