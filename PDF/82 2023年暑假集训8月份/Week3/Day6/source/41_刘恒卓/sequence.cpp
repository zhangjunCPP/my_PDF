#include<bits/stdc++.h>
const int mod = 998244353;
const int N = 40, K = 250 + 5;
int cnt[K];
int a[N];
int fir[N][2];
int f[N], g[N];
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			a[j + 1] = (i >> j) & 1;
		}
		fir[n][0] = fir[n][1] = n + 1;
		for (int i = n; i; i--) {
			fir[i - 1][0] = fir[i][0], fir[i - 1][1] = fir[i][1];
			fir[i - 1][a[i]] = i;
		}
		int c = 0;
		f[fir[0][0]] = f[fir[0][1]] = 1;
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i <= n; i++) {
				c += f[i], g[i] = f[i], f[i] = 0;
			}
			for (int i = 1; i <= n; i++) {
				f[fir[i][0]] += g[i], f[fir[i][1]] += g[i];
			}
		}
		if (c <= k) {
			cnt[c] = (cnt[c] + 1) % mod;
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}
