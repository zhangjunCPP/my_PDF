#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
const ll mod=13331;
char s[N];
ll h[N],p[N];
ll w(ll l,ll r){
	ll len=r-l+1;
	return (h[r]-h[l-1]*p[len]%mod+mod)%mod;
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	ll n=strlen(s+1);
	p[0]=1;
	for(ll i=1;i<=n;i++) p[i]=p[i-1]*100%mod;
	for(ll i=1;i<=n;i++) h[i]=(h[i-1]*100+s[i])%mod;
	for(ll i=1;i<=n;i++){
		ll ans=0;
		for(ll len=1;len<=n;len++){
			ll l1=i,r1=i+len-1;
			ll l2=i+len,r2=i+2*len-1;
			ll r3=n,l3=n-len+1;
			if(l3-r2<2) break;
			if(w(l1,r1)==w(l2,r2)&&w(l2,r2)==w(l3,r3)){
				ans++;
			}
		}
		printf("%lld ",ans);
	}
	return 0;
}

