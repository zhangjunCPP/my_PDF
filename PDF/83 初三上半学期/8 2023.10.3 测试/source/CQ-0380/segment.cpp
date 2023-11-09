#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
const ll INF=1e18;
ll n;
ll a[N],vis[N];
set<ll> f;
ll check(ll l,ll r){
	vis[0]=1;
	for(ll i=1;i<=n;i++) vis[i]=0;
	for(ll i=1;i<=n;i++){
		if(a[i]>r) return 0;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		ll v=a[i];
		if(a[i]<l){
			if(vis[i-1]){
				vis[i+1]=1;
				v=a[i]+a[i+1];
			}
			else if(a[i]+a[i-1]>r){
				vis[i+1]=1;
				v=a[i]+a[i+1];
			}
			else if(a[i+1]<l&&(a[i+1]+a[i+2]<l||a[i+1]+a[i+2]>r)){
				vis[i+1]=1;
				v=a[i]+a[i+1];
			}
			else{
				vis[i-1]=1;
				v=a[i]+a[i-1];
			}
			vis[i]=1;
		}
		if(v<l||v>r) return 0;
	}
	return 1;
}
ll get_max(ll minn){
	ll l=minn,r=2e9;
	ll maxn=INF;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(minn,mid)) r=mid-1,maxn=mid;
		else l=mid+1;
	}
	return maxn-minn;
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),f.insert(a[i]);
	for(ll i=1;i<n;i++) f.insert(a[i]+a[i+1]);
	ll ans=INF;
	for(auto i:f) ans=min(ans,get_max(i));
	printf("%lld",ans);
	return 0;
}
