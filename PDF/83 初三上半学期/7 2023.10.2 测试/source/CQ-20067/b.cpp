#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, ans;
int a[N], vis[N];

void dfs (int i) {
	if (i == n + 1) {
		int sum = 0, cnt = 0, tmp = 0;
		for (int i = 1; i <= n; ++i)
			if (vis[i])
				sum += a[i], ++cnt;
		double pjs = (double) sum / (double) cnt;
		for (int i = 1; i <= n; ++i)
			if (vis[i])
				if ((double) a[i] > pjs)
					++tmp;
		if (tmp > ans)
			ans = tmp;
		return;
	}
	vis[i] = 1;
	dfs (i + 1);
	vis[i] = 0;
	dfs (i + 1);
	return;
}

int main () {
	freopen ("b.in", "r", stdin);
	freopen ("b.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	dfs (1);
	printf ("%d\n", ans);
	return 0;
} 
