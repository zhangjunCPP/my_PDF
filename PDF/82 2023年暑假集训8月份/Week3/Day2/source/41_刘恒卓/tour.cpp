#include<bits/stdc++.h>
const int N = 1e3 + 5;
std::basic_string<int> f[N][N];
int main() {
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 2, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		f[x][y] += i, f[y][x] += i;
	}
	for (int x, y; q; q--) {
		scanf("%d%d", &x, &y);
		if (x == y) {
			int ans = 1;
			for (int i : f[x][x]) {
				ans = std::max(ans, i);
				i * i <= m && (ans = std::max(ans, i * i), 1);
				i * i * i <= m && (ans = std::max(ans, i * i * i), 1);
			}
			for (int z = 1; z <= n; z++) {
				if (z != x) {
					for (int i : f[x][z]) {
						for (int j : f[z][x]) {
							i * j <= m && (ans = std::max(ans, i * j), 1);
						}
					}
				}
			}
			printf("%d\n", ans);
		} else if (f[x][y].empty()) {
			printf("-1\n");
		} else {
			int ans = 1;
			for (int i : f[x][y]) {
				ans = std::max(ans, i);
				i * i * i <= m && (ans = std::max(ans, i * i * i), 1);
				for (int j : f[x][x]) {
					i * j <= m && (ans = std::max(ans, i * j), 1);
				}
				for (int j : f[y][y]) {
					i * j <= m && (ans = std::max(ans, i * j), 1);
				}
			}
			for (int z = 1; z <= n; z++) {
				if (z != x && z != y) {
					for (int i : f[x][z]) {
						for (int j : f[z][y]) {
							i * j <= m && (ans = std::max(ans, i * j), 1);
						}
					}
				}
			}
			printf("%d\n", ans); 
		}
	}
	return 0;
}

