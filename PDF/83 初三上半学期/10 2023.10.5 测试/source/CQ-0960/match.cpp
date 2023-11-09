#include <bits/stdc++.h> 
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5;


int T, n, m, ans;
int deg[N], fa[N], siz[N];
pair<int, int> e[N];
int get(int x) {
	return x == fa[x]? x: (fa[x] = get(fa[x]));
}
void solve() {
	scanf("%d%d", &n, &m);
	ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &e[i].fi, &e[i].se);
		deg[e[i].fi]++;
		deg[e[i].se]++;
	}
	for (int i = 1; i <= n; i++) ans = max(ans, deg[i]);
	if (ans < 3) {
		for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
		for (int i = 1; i <= m; i++) {
			int x = get(e[i].fi), y = get(e[i].se);
			if (x ^ y) {
				siz[x] += siz[y], fa[y] = x;
			} else {
				if (siz[x] == 3) {
					ans = 3; break;
				}
			}
		}
		for (int i = 1; i <= n; i++) fa[i] = siz[i] = 0;
 	}
	for (int i = 1; i <= n; i++) deg[i] = 0;
	printf("%d\n", ans);
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
