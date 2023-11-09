// lhzawa(https://www.cnblogs.com/lhzawa/)
#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, _N = 18, M = 1 << 16;
int a[N];
int len[N];
int f[2][M][_N];
const int mod = 998244353;
int main() {
	freopen("gap.in", "r", stdin);
	freopen("gap.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int m = 0;
	for (int i = 1; i <= n; len[++m] = a[i], i += a[i]);
	if (n <= 16) {
		for (int l = 1, r = len[1]; r <= n; l++, r++) {
			int s = 0;
			for (int i = l; i <= r; i++) {
				s |= (1 << (i - 1));
			}
			f[0][s][l] = f[0][s][r] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int s = 0; s < (1 << n); s++) {
				for (int j = 1; j <= n; j++) {
					f[1][s][j] = 0;
				}
			}
			for (int s = 0; s < (1 << n); s++) {
				for (int j = 1; j <= n; j++) {
					if (! f[0][s][j]) {
						continue;
					}
					int cnt0 = 0;
					for (int k = 1; k <= len[i + 1]; k++) {
						cnt0 += ((s >> (k - 1)) & 1); 
					}
					for (int l = 1, r = len[i + 1]; r <= n; l++, r++) {
						if (! cnt0) {
							int t = s;
							for (int k = l; k <= r; k++) {
								t |= (1 << (k - 1));
							}
//							printf("%d %d -> %d %d %d\n", s, j, t, l, r);
							if (abs(l - j) > 1) {
								f[1][t][r] = (f[1][t][r] + f[0][s][j]) % mod;
							}
							if (len[i + 1] > 1 && abs(r - j) > 1) {
								f[1][t][l] = (f[1][t][l] + f[0][s][j]) % mod;
							}
						}
						if (r < n) {
							cnt0 += ((s >> r) & 1) - ((s >> (l - 1)) & 1);
						}
					}
				}
			}
			for (int s = 0; s < (1 << n); s++) {
				for (int j = 1; j <= n; j++) {
					f[0][s][j] = f[1][s][j];
//					printf("%d : %d %d -> %d\n", i, s, j, f[0][s][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = (ans + f[0][(1 << n) - 1][i]) % mod;
		}
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}
