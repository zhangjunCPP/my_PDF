#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 5, mod = 998244353;
int n, m, q, id;
int s[N], inv[N];
vector <int> G[N];

int qpow (int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int main () {
	freopen ("umi.in", "r", stdin);
	freopen ("umi.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &id);
	inv[0] = 1;
	for (int i = 1; i <= m; ++i)
		inv[i] = inv[i - 1] * i % mod;
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &s[i]);
	for (int i = 1, u, v; i < n; ++i) {
		scanf ("%d %d", &u, &v);
		G[u].push_back (v);
		G[v].push_back (u);
	}
	scanf ("%d", &q);
	while (q--) {
		int a, b;
		scanf ("%d %d", &a, &b);
		long long ans = inv[m] * qpow (inv[2 * abs (a - b)], mod - 2) % mod;
		ans = ans * inv [2 * abs (a - b)] % mod;
		printf ("%lld\n", ans);
	}
	return 0;
} 
