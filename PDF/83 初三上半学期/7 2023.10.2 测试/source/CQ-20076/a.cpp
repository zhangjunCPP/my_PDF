#include<bits/stdc++.h>
template<typename T>
void read(T &x) {
	x = 0;
	char c = getchar();
	for (; ! isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}
using LL = long long;
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int maxn = 2.5e5 + 10;
int n, m, q;
struct node {
	int a1, b1, a2, b2;
};
node p[maxn];
struct opt {
	int a1, b1, a2, b2, d;
};
std::vector<opt> o[8];
namespace solve1 {
	bool check() {
		return std::max({n, m, q}) <= 1000;
	}
	void solve() {
		for (; q; q--) {
			int x, y;
			read(x), read(y);
			LL ans = 0;
			// [L, R] [0, D]
			// if L > R, R < 0, L > D -> 0
			// else
			// L = max(L, 0)
			// -> min(R, D) - L + 1
			std::function<int (int, int, int)> query = [](int L, int R, int D) -> int {
				if (L > R || R < 0 || L > D)
					return 0;
				return std::min(D, R) - std::max(L, 0) + 1;
			};
			for (opt i : o[0]) {
				// 1, 0
				// a2 + d >= x, a1 + d <= x, b1 <= y <= b2
				// d >= x - a2, d <= x - a1
				if (i.b2 < y || y < i.b1)
					continue;
				int L = x - i.a2, R = x - i.a1;
				ans += query(L, R, i.d);
			}
			for (opt i : o[1]) {
				// 1, 1
				// a2 + d >= x, b2 + d >= y, a1 + d <= x, b1 + d <= y
				// d >= x - a2, y - b2, d <= x - a1, y - b1
				int L = std::max(x - i.a2, y - i.b2), R = std::min(x - i.a1, y - i.b1);
				ans += query(L, R, i.d);
			}
			for (opt i : o[2]) {
				// 0, 1
				// a1 <= x <= a2, b2 + d >= y, b1 + d <= y
				// d >= y - b2, d <= y - b1
				if (i.a2 < x || x < i.a1)
					continue;
				int L = y - i.b2, R = y - i.b1;
				ans += query(L, R, i.d);
			}
			for (opt i : o[3]) {
				// -1, 1
				// a2 - d >= x, b2 + d >= y, a1 - d <= x, b1 + d <= y
				// d <= a2 - x, d >= y - b2, d >= a1 - x, d <= y - b1
				int L = std::max(y - i.b2, i.a1 - x), R = std::min(i.a2 - x, y - i.b1);
				ans += query(L, R, i.d);
			}
			for (opt i : o[4]) {
				// -1, 0
				// a2 - d >= x, a1 - d <= x, b1 <= y <= b2
				// d <= a2 - x, d >= a1 - x
				if (i.b2 < y || y < i.b1)
					continue;
				int L = i.a1 - x, R = i.a2 - x;
				ans += query(L, R, i.d);
			}
			for (opt i : o[5]) {
				// -1, -1
				// a2 - d >= x, b2 - d >= y, a1 - d <= x, b1 - d <= y
				// d <= a2 - x, b2 - y, d >= a1 - x, b1 - y
				int L = std::max(i.a1 - x, i.b1 - y), R = std::min(i.a2 - x, i.b2 - y); 
				ans += query(L, R, i.d);
			}
			for (opt i : o[6]) {
				// 0, -1
				// a1 <= x <= a2, b2 - d >= y, b1 - d <= y
				// d <= b2 - y, d >= b1 - y
				if (i.a2 < x || x < i.a1)
					continue;
				int L = i.b1 - y, R = i.b2 - y;
				ans += query(L, R, i.d);
			}
			for (opt i : o[7]) {
				// 1, -1
				// a2 + d >= x, b2 - d >= y, a1 + d <= x, b1 - d <= y
				// d >= x - a2, d <= b2 - y, d <= x - a1, d >= b1 - y
				int L = std::max(x - i.a2, i.b1 - y), R = std::min(i.b2 - y, x - i.a1);
				ans += query(L, R, i.d);
			}
			printf("%lld\n", ans);
		}
	}
}
namespace solve2 {
	bool check() {
		return m == 0;
	}
	#define lowbit(x) ((x) & -(x))
	LL tr[maxn];
	void add(int x, int y) {
		for (int i = x; i <= int(2.5e5); i += lowbit(i))
			tr[i] += y;
	}
	LL query(int x) {
		LL ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += tr[i];
		return ans;
	}
	struct line {
		int x, l, r, v;
	};
	std::vector<line> L;
	struct pt {
		int x, y, id;
	};
	pt u[maxn];
	LL ans[maxn];
	void solve() {
		for (int i = 1; i <= n; i++)
			L.push_back({p[i].a1, p[i].b1, p[i].b2, 1}), L.push_back({p[i].a2 + 1, p[i].b1, p[i].b2, -1});
		std::sort(L.begin(), L.end(), [](line a, line b) {
			return a.x < b.x;
		});
		for (int i = 1; i <= q; i++)
			read(u[i].x), read(u[i].y), u[i].id = i;
		std::sort(u + 1, u + q + 1, [](pt a, pt b) {
			return a.x < b.x;
		});
		for (int i = 1, j = 0; i <= q; i++) {
			for (; j < int(L.size()) && L[j].x <= u[i].x; j++)
				add(L[j].l, L[j].v), add(L[j].r + 1, -L[j].v);
			ans[u[i].id] = query(u[i].y);
		}
		for (int i = 1; i <= q; i++)
			printf("%lld\n", ans[i]);
	}
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++)
		read(p[i].a1), read(p[i].b1), read(p[i].a2), read(p[i].b2);
	for (int i = 1; i <= m; i++) {
		int v, id, d;
		read(v), read(id), read(d);
		o[v].push_back({p[id].a1, p[id].b1, p[id].a2, p[id].b2, d - 1});
		p[id].a1 += dx[v] * d, p[id].a2 += dx[v] * d;
		p[id].b1 += dy[v] * d, p[id].b2 += dy[v] * d;
	}
	for (int i = 1; i <= n; i++)
		o[0].push_back({p[i].a1, p[i].b1, p[i].a2, p[i].b2, 0});
	if (solve1::check())
		solve1::solve();
	else if (solve2::check())
		solve2::solve();
	return 0;
}
