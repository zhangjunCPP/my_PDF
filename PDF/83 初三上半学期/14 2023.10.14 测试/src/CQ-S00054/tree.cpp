#include<bits/stdc++.h>
using LL = long long;
const LL mod = 998244353;
const int maxn = 1e6 + 10;
int n;
int u[maxn], v[maxn];
namespace solve1 {
	bool check() {
		return n <= 10;
	}
	int ans = 0;
	bool vis[12];
	void dfs(int w) {
		if (w == n) {
			ans++;
			return ;
		}
		if (vis[u[w]] || vis[v[w]]) {
			dfs(w + 1);
		} else {
			vis[u[w]] = 1;
			dfs(w + 1);
			vis[u[w]] = 0;
			vis[v[w]] = 1;
			dfs(w + 1);
			vis[v[w]] = 0;
		}
	}
	void solve() {
		dfs(1);
		printf("%d\n", ans);
	}
}
namespace solve2 {
	bool check() {
		for (int i = 1; i < n; i++) {
			if (std::min(u[i], v[i]) != 1 || std::max(u[i], v[i]) != i + 1) {
				return false;
			}
		}
		return true;
	}
	void solve() {
		printf("%d\n", n);
	}
}
namespace solve3 {
	bool check() {
		for (int i = 1; i < n; i++) {
			if (std::min(u[i], v[i]) != i || std::max(u[i], v[i]) != i + 1) {
				return false;
			}
		}
		return true;
	}
	LL f[2], g[2];
	void solve() {
		f[0] = f[1] = 1LL;
		for (int i = 2; i < n; i++) {
			g[0] = f[0], g[1] = f[1];
			f[0] = (g[0] + g[1]) % mod;
			f[1] = g[0];
		}
		printf("%lld\n", (f[0] + f[1]) % mod);
	}
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u[i], &v[i]);
	}
	if (solve1::check()) {
		solve1::solve();
		return 0;
	}
	if (solve2::check()) {
		solve2::solve();
		return 0;
	}
	if (solve3::check()) {
		solve3::solve();
		return 0;
	}
	return 0;
}