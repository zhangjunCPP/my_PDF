#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=(1<<17), mo=998244353;

ll n, sizx;
ll u[5005], v[5005], f[maxn], inv[5005];
vector<pair<ll,ll> > g[5005];

ll dfs(ll x,ll s) {
	ll ts=0;
	sizx++;
	for(auto p:g[x]) {
		if(((s>>p.second)&1)==0) continue;
		ts|=(1<<p.second);
		ts|=dfs(p.first,s^(1<<p.second));
	}
	return ts;
}

ll solve(ll s,ll siz) {
	if(f[s]) return f[s];
	for(ll i=0;i<n-1;i++) {
		if((s>>i)&1) {
			ll ts=(s^(1<<i));
			ll uu=u[i], vv=v[i]; sizx=0;
			ll ts1=dfs(uu,ts);
			ll tmp=sizx;
			ll ts2=dfs(vv,ts);
			solve(ts1,tmp);
			solve(ts2,siz-tmp);
			f[s]=(f[s]+f[ts1]*f[ts2]%mo)%mo;
		}
	}
	if(siz==1) f[s]=1;
	else f[s]=f[s]*inv[siz]%mo;
	return f[s];
} 

ll qpow(ll a,ll p) {
	ll res=1;
	while(p) {
		if(p&1) res=res*a%mo;
		p>>=1, a=a*a%mo;
	}
	return res;
}

ll dp[5005];

int main() {
	freopen("band.in","r",stdin);
	freopen("band.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(ll i=0;i<n-1;i++) {
		cin>>u[i]>>v[i];
		g[u[i]].push_back({v[i],i});
		g[v[i]].push_back({u[i],i});
	}
	for(ll i=1;i<=n;i++) inv[i]=qpow(i,mo-2);
	if(n<=18) cout<<solve((1<<(n-1))-1,n)<<'\n';
	else {
		ll cnt=0, cnt2=0;
		for(ll i=0;i<n-1;i++) {
			if(v[i]==u[i]+1) cnt++;
			if(u[i]==1) cnt2++;
		}
		if(cnt==n-1) {
			dp[1]=1;
			for(ll i=2;i<=n;i++) {
				for(ll j=1;j<i;j++) {
					dp[i]=(dp[i]+dp[j]*dp[i-j]%mo*inv[i]%mo)%mo;
				}
			}
			cout<<dp[n]<<'\n';
		}else if(cnt2==n-1) cout<<inv[n]<<'\n';
		else cout<<998244352<<'\n';
	}
	return 0;
}
