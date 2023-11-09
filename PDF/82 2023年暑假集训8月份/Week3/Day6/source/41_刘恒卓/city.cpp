#include<bits/stdc++.h>
const int N = 2e3 + 10;
std::bitset<N> c[N];
std::vector<int> E[N];
std::vector<int> p[N];
int col[N];
void DFS(int u, int fa) {
	c[u][col[u]] = 1;
	for (int v : E[u]) {
		if (v == fa) {
			continue;
		}
		c[v] = c[u];
		DFS(v, u);
	}
}
int main() {
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		E[x].push_back(y), E[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
		p[col[i]].push_back(i);
	}
	int ans = k - 1;
	for (int i = 1; i <= k; i++) {
		if (p[i].empty()) {
			continue;
		}
		c[p[i][0]].reset(); 
		DFS(p[i][0], 0);
		std::bitset<N> vis, used;
		vis.set(i);
		for (int u = vis._Find_first(); u != N; u = vis._Find_first()) {
			used[u] = 1, vis[u] = 0;
			for (int v : p[u]) {
				vis |= ((~ used) & c[v]);
			}
		}
		int cnt = -1;
		for (int i = 1; i <= k; i++) {
			cnt += int(used[i]);
		}
		ans = std::min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
