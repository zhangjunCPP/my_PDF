#include<bits/stdc++.h>
using LL = long long;
const int maxT = 1e6 + 10;
int T;
struct Q {LL x; int id;};
Q q[maxT];
namespace solve1 {
	const int maxn = 1000;
	bool check() {return q[T].x <= LL(maxn);}
	LL cnt[maxn * maxn + 10];
	LL ans[maxT];
	void solve() {
		LL tot = 0;
		std::function<void (int, int)> add = [&](int x, int y) -> void {
			tot -= cnt[x] * cnt[x], cnt[x] += y, tot += cnt[x] * cnt[x];
		};
		for (int i = 1; i <= T; i++) {
			for (int j = q[i - 1].x + 1; j <= q[i].x; j++) {
				add(j * j, 1);
				for (int k = 1; k < j; k++) add(j * k, 2);
			}
			ans[q[i].id] = tot;
		} 
		for (int i = 1; i <= T; i++) printf("%lld\n", ans[i]);
	}
}
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) scanf("%lld", &q[i].x), q[i].id = i;
	std::sort(q + 1, q + T + 1, [&](Q a, Q b) {return a.x < b.x;});
	if (solve1::check()) {solve1::solve(); return 0;}
	return 0;
}