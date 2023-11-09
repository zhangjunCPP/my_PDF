#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505;
const ll mod=998244353;
ll n,Q;
ll a[N];
ll p[N],tot,vis[N];
void Init(ll lim){
	for(ll i=2;i<=lim;i++){
		if(!vis[i]) p[++tot]=i;
		for(ll j=1;j<=tot&&i*p[j]<=lim;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll power(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
ll ans[N][N];
vector<ll> cnt[200005];
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
	ll maxn=-1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	Init(maxn);
	while(Q--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		if(ans[l][r]){
			printf("%lld\n",ans[l][r]);
			continue;
		}
		for(ll i=1;i<=tot;i++) cnt[p[i]].clear();
		for(ll i=l;i<=r;i++){
			ll x=a[i];
			for(ll j=1;j<=tot;j++){
				ll res=0;
				while(x%p[j]==0){
					x/=p[j];
					res++;
				}
				if(res) cnt[p[j]].push_back(res);
				if(!vis[x]){
					cnt[x].push_back(1);
					break;
				}
			}
		}
		for(ll i=1;i<=tot;i++){
			if(cnt[p[i]].size()){
				sort(cnt[p[i]].begin(),cnt[p[i]].end());
			}
		}
		ll res=1;
		for(ll i=1;i<=tot;i++){
			if(cnt[p[i]].empty()) continue;
			ll len=cnt[p[i]].size();
			for(ll j=0;j<len;j++){
				ll x=power(p[i],cnt[p[i]][j]);
				res=res*power(x,power(2,len-j-1))%mod;
			}
		}
		ans[l][r]=res;
		printf("%lld\n",res);
	}
	return 0;
}
