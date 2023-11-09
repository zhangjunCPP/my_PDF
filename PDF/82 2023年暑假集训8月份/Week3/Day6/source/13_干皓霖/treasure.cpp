#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int n, sum1, sum2, sum3, ans = 1e9;
int a[N], vis[N], ANS[N];

void dfs (int u) {
	if (u == n + 1) {
		if ((max ({sum1, sum2, sum3}) - min ({sum1, sum2, sum3})) < ans) {
			ans = (max ({sum1, sum2, sum3}) - min ({sum1, sum2, sum3}));
			for (int i = 1; i <= n; ++i)
				ANS[i] = vis[i];
		}
		return;
	}
	vis[u] = 1, sum1 += a[u];
	dfs (u + 1);
	vis[u] = 0,	sum1 -= a[u];
	
	vis[u] = 2,	sum2 += a[u];
	dfs (u + 1);
	vis[u] = 0,	sum2 -= a[u];
	
	vis[u] = 3,	sum3 += a[u];
	dfs (u + 1);
	vis[u] = 0,	sum3 -= a[u];
	return;
}

int main () {
	freopen ("treasure.in", "r", stdin);
	freopen ("treasure.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	dfs (1);
	for (int i = 1; i <= n; ++i)
		printf ("%d ", ANS[i]);
	return 0;
} 
