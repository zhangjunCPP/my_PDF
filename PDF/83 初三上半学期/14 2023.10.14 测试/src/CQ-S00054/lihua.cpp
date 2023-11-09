#include<bits/stdc++.h>
int n;
namespace solve1 {
	const int maxn = 10 + 3;
	char s[maxn][33];
	bool check() {
		return n <= 10;
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			scanf("%s", s[i] + 1);
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			scanf("%s", s[0] + 1);
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				ans++;
				int k;
				for (k = 1; k <= std::min(strlen(s[0] + 1), strlen(s[i] + 1)) && s[0][k] == s[i][k]; k++, ans++);
				if (k > strlen(s[0] + 1) && strlen(s[0] + 1) == strlen(s[i] + 1)) {
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
}
int main() {
	freopen("lihua.in", "r", stdin);
	freopen("lihua.out", "w", stdout);
	scanf("%d", &n);
	if (solve1::check()) {
		solve1::solve();
		return 0;
	}
	return 0;
}