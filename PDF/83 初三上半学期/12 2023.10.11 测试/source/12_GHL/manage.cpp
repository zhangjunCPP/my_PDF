#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], b[N], ans[N];

int main () {
	freopen ("manage.in", "r", stdin);
	freopen ("manage.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1, cnt; i <= n; ++i) {
		cnt = 0;
		b[0] = 1e9;
		for (int j = 1; j <= n; ++j)
			b[j] = 0;
		for (int j = 1; j <= m; ++j) {
			if (!b[a[j]]) {
				if (cnt < i) {
					b[a[j]] = j;
					++cnt;
					++ans[i];
				}
				else {
					int lt = 0;
					for (int k = 1; k <= n; ++k)
						if (b[k] < b[lt] && b[k])
							lt = k;
					printf ("%d %d\n", lt, b[lt]);
					b[lt] = 0;
					b[a[j]] = j;
					++ans[i];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf ("%d ", ans[i]);
	return 0;
} 
