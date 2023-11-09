#include <bits/stdc++.h> 


using namespace std;
typedef long long ll;
const int N = 1e3 + 5, U = 1058576;
int n;
ll ans, f[U], g[N][N];
int l[N], r[N], c[N];
void sol1() {
	for (int i = 0; i < n; i++)  {
		scanf("%d%d%d", &l[i], &r[i], &c[i]);
		l[i]--, r[i]--;
	}
	int all = (1 << n) - 1;
	for (int s = 0; s < all; s++) {
		
		for (int t = all ^ s; t; t -= t & -t) {
			int i = __builtin_ctz(t), to = s | (t & -t);
			ll val = 0;
			for (int j = l[i]; j <= r[i]; j++) {
				if (!(to >> j & 1)) val += c[i];
			}
			f[to] = max(f[to], f[s] + val);
		}
	}
	printf("%lld", f[all]);
}
void sol2() {
//	printf("sol2\n");
	for (int i = 1; i <= n; i++) 
		l[i] = (l[i] != i) * c[i], r[i] = (r[i] != i) * c[i];
	for (int len = 2; len <= n; len++) {
		for (int i = 1, j = len; j <= n; i++, j++) {
			g[i][j] = max(r[i] + g[i + 1][j], l[j] + g[i][j - 1]);
			for (int k = i + 1; k < j; k++) {
				ll res = g[i][k - 1] + g[k + 1][j] + l[k] + r[k];
				g[i][j] = max(g[i][j], res);
			}
		}
	}
	printf("%lld", g[1][n]);
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	scanf("%d", &n);
	if (n <= 20) {
		return sol1(), 0;
	}
	int c1 = 1, jia = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &l[i], &r[i], &c[i]);
		jia = max({jia, i - l[i], r[i] - i});
		c1 &= c[i] == 1;
	}
	if (jia == 0) {
		return printf("0"), 0;
	}
	if (jia == 1) {
		return sol2(), 0;
	}
	return 0;
}
