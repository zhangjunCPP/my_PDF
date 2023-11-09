#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=1e6+5, mo=1e9+7;

int n,k;
ll fac[maxn], pw[maxn], ifac[maxn], dp[maxn], sdp[maxn];

ll qpow(ll a,ll p) {
	ll res=1;
	while(p) {
		if(p&1) res=res*a%mo;
		p>>=1, a=a*a%mo;
	}
	return res;
}

int main() {
	freopen("arisu.in","r",stdin);
	freopen("arisu.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	pw[0]=fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%mo, pw[i]=pw[i-1]*k%mo;
	ifac[n]=qpow(fac[n],mo-2);
	for(ll i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mo;
	ll ans=0;
	dp[0]=1, sdp[0]=1;
	for(int i=1;i<=n;i++) {
		if(i<=k) dp[i]=sdp[i-1]*fac[i-1]%mo;
		else dp[i]=(sdp[i-1]-sdp[i-k-1]+mo)%mo*fac[i-1]%mo;
		sdp[i]=(sdp[i-1]+dp[i]*ifac[i]%mo)%mo;
	}
	for(ll i=1;i<=n;i++) {
		ll sum=fac[n-1]*ifac[i-1]%mo*dp[i-1]%mo;
		ans=(ans+sum)%mo;
	}
	cout<<(fac[n]-ans+mo)%mo<<'\n';
	return 0;
}
