#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=3e5+5;

ll ans[maxn];
vector<ll> fa[1005];

struct node {
	ll u;
	ll v;
	ll w;
	ll id;
}e[maxn];

bool cmp(node x,node y) {
	return x.w>y.w;
}

ll find(ll pos,ll x) {
	if(fa[x][pos]!=x) return fa[x][pos]=find(pos,fa[x][pos]);
	return x;
}

int main() {
	freopen("hoshi.in","r",stdin);
	freopen("hoshi.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n,m,k; cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w, e[i].id=i;
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=m;i++) {
		ll u=e[i].u, v=e[i].v, mn=min(fa[u].size(),fa[v].size());
		if(u==v) {
			e[i].id=k+1;
			continue;
		}
		ll l=1, r=mn, pos=mn+1;
		while(l<=r) {
			ll mid=l+r>>1;
			ll r1=find(mid-1,u), r2=find(mid-1,v);
			if(r1==r2) l=mid+1;
			else r=mid-1, pos=mid;
		}
		if(pos<mn) {
			ll r1=find(pos-1,u), r2=find(pos-1,v);
			fa[r1][pos-1]=r2;
		}else {
			if(fa[u].size()<pos) fa[u].push_back(u);
			if(fa[v].size()<pos) fa[v].push_back(v);
			ll r1=find(pos-1,u), r2=find(pos-1,v);
			fa[r1][pos-1]=r2;
		}
		ans[e[i].id]=pos;
	}
	for(ll i=1;i<=m;i++) {
		if(ans[i]<=k) cout<<ans[i]<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
