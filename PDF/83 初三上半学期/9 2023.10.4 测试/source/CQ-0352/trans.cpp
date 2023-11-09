#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
int T, n, m, k;
int x[N], y[N], dif[N], sam[N];
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
	freopen ("trans.in", "r", stdin);
	freopen ("trans.out", "w", stdout);
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d %d", &n, &m, &k);
		if (n == 2) {
			int df = 1, sm = 1;
			for (int i = 1; i <= m; ++i) {
				scanf ("%d %d %d %d", &x[i], &y[i], &dif[i], &sam[i]);
				df = (df * dif[i]) % mod;
				sm = (sm * sam[i]) % mod;
			}
			int ans = k * sm % mod + k * (k - 1) % mod * df % mod;
			printf ("%d\n", ans);
		}
		else {
			for (int i = 1; i <= m; ++i)
				scanf ("%d %d %d %d", &x[i], &y[i], &dif[i], &sam[i]);
			printf ("0\n");
		}
	}
	return 0;
} 
