#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+1;
ll n;
ll l[N],r[N],w[N];
struct D1{
	ll dp[1<<20];
	int vis[21];
	void solve(){
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if((i>>j)&1) vis[j+1]=1;
			}
			for(int j=0;j<n;j++){
				int s=i^(1<<j);
				int res=0;
				for(int k=l[j+1];k<=r[j+1];k++){
					if(!vis[k]&&k!=j+1) res+=w[j+1];
				}
				dp[s]=max(dp[s],dp[i]+res);
			}
			for(int j=0;j<n;j++){
				if((i>>j)&1) vis[j+1]=0;
			}
		}
		printf("%lld",dp[(1<<n)-1]);
	}
}D1;
struct D2{
	int vis[101];
	void solve(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=l[i];j<=r[i];j++){
				if(!vis[j]) ans++;
			}
			vis[i]=1;
		}
	}
}D2;
struct D3{
	ll dp[N][1<<7];
	ll vis[N];
	void solve(){
		for(ll i=1;i<=n;i++){
			ll t=i-l[i];
			for(ll s=0;s<(1<<t);s++){
				for(ll j=0;j<t;j++){
					if((s>>j)&1){
						ll x=i-j-1;
						vis[x]=1;
						dp[i][s]+=w[i];
					}
				}
				for(ll j=0;j<t;j++){
					if((s>>j)&1) continue;
					ll x=i-j-1;
					if(r[x]>=i) dp[i][s]+=w[x];
					ll tt=x-l[x],res=0;
					for(ll ss=0;ss<(1<<tt);ss++){
						ll flag=1;
						for(ll k=0;k<tt;k++){
							if((ss>>k)&1) continue;
							ll y=j-k-1;
							if(vis[y]){
								flag=0;
								break;
							}
						}
						if(!flag) continue;
						res=max(res,dp[x][ss]);
					}
					dp[i][s]+=res;
				}
				for(ll x=l[i]-1;x;x--){
					if(x+7<i) break;
					if(r[x]>=i){
						dp[i][s]+=w[x];
						ll tt=x-l[x],res=0;
						for(ll ss=0;ss<(1<<tt);ss++) res=max(res,dp[x][ss]);
						dp[i][s]+=res;
					}
				}
				for(ll j=0;j<t;j++){
					if((s>>j)&1){
						ll x=i-j-1;
						vis[x]=0;
					}
				}
			}
		}
		ll ans=0;
		ll tot=n-l[n];
		for(ll i=0;i<(1<<tot);i++) ans=max(ans,dp[n][i]);
		printf("%lld",ans);
	}
}D3;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	int flag=1,ff=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&l[i],&r[i],&w[i]);
		if(l[i]!=r[i]) flag=0;
		if(w[i]>1) ff=0;
	}
	if(n<=20) D1.solve();
	else if(flag) printf("0");
	else if(ff) D2.solve();
	else D3.solve();
	return 0;
}
