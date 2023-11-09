#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5, mod = 998244353;
ll n, q;
ll a[N], tr[N << 2];

ll gcd (ll a, ll b) {
	ll mx = max (a, b), mn = min (a, b);
	if (!(mx % mn)) return mn;
	if (mn == 1) return mx;
	return gcd (mn, (mx % mn));
}
ll lcm (ll a, ll b) {
	return a * b % mod / gcd (a, b);
}
void build (ll u, ll l, ll r) {
	ll v = u << 1, mid = (l + r) >> 1;
	if (l == r) {
		tr[u] = a[l];
		return;
	}
	build (v, l, mid);
	build (v + 1, mid + 1, r);
	tr[u] = lcm (tr[u << 1], tr [(u << 1) + 1]) % mod;
	return;
}
ll query (ll u, ll l, ll r, ll L, ll R) {
	if (L <= l && r <= R) return tr[u];
	ll mid = (l + r) >> 1, ret = 1, v = u << 1;
	if (L <= mid) ret = lcm (lcm (ret, query (v, l, mid, L, R)), ret);
	if (R > mid) ret = lcm (lcm (ret, query (v + 1, mid + 1, r, L, R)), ret);
	return ret;
}

int main () {
	freopen ("boring.in", "r", stdin);
	freopen ("boring.out", "w", stdout);
	scanf ("%lld %lld", &n, &q);
	for (ll i = 1; i <= n; ++i)
		scanf ("%lld", &a[i]);
	build (1, 1, n);
	for (ll i = 1, k; i <= q; ++i) {
		scanf ("%lld", &k);
		ll Lcm = 1;
		for (ll j = 1, l, r; j <= k; ++j) {
			scanf ("%lld %lld", &l, &r);
			Lcm = lcm (query (1, 1, n, l, r) % mod, Lcm) % mod;
		}
		printf ("%lld\n", (Lcm + mod) % mod);
	}
	return 0;
}
