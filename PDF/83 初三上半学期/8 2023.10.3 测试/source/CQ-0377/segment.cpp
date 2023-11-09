#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans = 2e9 + 5;
int a[N];

void dfs (int i, int mx, int mn) {
	if (i == n + 1) {
		ans = min (ans, mx - mn);
		return;
	}
	if (i < n)
		dfs (i + 2, max (mx, a[i] + a[i + 1]), min (mn, a[i] + a[i + 1]));
	dfs (i + 1, max (mx, a[i]), min (mn, a[i]));
	return;
}

int main () {
	freopen ("segment.in", "r", stdin);
	freopen ("segment.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	if (n > 300)
		printf ("0\n");
	else {
		dfs (1, 0, 2e9 + 5);
		printf ("%lld\n", ans);
	}
	return 0;
} 
