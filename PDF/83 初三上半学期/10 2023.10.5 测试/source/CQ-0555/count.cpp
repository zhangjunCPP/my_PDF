#include <bits/stdc++.h>
using namespace std;
int t, n;

int main () {
	freopen ("count.in", "r", stdin);
	freopen ("count.out", "w", stdout);
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					if (!((i * j) % k) && (i * j / k <= n))
						++ans;
		printf ("%lld\n", ans);
	}
	return 0;
} 
