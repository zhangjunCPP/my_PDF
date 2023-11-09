#include<bits/stdc++.h>
const int mod = 998244353;
const int N = 4e2 + 10, M = 6e4 + 10;
int f[M], g[M];
int x[N], y[N];
int pow_3[N];
char s[N];
int main() {
	freopen("big.in", "r", stdin);
	freopen("big.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	pow_3[0] = 1;
	for (int i = 1; i <= n; pow_3[i] = pow_3[i - 1] * 3, i++);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]), x[i]--, y[i]--;
	}
	g[0] = 1;
	for (int i = 1; i <= m; i++) {
		int x = ::x[i], y = ::y[i];
		memset(f, 0, sizeof(f));
		for (int s = 0; s < pow_3[n]; s++) {
			int u = (s / pow_3[x]) % 3, v = (s / pow_3[y]) % 3;
			int t = s + pow_3[x] * (u < 2) + pow_3[y] * (v < 2);
			f[t] = (f[t] + g[s]) % mod, f[s] = (f[s] + g[s]) % mod; 
		}
		for (int s = 0; s < pow_3[n]; s++) {
			g[s] = f[s];
		}
	}
	int q;
	scanf("%d", &q);
	for (; q; q--) {
		scanf("%s", s);
		int sum = 0;
		for (int i = 0; i < n; sum += pow_3[i] * 2 * (s[i] == '1'), i++);
		printf("%d\n", f[sum]);
	}
	return 0;
}
