#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
int n, m, k, T;


void sol1() {
	ll sme = 1;
	ll xys = 1, xyd = 1;
	for (int i = 1, x, y, d, s; i <= m; i++) {
		scanf("%d%d%d%d", &x, &y, &d, &s);
		if (x == y) {
			sme = sme * s % P;
		} else {
			xys = xys * s % P;
			xyd = xyd * d % P;
		}
	}
	ll _same_ = 1ll * k * xys % P * sme % P;
	ll _diff_ = 1ll * (k) * (k - 1ll) % P * xyd % P * sme % P;
	printf("%lld", (_same_ + _diff_) % P);
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	if (n == 2) {
		sol1();
	}
}
int main() {
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	
	return 0;
}
