#include<bits/stdc++.h>
#define int long long
typedef long long ll;
#define lc (p<<1)
#define rc (p<<1|1)
#define mid ((L+R)>>1)
using namespace std;
const int N=1e5+10,mod=998244353;

ll power(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){a%=mod,b%=mod;return a*b%mod*power(gcd(a,b),mod-2)%mod;}
ll Lcm[N<<2],a[N],n,m;

void build(int p,int L,int R){
	if(L==R){
		Lcm[p]=a[L]%mod;
		return;
	}
	build(lc,L,mid),build(rc,mid+1,R);
	Lcm[p]=lcm(Lcm[lc],Lcm[rc])%mod;
}

ll ask(int p,int L,int R,int l,int r){
	if(l<=L&&R<=r)return Lcm[p];
	ll ans=1;
	if(l<=mid)ans=lcm(ans,ask(lc,L,mid,l,r))%mod;
	if(r>mid)ans=lcm(ans,ask(rc,mid+1,R,l,r))%mod;
	return ans;
}

signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	for(ll i=1,k;i<=m;i++){
		scanf("%lld",&k);
		ll ans=1;
		for(int j=1,l,r;j<=k;j++){
			scanf("%d%d",&l,&r);
			if(r<l)swap(l,r);
			ll pos=ask(1,1,n,l,r)%mod;
			ans=lcm(ans,pos);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
