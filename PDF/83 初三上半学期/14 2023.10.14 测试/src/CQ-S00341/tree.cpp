#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e6 + 2;
int n;
struct Node { int u, v; }node[N];
int du[N];
namespace Solve1 {
	bool vis[12];
	unordered_map<int, int> mp;
	int ans, a[12], ac;
	inline int calc () {
		int ret = 0;
		rep (i, 1, ac) ret = ret * 11 + a[i];
		return ret;
	}
	inline void dfs (int u) {
		if (u == n) {
			int val = calc();
			if (!mp[val]) mp[val] = 1, ++ans;
			return;
		}
		if (!vis[node[u].u] && !vis[node[u].v]) {
			vis[node[u].u] = 1, a[++ac] = node[u].u;
			dfs(u + 1);
			vis[node[u].u] = 0, a[ac--] = 0;
			vis[node[u].v] = 1, a[++ac] = node[u].v;
			dfs(u + 1);
			vis[node[u].v] = 0, a[ac--] = 0;
		}
		else dfs(u + 1);
	}
}
inline void solve1 () {
	using namespace Solve1;
	ans = 0;
	dfs(1);
	printf("%lld\n", ans);
}
namespace Solve2 {
	
}
inline void solve2 () {
	using namespace Solve2;
	printf("%lld\n", n);
}
namespace Solve3 {
	int f[N];
}
inline void solve3 () {
	using namespace Solve3;
	f[1] = 1, f[2] = 2;
	rep (i, 3, N - 1) f[i] = (f[i - 1] + f[i - 2]) % mod;
	printf("%lld\n", f[n]);
}
inline void solve () {
	scanf("%lld", &n);
	int mx = 0;
	rep (i, 1, n - 1) scanf("%lld%lld", &node[i].u, &node[i].v), ++du[node[i].u], ++du[node[i].v];
	rep (i, 1, n) mx = max(mx, du[i]);
	if (n <= 10) return solve1(), void();
	else if (mx == n - 1) return solve2(), void();
	else return solve3(), void();
}
inline void freo () {
	freopen("tree.in", "r", stdin), freopen("tree.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
