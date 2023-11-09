#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5, mod = 998244353;
ll n, q, ans;
ll a[N];
vector <ll> G;

ll gcd (ll a, ll b) {
	if (!b)
		return a;
	return gcd (b, a % b);
}
void dfs (ll l, ll r) {
	if (l > r) {
		if (!G.size ())
			return;
		ll tmp = G[0];
		for (ll i = 1; i < G.size (); ++i)
			tmp = gcd (G[i], tmp);
		ans = ans * tmp % mod;
		return;
	}
	G.push_back (a[l]);
	dfs (l + 1, r);
	G.pop_back ();
	dfs (l + 1, r);
	return;
}

int main () {
	freopen ("ddickky.in", "r", stdin);
	freopen ("ddickky.out", "w", stdout);
	scanf ("%lld %lld", &n, &q);
	for (ll i = 1; i <= n; ++i)
		scanf ("%ld", &a[i]);
	while (q--) {
		ll l, r;
		scanf ("%lld %lld", &l, &r);
		ans = 1;
		dfs (l, r);
		printf ("%lld\n", ans);
	}
	return 0;
} 
