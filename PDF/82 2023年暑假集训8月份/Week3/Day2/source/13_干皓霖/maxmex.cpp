#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;
int a[N], cnt[N];

int main () {
	freopen ("maxmex.in", "r", stdin);
	freopen ("maxmex.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	scanf ("%d", &q);
	for (int i = 1, k; i <= q; ++i) {
		scanf ("%d", &k);
		int mex = 0, ans = 0;
		for (int j = 1; j <= k; ++j) {
			++cnt[a[j]];
			while (cnt[mex])
				++mex;
		}
		for (int j = 1; j <= n - k; ++j) {
			ans = max (ans, mex);
			--cnt[a[j]];
			++cnt[a[j + k]];
			if (!cnt[a[j]] && mex >= a[j])
				mex = a[j];
			while (cnt[mex])
				++mex;
		}
		ans = max (ans, mex);
		for (int j = n - k + 1; j <= n; ++j)
			--cnt[a[j]];
		printf ("%d\n", ans);
	}
	return 0;
} 
