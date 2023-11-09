#include<bits/stdc++.h>
std::mt19937_64 rnd(time(0));
using ULL = unsigned long long;
const int maxn = 1e6 + 10;
int u[maxn], v[maxn];
int deg[maxn];
bool vis[maxn];
ULL val[maxn], lval[maxn];
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		deg[u[i]]++, deg[v[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = std::max(ans, deg[i]);
	if (ans == 2) {
		for (int i = 1; i <= n; i++)
			val[i] = lval[i] = rnd();
		for (int i = 1; i <= m; i++)
			if (deg[u[i]] == 2 && deg[v[i]] == 2)
				lval[u[i]] ^= val[v[i]], lval[v[i]] ^= val[u[i]];
		std::basic_string<ULL> p;
		for (int i = 1; i <= n; i++)
			if (deg[i] == 2) p += lval[i];
		std::sort(p.begin(), p.end());
		for (int i = 0; i + 2 < (int)(p.size()); i++)
			if (p[i] == p[i + 1] && p[i] == p[i + 2]) {ans = 3; break;}
	}
	for (int i = 1; i <= m; i++) deg[u[i]]--, deg[v[i]]--;
	printf("%d\n", ans);
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (; T; T--) solve();
	return 0;
}