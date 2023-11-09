#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=1e6+5, mo=998244353;

ll n,cnt=0;
ll u[maxn], v[maxn], vis[maxn], deg[maxn];
ll f[maxn];

void dfs(ll x) {
	if(x==n) {
		cnt++;
		return ;
	}
	if(vis[u[x]]||vis[v[x]]) dfs(x+1);
	else {
		vis[u[x]]=1, dfs(x+1), vis[u[x]]=0;
		vis[v[x]]=1, dfs(x+1), vis[v[x]]=0;
	}
	return ;
}

int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(ll i=1;i<n;i++) cin>>u[i]>>v[i], deg[u[i]]++, deg[v[i]]++;
	if(n<=10) dfs(1), cout<<cnt<<'\n';
	else {
		if(deg[1]==n-1) cout<<n<<'\n';
		else {
			f[0]=1, f[1]=2;
			for(ll i=2;i<n;i++) f[i]=(f[i-1]+f[i-2])%mo;
			cout<<f[n-1]<<'\n';	
		}
	}
	return 0;
}
