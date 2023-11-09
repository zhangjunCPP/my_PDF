#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
const ll mod=998244353;
ll n;
ll d[N];
ll dp[N][2];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<n;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		d[a]++;d[b]++;
	}
	if(d[1]==n-1) printf("%lld",n);
	else{
		dp[1][0]=dp[1][1]=1;
		for(ll i=2;i<n;i++){
			dp[i][0]=dp[i-1][1];
			dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
		}
		printf("%lld",(dp[n-1][0]+dp[n-1][1])%mod);
	}
	return 0;
}
