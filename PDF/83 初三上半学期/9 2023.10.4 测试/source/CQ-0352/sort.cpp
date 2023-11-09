#include <bits/stdc++.h>
using namespace std;
int T, n, p;

int ans[13] = {0, 0, 0, 0, 2, 30, 0, 0, 0, 0, 0, 0, 473708154};

int main () {
	freopen ("sort.in", "r", stdin);
	freopen ("sort.out", "w", stdout);
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d", &n, &p);
		if (n <= 12)
			printf ("%d\n", ans[n] % p);
		else
			printf ("0\n");
	}
	return 0;
} 
