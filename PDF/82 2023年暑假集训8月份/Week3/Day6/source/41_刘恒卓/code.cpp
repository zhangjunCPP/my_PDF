#include<bits/stdc++.h>
using ll = long long;
int main() {
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll s = a * b - 1;
	for (ll n = 1; n <= ll(2e5); n++) {
		ll p = s - n;
		ll l = 0, r = n >> 1;
		for (ll mid; l <= r; ) {
			mid = (l + r) >> 1;
			if (mid * (n - mid) == p) {
				for (int i = 1; i <= mid; i++) {
					printf("0");
				}
				for (int i = 1; i <= n - mid; i++) {
					printf("1");
				}
				return 0;
			} else if (mid * (n - mid) < p) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
	return 0;
}
