#include<bits/stdc++.h>
using LL = long long;
int op, n;
inline void decode(int &l, int &r, int &k, LL lstans) {
	lstans %= 19260817;
	if(op) {
		l ^= lstans; l = (l % n + n) % n + 1;
		r ^= lstans; r = (r % n + n) % n + 1; if(l > r) std :: swap(l, r);
		k ^= lstans;
		k = (k % std :: min(r - l + 1, 100)) + 1;
	}
}
const int maxn = 2e5 + 10;
int P[maxn];
std::basic_string<std::pair<int, LL> > G[maxn];
int dep[maxn], fa[maxn], siz[maxn], son[maxn];
LL fw[maxn];
void dfs(int u, int fa, LL fw) {
	::fa[u] = fa, ::fw[u] = fw;
	if (fa) G[u].erase(std::find(G[u].begin(), G[u].end(), std::pair<int, LL>{fa, fw}));
	siz[u] = 1, dep[u] = dep[fa] + 1;
	for (std::pair<int, LL> &i : G[u]) {
		int v = i.first;
		LL w = i.second;
		dfs(v, u, w);
		siz[u] += siz[v];
		if (siz[v] > siz[G[u][0].first]) std::swap(G[u][0], i);
	}
}
int top[maxn], dfn[maxn], dtot;
void dfs2(int u) {
	dfn[u] = ++dtot;
	for (std::pair<int, LL> i : G[u]) {
		int v = i.first;
		top[v] = i == G[u][0] ? top[u] : v;
		dfs2(v);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] <= dep[y] ? x : y; 
}
namespace solve1 {
	LL ans;
	int l, r, k;
	int vis[10], sizz[10];
	LL calc(int u) {
		sizz[u] = vis[u];
		LL tot = 0;
		for (std::pair<int, LL> i : G[u]) {
			int v = i.first;
			tot += calc(v);
			sizz[u] += sizz[v];
		}
		if (sizz[u] && sizz[u] < k) tot += fw[u];
		return tot; 
	}
	void dfs(int w, int ch) {
		if (ch == k) {
			ans = std::max(ans, calc(1));
			return ;
		}
		if (w > r) return ;
		dfs(w + 1, ch);
		vis[P[w]] = 1, dfs(w + 1, ch + 1), vis[P[w]] = 0;
	}
	void solve() {
		int Q;
		scanf("%d", &Q);
		ans = 0;
		while (Q--) {
			scanf("%d%d%d", &l ,&r, &k);
			decode(l, r, k, ans);
			ans = 0;
			dfs(l, 0);
			printf("%lld\n", ans);
		}
	}
}
namespace solve2 {
	struct segnode {
		int cnt;
		LL sum;
		int ls, rs;
	};
	std::basic_string<segnode> T;
	int cnt = 0;
	void build(int k, int l, int r) {
		if (l == r) return ;
		int mid = (l + r) >> 1;
		T += {0, 0, 0, 0}, T += {0, 0, 0, 0};
		T[k].ls = ++cnt, T[k].rs = ++cnt;
		build(T[k].ls, l, mid), build(T[k].rs, mid + 1, r); 
	}
	void update(int k, int lk, int l, int r, int x, LL y) {
		T[k] = T[lk];
		T[k].cnt++, T[k].sum += y;
		if (l == r) return ;
		T += {0, 0, 0, 0};
		int mid = (l + r) >> 1;
		if (x <= mid) T[k].ls = ++cnt, update(T[k].ls, T[lk].ls, l, mid, x, y);
		else T[k].rs = ++cnt, update(T[k].rs, T[lk].rs, mid + 1, r, x, y);
	}
	int rt[maxn];
	LL wp[maxn];
	int rk[maxn];
	void solve() {
		for (int i = 1; i <= n; i++) wp[i] = fw[i];
		std::sort(wp + 1, wp + n + 1);
		for (int i = 1; i <= n; i++) rk[i] = std::lower_bound(wp + 1, wp + n + 1, fw[i]) - wp;
		T += {0, 0, 0, 0}, rt[0] = 0;
		build(rt[0], 1, n);
		for (int i = 1; i <= n; i++) {
			T += {0, 0, 0, 0}, rt[i] = ++cnt;
			update(rt[i], rt[i - 1], 1, n, rk[i], wp[rk[i]]);
		}
		int Q;
		scanf("%d", &Q);
		LL ans = 0;
		while (Q--) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			decode(l, r, k, ans);
			ans = 0;
			if (k == 1) {printf("0\n"); continue;}
			int L = 1, R = n, lk = rt[l - 1], rk = rt[r];
			while (L != R) {
				int c = T[rk].cnt - T[lk].cnt;
				LL s = T[rk].sum - T[lk].sum;
				int Mid = (L + R) >> 1;
				if (k > c) {
					k -= c, ans += s, L = Mid + 1;
					lk = T[lk].rs, rk = T[rk].rs;
				}
				else {
					R = Mid;
					lk = T[lk].ls, rk = T[rk].ls;
				}
			}
			ans += 1LL * k * wp[L];
			printf("%lld\n", ans);
		} 
	}
}
int main() {
	freopen("voidtree.in", "r", stdin);
	freopen("voidtree.out", "w", stdout);
	int id;
	scanf("%d%d%d", &id, &op, &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		LL z;
		scanf("%d%d%lld", &x, &y, &z);
		G[x] += {y, z}, G[y] += {x, z};
	}
	for (int i = 1; i <= n; i++) scanf("%d", &P[i]);
	dfs(1, 0, 0LL), top[1] = 1, dfs2(1);
	if (id == 1 || id == 2) {solve1::solve(); return 0;}
	if (id == 13 || id == 14) {solve1::solve(); return 0;}
	return 0;
} 
