#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n;
ll ans = 2e9, a[N];
void dfs(int x, ll mx, ll mn, ll du) {
	if (x > n) {
		ans = min(ans, mx - mn);
		return;
	}
	if (mx - mn >= ans) return;
	if (x < n - 1) {
		if (min(a[x], a[x + 1]) < du) {
			dfs(x + 2, max(mx, a[x] + a[x + 1])
			, min(mn, a[x] + a[x + 1]), du);
		}
	}
	dfs(x + 1, max(mx, a[x]), min(mn, a[x]), min(du, a[x]));
}
int main() {
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	dfs(1, 0, 1e9, 1e9);
	printf("%lld", ans);
	return 0;
}
