#include<bits/stdc++.h>
using ll = long long;
const ll mod = 65535;
ll qpow(ll a, ll b) {
	ll v = 1;
	for (; b; (b & 1) && (v = v * a % mod), a = a * a % mod, b >>= 1);
	return v;
}
const int N = 18 + 5;
int n;
int a[N];
ll ans;
void dfs(int w, int c, ll sum) {
	if (c > n / 2 || c + (n - w + 1) < n / 2);
	else if (w == n + 1) {
		ans = ans * sum % mod;
	} else {
		dfs(w + 1, c, (sum + a[w]) % mod);
		dfs(w + 1, c + 1, (sum + 256 * a[w]) % mod);
	}
}
void solve() {
	int k;
	scanf("%d", &k);
	n = 0;
	for (int i = 1, x, y; i <= k; i++) {
		scanf("%d%d", &x, &y);
		for (; y; a[++n] = x, y--);
	}
	ans = 1; 
	dfs(1, 0, 0);
	ll t = 1;
	for (int i = 1; i <= n / 2; t = 1ll * t * i, i++);
	for (int i = 1; i <= n - n / 2; t = 1ll * t * i, i++);
	printf("%lld\n", qpow(ans, t));
}
int main() {
	freopen("secret.in", "r", stdin);
	freopen("secret.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for (; _; _--) {
		solve();
	}
	return 0;
}

