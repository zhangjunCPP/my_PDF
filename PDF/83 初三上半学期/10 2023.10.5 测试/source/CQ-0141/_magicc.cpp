#include<bits/stdc++.h>
using LL = long long;
const int maxn = 1e3 + 10;
int n;
int l[maxn], r[maxn];
LL C[maxn];
namespace solve1 {
	bool check() {
		for (int i = 1; i <= n; i++)
			if (l[i] != i || r[i] != i) return false;
		return true;
	}
	void solve() {printf("0\n");}
}
namespace solve2 {
	bool check() {return n <= 20;}
	const int maxnn = 20;
	LL f[1 << maxnn];
	void solve() {
		for (int i = 0; i < n; i++) l[i] = l[i + 1] - 1, r[i] = r[i + 1] - 1, C[i] = C[i + 1];
		memset(f, -0x3f, sizeof(f));
		f[0] = 0;
		for (int s = 1; s < (1 << n); s++) {
			for (int i = 0; i < n; i++) {
				if (! ((s >> i) & 1)) continue;
				LL tot = 0;
				for (int j = l[i]; j <= r[i]; j++) tot += C[i] * (! ((s >> j) & 1));
				f[s] = std::max(f[s], f[s ^ (1 << i)] + tot);
			}
		}
		printf("%lld\n", f[(1 << n) - 1]);
	}
}
namespace solve3 {
	bool check() {
		bool flg6 = 1;
		for (int i = 1; i <= n; i++)
			flg6 &= (l[i] == std::max(i - 6, 1) && r[i] == std::min(i + 6, n) && C[i] == 1);
		bool flg7 = 1;
		for (int i = 1; i <= n; i++)
			flg7 &= (l[i] == std::max(i - 7, 1) && r[i] == std::min(i + 7, n) && C[i] == 1);
		return flg6 | flg7;
	}
	int p[maxn];
	bool vis[maxn];
	void solve() {
		for (int i = 1; i <= n; i++) p[i] = i;
		std::sort(p + 1, p + n + 1, [](int x, int y) {
			return r[x] - l[x] > r[y] - l[y];
		});
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = p[i];
			vis[x] = 1;
			for (int j = l[x]; j <= r[x]; j++) ans += ! vis[j];
		}
		printf("%d\n", ans);
	}
}
namespace solve4 {
	bool check() {
		for (int i = 1; i <= n; i++)
			if (std::max(i - l[i], r[i] - i) > 2) return false;
		return true;
	}
	LL f[100][4][4][4];
	bool vis[100][4][4][4];
	LL dfs(int w, int a, int b, int c) {
		if (w == n + 1) return 0LL;
		if (vis[w][a][b][c]) return f[w][a][b][c];
		vis[w][a][b][c] = 1;
		if (w == 1) return f[w][a][b][c] = std::max(dfs(2, 0, 1, 2), dfs(2, 0, 2, 1));
		LL tot = 0;
		if (b < c) tot += C[w - 1] * (r[w - 1] >= w);
		else tot += C[w] * (l[w] <= w - 1);
		if (w > 2) {
			if (a < c) tot += C[w - 2] * (r[w - 2] >= w);
			else tot += C[w] * (l[w] <= w - 2);
		}
		LL val;
		if (b < c) val = std::max({dfs(w + 1, 1, 2, 3), dfs(w + 1, 1, 3, 2), dfs(w + 1, 2, 3, 1)});
		else val = std::max({dfs(w + 1, 2, 1, 3), dfs(w + 1, 3, 1, 2), dfs(w + 1, 3, 2, 1)});
		return f[w][a][b][c] = tot + val;
	}
	void solve() {
		printf("%lld\n", dfs(1, 0, 0, 1));
	}
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magicc.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%lld", &l[i], &r[i], &C[i]);
	if (solve1::check()) {solve1::solve(); return 0;}
	if (solve2::check()) {solve2::solve(); return 0;}
	if (solve3::check()) {solve3::solve(); return 0;}
	if (solve4::check()) {solve4::solve(); return 0;}
	return 0;
}