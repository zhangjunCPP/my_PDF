#include<bits/stdc++.h>
using LL = long long;
const LL mod = 1000000007LL;
LL qpow(LL a, LL b) {
	LL v = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1) v = v * a % mod;
	return v;
}
LL A(int n, int m) {
	LL tot = 1;
	for (int i = n, j = 1; j <= m; i--, j++) tot = 1LL * tot * i % mod;
	return tot;	
}
const int maxn = 1e2 + 10;
LL dif[maxn][maxn], sam[maxn][maxn];
bool vis[maxn][maxn];
int n, m, k;
namespace solve1 {
	bool check() {return n <= 9 || k == 3;}
	LL ans;
	int col[maxn];
	void dfs(int x, int lim, LL tot) {
		if (lim > k || ! tot) return ;
		if (x == n + 1) {
			ans = (ans + tot * A(k, lim) % mod) % mod;
			return ;
		}
		for (int i = 1; i <= lim; i++) {
			col[x] = i;
			LL ntot = tot;
			for (int j = 1; j < x; j++) ntot = ntot * (i != col[j] ? dif[x][j] : sam[x][j]) % mod;
			dfs(x + 1, lim, ntot);
		}
		for (int j = 1; j < x; j++) tot = tot * dif[x][j] % mod;
		col[x] = lim + 1, dfs(x + 1, lim + 1, tot);
	}
	void solve() {
		ans = 0;
		dfs(1, 0, 1LL);
		printf("%lld\n", ans);
	}
}
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dif[i][j] = sam[i][j] = 1LL;
	for (int i = 1; i <= m; i++) {
		int x, y;
		LL a, b;
		scanf("%d%d%lld%lld", &x, &y, &a, &b);
		dif[x][y] = dif[y][x] = dif[y][x] * a % mod, sam[x][y] = sam[y][x] = sam[y][x] * b % mod;
	}
	solve1::solve();
}
int main() {
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (; T; T--) solve();
	return 0;
}