#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e6 + 2;
int n, m;
inline void freo () {
	freopen("match.in", "r", stdin), freopen("match.out", "w", stdout); }
int K[N];
vector<int> b[N];
namespace Solve1 {
	int vis1[N], vis2[N];
	int ans1[N], ans2[N];
}
inline void solve1 () {
	using namespace Solve1;
	if (n == 1) {
		for (auto x : b[1]) vis1[x] = 1;
		drep (i, m, 1) printf("%d", vis1[i]);
		return;
	}
	for (auto x : b[1]) vis1[x] = 1;
	for (auto x : b[2]) {
		if (!vis1[x]) vis1[x] = 2;
		else {
			int p = x + 1;
			while (p <= m) {
				if (!vis1[p]) break;
				else if (vis1[p] == 2) vis1[p] = 0;
				++p;
			}
			if (p == m + 1) {
				printf("-1\n");
				return;
			}
			vis1[p] = 2;
			break;
		}
	}
	for (auto x : b[2]) vis2[x] = 1;
	for (auto x : b[1]) {
		if (!vis2[x]) vis2[x] = 2;
		else {
			int p = x + 1;
			while (p <= m) {
				if (!vis2[p]) break;
				else if (vis2[p] == 2) vis2[p] = 0;
				++p;
			}
			if (p == m + 1) {
				printf("-1\n");
				return;
			}
			vis2[p] = 2;
			break;
		}
	}
	int cmp = -1;
	drep (i, m, 1) {
		if (vis1[i] && !vis2[i]) {
			cmp = 0;
			break;
		}
		else if (!vis1[i] && vis2[i]) {
			cmp = 1;
			break;
		}
	}
	if (cmp == 1) {
		drep (i, m, 1) printf("%d", (vis2[i] > 0));
	}
	else drep (i, m, 1) printf("%d", (vis1[i] > 0));
}
namespace Solve2 {
	int S = 0, val[N], ans[N];
}
inline void solve2 () {
	using namespace Solve2;
	rep (i, 1, n) {
		int now = 0;
		for (auto x : b[i]) now |= (1 << x - 1);
		val[i] = now;
	}
	sort(val + 1, val + n + 1);
	int c = 0, all = (1 << m) - 1;
	rep (i, 1, n) {
		rep (j, val[i], all) {
			if (S & j) continue;
			S |= j, ++c;
		}
	}
	int cnt = 0;
	while (S) {
		++cnt;
		ans[cnt] = (S & 1);
		S >>= 1;
	}
	rep (i, 1, n - c) ans[++cnt] = 1;
	if (cnt <= m) {
		drep (i, m, 1) printf("%d", ans[i]);
	}
	else printf("-1\n");
}
signed main () {
	freo();
	scanf("%d%d", &n, &m);
	int x;
	rep (i, 1, n) {
		scanf("%d", &K[i]);
		rep (j, 1, K[i]) {
			scanf("%d", &x);
			b[i].emplace_back(x);
		}
		sort(b[i].begin(), b[i].end(), [&] (int x, int y) { return x > y; });
	}
	if (n <= 2) return solve1(), 0;
	else if (m <= 10) return solve2(), 0;
	else printf("-1\n");
return 0; 
}
