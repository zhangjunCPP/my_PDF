#include<bits/stdc++.h>
const int maxn = 1e6 + 10;
int n, m;
std::vector<int> w[maxn];
namespace solve1 {
	bool check() {return (n <= 10 && m <= 10) || (n <= 1000 && m <= 5) || (m <= 10 && 1LL * n * (1LL << (m * 2)) <= (long long)(1e8));}
	const int maxm = 10;
	bool f[1 << maxm], g[1 << maxm];
	void solve() {
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int x : w[i]) s |= 1 << (x - 1);
			for (int j = 0; j < (1 << m); j++)
				g[j] = f[j], f[j] = 0;
			for (int j = s; j < (1 << m); j++)
				for (int t = 0; t < (1 << m); t++)
					if ((j & t) == j)
						f[t] |= g[t ^ j];
		}
		for (int i = 0; i < (1 << m); i++)
			if (f[i]) {
				for (int j = m - 1; ~ j; j--) printf("%d", (i >> j) & 1);
				return ;
			}
		printf("-1\n");
	}
}
namespace solve2 {
	bool check() {return n <= 2;};
	std::bitset<maxn> vis;
	void print(std::vector<int> &W) {
		for (int x : W) vis[x] = 1;
		for (int i = m; i >= 1; i--) printf("%d", int(vis[i]));
	}
	std::bitset<maxn> a;
	void solve() {
		if (n <= 1) {print(w[1]); return ;}
		for (int i : w[1])
			a[i] = 1;
		for (int i : w[2])
			if (! a[i]) a[i] = 1;
			else {
				int l, r;
				for (l = i - 1; l && a[l]; a[l--] = 0);
				for (r = i + 1; r <= m && a[r]; a[r++] = 0);
				if (r > m) {printf("-1\n"); return ;}
				a[r] = 1;
			}
		for (int i = m; i >= 1; i--) printf("%d", int(a[i]));
	}
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int _n = 0;
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		if (! k) continue;
		++_n;
		for (int x; k; k--) {scanf("%d", &x); w[_n].push_back(x);}
	}
	n = _n;
	if (solve1::check()) {solve1::solve(); return 0;}
	if (solve2::check()) {solve2::solve(); return 0;}
	return 0;
}