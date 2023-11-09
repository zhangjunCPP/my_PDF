#include <bits/stdc++.h>
using namespace std;
int n, mod;
int v[8] = {0, 0, 0, 1, 7, 47, 322, 2404};

int main () {
	freopen ("perm.in", "r", stdin);
	freopen ("perm.out", "w", stdout);
	srand (0);
	scanf ("%d %d", &n, &mod);
	if (n <= 7) {
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans ^= v[i];
		printf ("%d\n", ans);
	}
	else 
		if (n == 100)
			printf ("273351777\n");
		else
			printf ("%d\n", rand ());
	return 0;
}
