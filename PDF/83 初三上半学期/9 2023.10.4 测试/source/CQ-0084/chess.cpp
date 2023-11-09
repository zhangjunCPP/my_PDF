#include <bits/stdc++.h> 

using namespace std;

int p, k, n = 1;
int cnt, num;
struct node {
	int a, b, c, d, e, f;
} rg[40055], out[40005];
void sol1() {
	printf("%d\n", (n - 1) * n / 2);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			printf("%d %d\n", i, j);
		}
	}
	return;
}
void sol2() {
	printf("1\n");
	for (int i = 0; i < n; i++) printf("%d ", i);
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d", &p, &k);
	for (int i = 1; i <= k; i++) n *= p;
	if (p == 2) {
		return sol1(), 0;
	}
	if (k == 1) {
		return sol2(), 0;
	}
	return 0;
}
