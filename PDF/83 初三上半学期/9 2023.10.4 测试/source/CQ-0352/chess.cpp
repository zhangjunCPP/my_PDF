#include <bits/stdc++.h>
using namespace std;
int p, k;

int main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	scanf ("%d %d", &p, &k);
	if (k == 1) {
		printf ("1\n");
		for (int i = 0; i < p; ++i)
			printf ("%d ", i);
	}
	else {
		int n = 1;
		for (int i = 1; i <= k; ++i)
			n *= p;
		if (p == 2) {
			printf ("%d\n", n * (n - 1) / 2);
			for (int i = 0; i < n; ++i)
				for (int j = i + 1; j < n; ++j)
					printf ("%d %d\n", i, j);
		}
		else {
			if (k == 2) {
				printf ("%d\n", p * (p + 1));
				for (int i = 0; i < p; ++i) {
					for (int j = 0; j < p; ++j)
						printf ("%d ", i * p + j);
					printf ("\n");
				}
				for (int i = 0; i < p; ++i) {
					for (int j = 0; j < p; ++j) {
						int cnt = 0;
						printf ("%d ", i);
						for (int k = 1; k < p; ++k) {
							printf ("%d ", k * p + (cnt + j) % p);
							cnt += i;
						}
						printf ("\n");
					}
				}
			}
			else {
				printf ("0\n");
			}
		}
	}
	return 0;
} 
/*
1 <= k <= 10 
k = 1时 有且仅有一组构造为从0 -- n-1
p = 2时 构造方法为C上2 下n
k = 2时
*/
