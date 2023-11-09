#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e3 + 2, M = 7;
struct Node { int l, r, c; }node[N];
int n, f[N][(1 << M) + 2], mxlen, mx;
int vec[12];
int veclen;
int L, R, mtc, now, nowS, lim;
bool vis[12];
int a[12];
inline void calc () {
	bool fg = 0;
	if (mtc < 1) fg = 1;
	int ret = 0, tmp, delta = 0;
	int nxtS = (mtc < 1 ? nowS : (nowS >> 1));
	bool cho = 0;
	rep (i, 1, veclen) {
		tmp = nowS | delta, tmp &= ((1 << a[i] - L + 1) - 1);
		if (node[a[i]].l > L) tmp &= (1 << node[a[i]].l - L);
		if (node[a[i]].l < a[i])
			ret += (a[i] - max(node[a[i]].l, L) - __builtin_popcount(tmp)) * node[a[i]].c;
		tmp = nowS | delta, tmp &= (1 << a[i] - L + 1);
		if (node[a[i]].r < now) tmp &= (((1 << node[a[i]].r - L + 1) - 1) ^ (1 << a[i] - L + 1));
		if (node[a[i]].r > a[i])
			ret += (min(node[a[i]].r, now) - a[i] - __builtin_popcount(tmp) + max(0, node[a[i]].r - now)) * node[a[i]].c;
		if (a[i] - L - (mtc >= 1) > -1) nxtS |= (1 << (a[i] - L - (mtc >= 1)));
		if (a[i] == now + 1) cho = 1;
		/*cout << "i : " << i << " " << a[i] << '\n';
		cout << ret << '\n';*/
		delta |= (1 << (a[i] - L));
		if (!fg && a[i] == mtc) fg = 1;
		if (fg) {
			f[now + 1][nxtS] = max(f[now + 1][nxtS], f[now][nowS] + ret);
			/*cout << now << " " << nowS << " " << f[now][nowS] << " " << ret << '\n';
			cout << "->" << '\n';
			cout << now + 1 << " " << nxtS << " " << f[now + 1][nxtS] << '\n';
			cout << a[i] << '\n';*/
		}
	}
}
inline void dfs (int u) {
	if (u == veclen + 1) {
		calc();
		return;
	}
	rep (i, 1, veclen) if (!vis[i]) {
		vis[i] = 1, a[u] = vec[i];
		dfs(u + 1);
		vis[i] = 0, a[u] = 0;
	}
}
namespace Solve1 {
	
}
inline void solve1 () {
	using namespace Solve1;
	
}
inline void solve () {
	cin >> n;
	int l, r, c;
	rep (i, 1, n) {
		cin >> l >> r >> c;
		node[i] = (Node) {l, r, c};
		mxlen = max({mxlen, r - i, i - l});
	}
	//cout << mxlen << '\n';
	//if (n <= 10) return solve1(), void();
	if (!mxlen) return printf("0\n"), void();
	mx = (1 << mxlen + 1) - 1;
	f[1][0] = 0, f[1][1] = (node[1].r - node[1].l) * node[1].c;
	rep (i, 1, n - 1) {
		now = i;
		lim = min(1 << i - 1, mx);
		L = max(i - mxlen, 1), R = min(i + mxlen, n);
		mtc = i + 1 - mxlen;
		rep (S, 0, lim) {
			//cout << i << " " << S << " " << f[i][S] << '\n';
			veclen = 0;
			vec[++veclen] = i + 1, nowS = S;
			rep (j, L, i) if (!((S >> j - L) & 1))
				vec[++veclen] = j;
			dfs(1);
		}
	}
	printf("%lld\n", f[n][min(1 << n - 1, mx)]);
}
inline void freo () {
	freopen("magic.in", "r", stdin), freopen("magic.out", "w", stdout); }
signed main () {
	freo();
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//cin >> _;
	while (_--) solve();
return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
