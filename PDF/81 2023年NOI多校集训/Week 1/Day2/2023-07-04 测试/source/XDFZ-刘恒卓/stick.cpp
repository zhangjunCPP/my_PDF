// lhzawa(https://www.cnblogs.com/lhzawa)
#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 50, M = 2.5e3;
int f[M + 5][N + 5];
int main() {
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
	f[0][0] = 1;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (f[i][j]) {
				for (int k = f[i][j]; i + j * k <= M && j + k <= N; k++) {
					f[i + j * k][j + k] = k;
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	for (; q; q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", f[y][x] ? 1 : 0);
	}
	return 0;
}
