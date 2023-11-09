#include <bits/stdc++.h>
using namespace std;
int n;

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	scanf ("%d", &n);
	long long sum = 0;
	for (int i = 1, x; i <= n; ++i) {
		scanf ("%d", &x);
		if (i != n)
			sum += x;
	}
	printf ("%lld\n", sum);
	for (int i = 1; i <= n; ++i)
		printf ("%d ", n - i + 1);
	return 0;
} 
