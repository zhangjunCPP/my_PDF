#include<bits/stdc++.h>
const int N = 3e5 + 10;
int n;
int Ex[N], Ey[N];
namespace Subtask12 {
	int siz[N];
	std::vector<int> E[N];
	int vis[N];
	void dfs(int u, int fa) {
		siz[u] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				siz[u] += siz[v];
			}
		}
	} 
	int ans[N];
	void dfs(int u, int fa, int all, int &z) {
		ans[u] = 0;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u, all, z);
				ans[u] = std::max(ans[u], siz[v]);
			}
		}
		ans[u] = std::max(ans[u], all - siz[u]);
//		printf("ans[%d] = %d\n", u, ans[u]);
		ans[u] < ans[z] && (z = u, 1);
	}
	void solve() {
		for (int i = 1; i < n; i++) {
			E[Ex[i]].push_back(Ey[i]), E[Ey[i]].push_back(Ex[i]);
		}
		ans[0] = n + 1;
		for (int i = 1; i <= n; i++) {
			int mx = 0, p = 0, cnt = 0;
			for (int v : E[i]) {
//				printf("v = %d, ", v);
				dfs(v, i);
				if (siz[v] > mx) {
					mx = siz[v], cnt = 1, p = v;
				} else {
					cnt += mx == siz[v];
				}
			}
			if (cnt > 1) {
				printf("%d\n", i == 1 ? 2 : i - 1);
			} else {
//				printf("p = %d\n", p);
				int z = 0;
				dfs(p, i, siz[p], z);
				printf("%d\n", z);
			}
		}
	}
}
namespace Subtask3 {
	bool check() {
		for (int i = 1; i < n; i++) {
			if (Ex[i] != i || Ey[i] != i + 1) {
				return 0;
			}
		}
		return 1;
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			int x = i - 1, y = n - i;
			if (x == y) {
				printf("%d\n", i - 1);
			} else if (x > y) {
				printf("%d\n", (x + 1) / 2);
			} else {
				printf("%d\n", i + (y + 1) / 2);
			}
		}
	}
}
namespace Subtask4 {
	bool check() {
		for (int i = 1; i < n; i++) {
			if (Ex[i] != 1 || Ey[i] != i + 1) {
				return 0;
			}
		}
		return 1;
	}
	void solve() {
		printf("2\n");
		for (int i = 2; i <= n; i++) {
			printf("1\n");
		}
	}
}
int main() {
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; scanf("%d%d", &Ex[i], &Ey[i]), i++);
	if (Subtask4::check()) {
		Subtask4::solve();
	} else if (Subtask3::check()) {
		Subtask3::solve();
	} else {
		Subtask12::solve();
	}
	return 0;
}
