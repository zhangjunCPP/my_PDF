#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e7+10;

ll n,mod,f[N],g[N],ans;
ll power(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	ll inv=power(2,mod-2);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod;
	g[1]=f[1],g[2]=f[2];
	for(int i=3;i<=n;i++){
		g[i]=(g[i-1]+g[i-2]*(i-1)%mod)%mod;
		ans^=(f[i]-g[i]+mod)%mod*inv%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
