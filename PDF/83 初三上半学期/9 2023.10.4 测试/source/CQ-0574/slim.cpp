#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=3e5+5, N=3e5, mo=998244353;

ll val,len;
ll cnt[maxn], cnt2[maxn], ans[maxn], inv[maxn], a[maxn], vx[maxn];

struct node {
	ll l;
	ll r;
	ll id;
};

map<ll,vector<node> > mp;

ll qpow(ll a,ll p) {
	ll res=1;
	while(p) {
		if(p&1) res=res*a%mo;
		p>>=1, a=a*a%mo; 
	}
	return res;
} 

void add(ll x) {
	++len;
	val=val*cnt[a[x]]%mo;
	--cnt[a[x]];
	return ;
}

void del(ll x) {
	--len;
	++cnt[a[x]];
	val=val*inv[cnt[a[x]]]%mo;
	return ;
}

int main() {
	freopen("slim.in","r",stdin);
	freopen("slim.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n,m,q; cin>>n>>m>>q;
	for(ll i=1;i<=n;i++) cin>>a[i], cnt2[a[i]]++;
	inv[0]=1;
	for(ll i=1;i<=N;i++) inv[i]=qpow(i,mo-2);
	for(ll i=1;i<=q;i++) {
		ll l,r,k;
		cin>>l>>r>>k;
		mp[k].push_back((node){l,r,i});
	}
	for(auto p:mp) {
		ll k=p.first;
		auto vec=p.second;
		ll l=1, r=0; val=1,len=0;
		vx[n]=1;
		for(ll i=n-1;i>=0;i--) vx[i]=vx[i+1]*(m*k%mo+(n-i))%mo;
		for(ll i=1;i<=m;i++) cnt[i]=cnt2[i]+k;
		for(auto x:vec) {
			while(l>x.l) add(--l);
			while(r<x.r) add(++r);
			while(l<x.l) del(l++);
			while(r>x.r) del(r--);
			ans[x.id]=val*vx[len]%mo;
		}
	}
	for(ll i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
