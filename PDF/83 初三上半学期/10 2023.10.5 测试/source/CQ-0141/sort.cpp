#include<bits/stdc++.h>
using LL = long long;
const int maxn = 7e5 + 10;
int n;
int a[maxn];
namespace solve1 {
	bool check() {
		for (int i = 1; i <= n; i++)
			if (a[i] != i) return false;
		return true;
	}
	LL ans;
	void dfs(int l, int r) {
		if (l >= r) return ;
		ans += r - l + 1;
		int mid = l + (r - l) / 2;
		dfs(l, mid - 1), dfs(mid + 1, r);
	}
	void solve() {
		ans = 0;
		dfs(1, n);
		printf("%lld\n", ans);
	}
}
namespace solve2 {
	LL ans;
	void dfs(std::vector<int> &x) {
		int n = x.size();
		if (n <= 1) return ;
		int pos = x[(n + 1) / 2 - 1];
		std::vector<int> l, r;
		for (int i : x)
			if (i < pos) l.push_back(i);
			else if (i > pos) r.push_back(i);
		ans += n;
		dfs(l), dfs(r);
	}
	void solve() {
		std::vector<int> x;
		for (int i = 1; i <= n; i++) x.push_back(a[i]);
		ans = 0;
		dfs(x);
		printf("%lld\n", ans);
	}
}
int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (solve1::check()) {solve1::solve(); return 0;}
	solve2::solve();
	return 0;
}