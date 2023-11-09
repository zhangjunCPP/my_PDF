#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,mod;
inline ll qpow(ll a,ll b){
	ll ret=1ll;
	for( ; b; b>>=1ll){
		if(b&1ll) ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}
ll g[3];
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout); 
	cin>>n>>mod;
	g[1]=1,g[2]=2;
	ll jc=2ll,ans=0,inv=qpow(2,mod-2);
	for(ll i=3;i<=n;i++){
		jc=jc*i%mod;
		g[i%3]=(g[(i-1)%3]+g[(i-2)%3]*(i-1)%mod)%mod;
		ll sum=((jc-g[i%3]+mod)%mod*inv)%mod;
		ans^=sum;
	}
	cout<<ans;
	return 0;
}
