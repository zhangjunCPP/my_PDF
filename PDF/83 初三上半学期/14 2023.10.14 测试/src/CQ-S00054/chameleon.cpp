#include<bits/stdc++.h>
using LD = long double;
const int maxk = 40 + 5;
LD ans[maxk];
LD tot[maxk];
const int maxn = 1e5 + 10;
struct node {
	int d, c;
	bool op;
};
node a[maxn];
int main() {
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
	int n, k, L;
	scanf("%d%d%d", &n, &k, &L);
	for (int i = 1; i <= n; i++) {
		char opt[5];
		scanf("%d%d%s", &a[i].d, &a[i].c, opt);
		a[i].op = opt[0] == 'D';
	}
	std::sort(a + 1, a + n + 1, [](node x, node y) {
		return x.d < y.d;
	});
	int firDw = -1, lstDw, nowc = 0;
	for (int w = 1; w <= n; w++) {
		int d = a[w].d, c = a[w].c;
		if (a[w].op) {
			ans[c] += 1.0 * (L - d);
			if (firDw == -1) {
				firDw = lstDw = d, nowc = c;
			} else {
				tot[nowc] += 1.0 * (d - lstDw) / 2.0;
				nowc = (nowc + c) % k, lstDw = d;
			}
		} else {
			for (int i = 0; i < k; i++) {
				ans[(nowc + c - i + k) % k] += tot[i];
			}
			if (firDw == -1) {
				ans[c] += 1.0 * d; 
			} else {
				ans[c] += 1.0 * (d - lstDw) / 2.0;
				ans[(c + nowc) % k] += 1.0 * firDw + 1.0 * (d - firDw) / 2.0;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%.1Lf\n", ans[i]);
	}
	return 0;
}