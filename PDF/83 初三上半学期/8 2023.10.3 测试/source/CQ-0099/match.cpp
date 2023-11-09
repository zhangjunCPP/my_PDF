#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n, m;
int f[1005][1030];
int b[1005];
void sol1() {
	for (int i = 1, k, p; i <= n; i++) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &p);
			b[i] |= 1 << (p - 1);
		}
	}
	int num = 1 << m;
	for (int j = 0; j < num; j++) f[0][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = b[i]; j < num; j++) {
			int cu = (num - 1) ^ j;
			for (int k = cu; k; k = (k - 1) & cu) {
				f[i][j | k] |= f[i - 1][k];
			}
			f[i][j] |= f[i - 1][0];
		}
	}
	for (int j = 0; j < num; j++) {
		if (f[n][j]) {
			for (int k = m - 1; ~k; k--) {
				printf("%d", j >> k & 1);
			}
			return;
		}
	}
	printf("-1");
}
int b0[1000005], b1[1000005];
void sol2() {
	int _k, _p;
	scanf("%d", &_k); while (_k--) scanf("%d", &_p), b0[_p] = 1;
	scanf("%d", &_k); while (_k--) scanf("%d", &_p), b1[_p] = 1;
	for (int i = 1; i <= m; i++) {
		;
	}
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (m <= 10) {
		sol1();
	} else {
		sol2();
	}
	return 0;
}
