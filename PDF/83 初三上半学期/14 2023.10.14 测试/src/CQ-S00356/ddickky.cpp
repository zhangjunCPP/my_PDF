#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=2e5+5, mo=998244353;

ll n,q,A=2e5;
ll a[maxn], f[maxn], vis[maxn], pw[maxn];

ll qpow(ll a,ll p) {
	ll res=1;
	while(p) {
		if(p&1) res=res*a%mo;
		p>>=1, a=a*a%mo; 
	}
	return res;
}

ll solve(ll l,ll r) {
	ll res=1;
	for(ll i=l;i<=r;i++) {
		for(ll j=1;j*j<=a[i];j++) if(a[i]%j==0) vis[j]=vis[a[i]/j]=1;
	}
	for(int i=A;i>=1;i--) {
		if(!vis[i]) continue;
		f[i]=0;
		for(int j=l;j<=r;j++) if(a[j]%i==0) f[i]++;
		ll tmp=f[i];
		for(int j=i+i;j<=A;j+=i) {
			if(!vis[j]) continue;
			f[i]-=f[j];
		}
		res=res*qpow(i,(pw[f[i]]-1)*pw[tmp-f[i]]%(mo-1))%mo;
	}
	for(ll i=l;i<=r;i++) {
		for(ll j=1;j*j<=a[i];j++) vis[j]=vis[a[i]/j]=0;
	}
	return res;
}

int main() {
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=A;i++) pw[i]=pw[i-1]*2%(mo-1);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1,l,r;i<=q;i++) {
		cin>>l>>r;
		cout<<solve(l,r)<<'\n';
	}
	return 0;
}
