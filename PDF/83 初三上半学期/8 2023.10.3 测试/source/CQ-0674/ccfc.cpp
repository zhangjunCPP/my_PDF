#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=2e5+5, mo=998244353;

char s[maxn];
ll nxt[maxn], pw[maxn], f[maxn], pi[maxn], fa[maxn][20], ans[maxn];
vector<ll> g[maxn];

void dfs(ll x) {
	for(ll y:g[x]) {
		pi[y]+=pi[x];
		dfs(y);
	}
	return ;
}

int main() {
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>s+1;
	ll n=strlen(s+1);
	reverse(s+1,s+n+1);
	pw[0]=1;
	for(ll i=1;i<=n;i++) f[i]=(f[i-1]*131+s[i]-'a')%mo, pw[i]=pw[i-1]*131%mo;
	for(ll i=1;i<=n;i++) {
		if(i&1) continue;
		ll mid=(i>>1);
		if(f[mid]==(f[i]-f[mid]*pw[i-mid]%mo+mo)%mo) pi[mid]=1;
	}
	ll pos=0;
	nxt[1]=0;
	g[0].push_back(1);
	for(ll i=2;i<=n;i++) {
		while(pos&&s[pos+1]!=s[i]) pos=nxt[pos];
		if(s[pos+1]==s[i]) ++pos;
		nxt[i]=pos;
		fa[i][0]=pos;
		g[nxt[i]].push_back(i);
		for(ll j=1;j<20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	dfs(0);
	for(ll i=1;i<=n;i++) {
		ll x=i, len=(x-1)/3;
		for(ll j=19;j>=0;j--) if(fa[x][j]>len) x=fa[x][j];
		x=fa[x][0];
		ans[n-i+1]=pi[x];
	}
	for(ll i=1;i<=n;i++) {
		cout<<ans[i];
		if(i<n) cout<<' ';
		else cout<<'\n';
	}
	return 0;
}
