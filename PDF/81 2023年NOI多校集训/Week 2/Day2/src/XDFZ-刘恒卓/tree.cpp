#include<bits/stdc++.h>
using namespace std;
const int N = 10 + 5, M = 1e6 + 10;
int n;
int dis[N][N];
vector<int> G[N];
int fa[N], dep[N], c[N];
int u[M], v[M];
int d[M];
const long long mod = 998244353;
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u[i], &v[i]);
	}
	if (n <= 10) {
		for (int i = 1; i < n; i++) {
			G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
		}
		function<void (int)> dfs = [&dfs](int u) -> void {
			for (int v : G[u]) {
				if (v == fa[u]) {
					continue;
				}
				fa[v] = u, dep[v] = dep[u] + 1;
				dfs(v);
			}
			return ;
		};
		dfs(1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int u = i, v = j;
				if (dep[u] < dep[v]) {
					swap(u, v);
				}
				for (; dep[u] > dep[v]; u = fa[u], dis[i][j]++);
				for (; u != v; u = fa[u], v = fa[v], dis[i][j] += 2);
			}
		}
		int val = 0;
		for (int s = 0; s < (1 << n); s++) {
			vector<int> d[2];
			for (int i = 1; i <= n; i++) {
				d[(s >> (i - 1)) & 1].push_back(i);
			}
			int mx = 0;
			for (int i : d[0]) {
				for (int j : d[0]) {
					mx = max(mx, dis[i][j]);
				}
			}
			for (int i : d[1]) {
				for (int j : d[1]) {
					mx = max(mx, dis[i][j]);
				}
			}
			c[mx]++;
			val = (val + mx) % mod;
		}
		printf("%d\n", val);
		return 0;
	}
	function<long long (long long, long long)> qpow = [](long long a, long long b) -> long long {
		long long val = 1;
		for (; b; a = a * a % mod, b >>= 1) {
			if (b & 1) {
				val = val * a % mod;
			}
		}
		return val;
	};
	function<int ()> checkB = []() -> int {
		for (int i = 1; i < n; i++) {
			d[u[i]]++, d[v[i]]++;
		}
		return d[1] == n - 1;
	};	
	if (checkB()) {
		printf("%lld\n", qpow(2, n) * 1ll * 2 % mod);
		return 0;
	}
	return 0;
}
