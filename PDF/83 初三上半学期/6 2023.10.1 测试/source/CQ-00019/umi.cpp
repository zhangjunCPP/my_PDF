#include<bits/stdc++.h>
using LL = long long;
const LL mod = 998244353;
const int maxn = 1e5 + 10, maxm = 2e6 + 10;
int n, m, id;
int s[maxn];
LL fac[maxm], inv[maxm];
LL qpow(LL a, LL b) {
	LL v = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1)
			v = v * a % mod;
	return v;
}
LL C(int n, int m) {
	return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
LL f[maxn], g[maxn];
std::vector<int> G[maxn];
int fa[maxn], dep[maxn], siz[maxn];
void dfs1(int u) {
	dep[u] = dep[fa[u]] + 1, siz[u] = 1;
	if (fa[u])
		G[u].erase(std::find(G[u].begin(), G[u].end(), fa[u]));
	for (int &v : G[u]) {
		fa[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if (siz[v] > siz[G[u][0]])
			std::swap(v, G[u][0]);
	}
}
int dfn[maxn], dt, top[maxn], sd[maxn];
void dfs2(int u) {
	dfn[u] = ++dt, sd[dt] = s[u];
	for (int v : G[u]) {
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
	}
}
struct node {
	LL val;
	int lc, rc, ln, rn, len;
};
node merge(const node &a, const node &b) {
	if (! a.len)
		return b;
	if (! b.len)
		return a;
	node c;
	c.val = a.val * b.val % mod;
	c.lc = a.lc, c.rc = b.rc;
	c.ln = a.ln, c.rn = b.rn;
	c.len = a.len + b.len;
	if (a.rc == b.lc) {
		c.val = c.val * g[a.rn] % mod * g[b.ln] % mod * f[a.rn + b.ln] % mod;
		if (a.ln == a.len)
			c.ln += b.ln;
		if (b.rn == b.len)
			c.rn += a.rn;
	}
	return c;
}
void rev(node& a) {
	std::swap(a.lc, a.rc), std::swap(a.ln, a.rn);
}
node tr[maxn * 4];
void build(int k, int l, int r) {
	if (l == r) {
		tr[k] = {1LL, sd[l], sd[l], 1, 1, 1};
		return ;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tr[k] = merge(tr[k << 1], tr[k << 1 | 1]);
}
node query(int k, int l, int r, int L, int R) {
	if (L <= l && r <= R)
		return tr[k];
	int mid = (l + r) >> 1;
	if (L <= mid && mid < R)
		return merge(query(k << 1, l, mid, L, R), query(k << 1 | 1, mid + 1, r, L, R));
	if (L <= mid)
		return query(k << 1, l, mid, L, R);
	return query(k << 1 | 1, mid + 1, r, L, R);
}
int main() {
	freopen("umi.in", "r", stdin);
	freopen("umi.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &id);
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	fac[0] = inv[0] = 1LL;
	for (int i = 1; i <= int(2e6); i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[int(2e6)] = qpow(fac[int(2e6)], mod - 2);
	for (int i = int(2e6); i > 1; i--)
		inv[i - 1] = inv[i] * i % mod;
	f[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		f[i] = C(i + i, i);
//		for (int j = 0; j < i; j++)
//			f[i] = (f[i] - f[j] * C(2 * (i - j) - 1, i - j) % mod + mod) % mod;
//	}
	for (int i = 1; i <= n; i++)
		f[i] = C(i + i, i) * qpow(i + 1, mod - 2) % mod, g[i] = qpow(f[i], mod - 2);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs1(1), top[1] = 1, dfs2(1), build(1, 1, n);
	int q;
	scanf("%d", &q);
	for (; q; q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int la = a, lb = b;
		node A = {0LL, 0, 0, 0, 0, 0}, B = {0LL, 0, 0, 0, 0, 0};
		for (; top[a] != top[b]; ) {
			if (dep[top[a]] >= dep[top[b]]) {
				node C = query(1, 1, n, dfn[top[a]], dfn[a]);
				rev(C);
				A = merge(A, C);
				a = fa[top[a]];
			}
			else {
				node C = query(1, 1, n, dfn[top[b]], dfn[b]);
				B = merge(C, B);
				b = fa[top[b]];
			}
		}
		int LCA;
		if (dep[a] <= dep[b]) {
			LCA = a;
			node C = query(1, 1, n, dfn[a], dfn[b]);
			A = merge(A, merge(C, B));
		}
		else {
			LCA = b;
			node C = query(1, 1, n, dfn[b], dfn[a]);
			rev(C);
			A = merge(merge(A, C), B);
		}
		printf("%lld\n", A.val * C(m, 2 * (dep[la] + dep[lb] - 2 * dep[LCA] + 1)) % mod);
	}
	return 0;
}
