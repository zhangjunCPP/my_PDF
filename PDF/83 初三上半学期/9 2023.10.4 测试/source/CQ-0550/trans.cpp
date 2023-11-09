#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=105;
const int mod=1e9+7;

int fpow(long long a, int b=mod-2) {
	int res=1;
	while (b) {
		if (b&1) res=res*a%mod;
		a=a*a%mod, b>>=1;
	}
	return res;
}

int f[N], vis[N];
int ans, n, m, k, U[N], V[N], di[N], sa[N], a[N];

void dfs2(int u) {
	if (u>n) {
		int cnt=0;
		for (int i=1; i<=n; i++) vis[a[i]]=1;
		for (int i=1; i<=n; i++) cnt+=vis[i];
		for (int i=1; i<=cnt; i++) if (!vis[i]) return;
		for (int i=1; i<=n; i++) vis[i]=0;
		long long res=1;
		for (int i=1; i<=m; i++) {
			if (a[U[i]]==a[V[i]]) res=res*sa[i]%mod;
			else res=res*di[i]%mod;
		}
//		cout<<cnt<<" "<<res<<'\n';
		f[cnt]=(f[cnt]+res)%mod;
		return;
	}
	for (int i=1; i<=k; i++) {
		a[u]=i, dfs2(u+1);
	}
}
void dfs(int u) {
	if (u>n) {
		long long res=1;
		for (int i=1; i<=m; i++) {
			if (a[U[i]]==a[V[i]]) res=res*sa[i]%mod;
			else res=res*di[i]%mod;
		}
		(ans+=res)%=mod;
		return;
	}
	for (int i=1; i<=k; i++) {
		a[u]=i, dfs(u+1);
	}
}
void solve1() {
	ans=0;
	dfs(1);
	printf("%d\n", ans);
}
void solve2() {
	int res=0;
	int kk=k; k=n;
	dfs2(1);
	k=kk;
	for (int i=1, bs=k; i<=n; bs=1ll*bs*(k-i)%mod*fpow(i+1)%mod, i++) {
		res=(res+1ll*f[i]*bs)%mod;
//		cout<<f[i]<<" "<<bs<<'\n';
	}
	printf("%d\n", res);
}

struct edge {
	int to, id;
};
vector<edge> e[N];

void dfs(int u, int dad) {
	for (auto i:e[u]) {
		int v=i.to;
		if (v==dad) continue;
		for (int j=n; j>=1; j--) {
			f[j+1]=(f[j+1]+1ll*f[j]*di[i.id])%mod;
			f[j]=f[j]*(sa[i.id]+di[i.id]*(j-1ll))%mod;
		}
		dfs(v, u);
	}
}
void Tree() {
	for (int i=1; i<=n; i++) f[i]=0;
	f[1]=1;
	dfs(1, 1);
	for (int i=1, bs=k; i<=n; bs=1ll*bs*(k-i)%mod*fpow(i+1)%mod, i++) {
		ans=(ans+1ll*f[i]*bs)%mod;
	}
	printf("%d\n", ans);
}

int main() {
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
	int T=read();
	while (T--) {
		for (int i=1; i<=n; i++) e[i].clear();
		n=read(), m=read(), k=read();
		for (int i=1; i<=m; i++) {
			U[i]=read(), V[i]=read(), di[i]=read(), sa[i]=read();
			e[U[i]].push_back({V[i], i});
			e[V[i]].push_back({U[i], i});
		}
		if (k<=13&&m<=20&&n<=12&&pow(n, k)<=1e7) {
			solve1(); continue;
		}
		if (m==n-1) {
//			cout<<"Ohh\n";
			Tree(); continue;
		}
		solve2();
	}
	return 0;
}
