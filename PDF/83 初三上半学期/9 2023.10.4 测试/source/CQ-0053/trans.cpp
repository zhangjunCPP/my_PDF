#include<bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e2 + 2, M = 5e3 + 2;
int n, m, K;
struct Node { int x, y, d, s; }node[N];
namespace Solve1 {
	
}
inline void solve1 () {
	using namespace Solve1;
	int mul1, mul2;
	mul1 = mul2 = 1;
	rep (i, 1, m) mul1 = mul1 * node[i].d % mod, mul2 = mul2 * node[i].s % mod;
	int ans = (K * (K - 1) % mod * mul1 % mod + K * mul2 % mod) % mod;
	printf("%lld\n", ans);
}
namespace Solve2 {
	int col[N], ans = 0;
	inline void calc () {
		int ret = 1;
		rep (i, 1, m) {
			if (col[node[i].x] == col[node[i].y]) ret = ret * node[i].s % mod;
			else ret = ret * node[i].d % mod;
		}
		(ans += ret) %= mod;
	}
	inline void dfs (int u) {
		if (u == n + 1) {
			calc();
			return;
		}
		rep (i, 1, K) {
			col[u] = i;
			dfs(u + 1);
			col[u] = 0;
		}
	}
}
inline void solve2 () {
	using namespace Solve2;
	ans = 0;
	dfs(1);
	printf("%lld\n", ans);
}
namespace Solve3 {
	int f[N][M];
	inline int ksm (int a, int b) {
		int ret = 1;
		while (b) {
			if (b & 1) ret = ret * a % mod;
			a = a * a % mod, b >>= 1;
		}
		return ret;
	}
	int head[N], pos;
	struct Edge { int to, next, d, s; }edge[N << 1];
	inline void add_edge (int u, int v, int d, int s) {
		edge[++pos] = (Edge) {v, head[u], d, s}, head[u] = pos; }
	inline void dfs (int u, int fa) {
		rep (i, 1, K) f[u][i] = 1;
		go (i, u) {
			int v = edge[i].to, d = edge[i].d, s = edge[i].s, sum = 0;
			if (v == fa) continue;
			dfs(v, u);
			rep (j, 1, K) (sum += f[v][j]) %= mod;
			rep (j, 1, K) f[u][j] = f[u][j] * ((sum - f[v][j] + mod) % mod * d % mod + f[v][j] * s % mod) % mod; 
		}
		/*rep (i, 1, K) cout << f[u][i] << " ";
		cout << '\n';*/
	}
}
inline void solve3 () {
	using namespace Solve3;
	rep (i, 0, N - 1) rep (j, 0, M - 1) f[i][j] = 0;
	memset(head, 0, sizeof head), pos = 0;
	rep (i, 1, m)
		add_edge(node[i].x, node[i].y, node[i].d, node[i].s), add_edge(node[i].y, node[i].x, node[i].d, node[i].s);
	dfs(1, 0);
	int ans = 0;
	rep (i, 1, K) (ans += f[1][i]) %= mod;
	printf("%lld\n", ans);
}
inline void solve () {
	cin >> n >> m >> K;
	int lim = 1;
	rep (i, 1, n) {
		if (lim > 1e9) break;
		lim *= K;
	}
	int x, y, d, s;
	rep (i, 1, m) {
		cin >> x >> y >> d >> s;
		if (x > y) swap(x, y);
		node[i] = (Node) {x, y, d, s};
	}
	if (n == 2) return solve1(), void();
	else if (lim < 2e8) return solve2(), void();
	else if (m == n - 1) return solve3(), void();
}
inline void freo () {
	freopen("trans.in", "r", stdin), freopen("trans.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
return 0;
}
/*
1
6 5 8
1 2 4 6
2 3 6 9
3 4 8 6
3 5 2 3
2 6 9 8
*/
