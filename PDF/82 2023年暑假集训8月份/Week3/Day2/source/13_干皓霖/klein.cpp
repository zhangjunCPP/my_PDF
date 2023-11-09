#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n, q, x, y, X, Y;

ll js (ll a, ll b, ll c, ll d) {
	return abs (a - c) + min (abs (b - d), abs (n - b - d));;
}
void solve () {
	ll ans1 = js (x, y, X, Y);
	// 不用克莱因边的情况
	ll ans2 = 0;
	if (x <= ((n + 1) >> 1))
		ans2 = js (0, y, x, y) + js (n, n - y, X, Y) + 1ll;
	else
		ans2 = js (n, y, x, y) + js (0, n - y, X, Y) + 1ll;
	ll ans = min (ans1, ans2);
	printf ("%lld\n", ans);
}

int main () {
	freopen ("klein.in", "r", stdin);
	freopen ("klein.out", "w", stdout);
	scanf ("%lld %lld", &n, &q);
	for (ll i = 1; i <= q; ++i) {
		scanf ("%lld %lld %lld %lld", &x, &y, &X, &Y);
		solve ();
	}
	return 0;
} 
/*
保证最优策略中（i，0） - （i，n） 与 （0，j） - （n，n - j） 两种边至多各走一次 
*/
