#include<bits/stdc++.h>
void read(int &x) {
	x = 0;
	char c = getchar_unlocked();
	for (; ! isdigit(c); c = getchar_unlocked());
	for (; isdigit(c); c = getchar_unlocked()) {
		x = x * 10 + c - '0';
	}
}
const int mod = 998244353;
int qpow(int a, int b) {
	int v = 1;
	for (; b; b >>= 1, a = 1LL * a * a % mod) {
		if (b & 1) {
			v = 1LL * v * a % mod;
		}
	}
	return v;
}
const int maxn = 2e5 + 10;
int iv[maxn];
std::vector<int> id[maxn];
int cnt[maxn];
std::vector<int> val[maxn], ival[maxn];
inline void ins(int v, int x) {
	val[v].push_back(1LL * val[v].back() * val[v].back() % mod * x % mod);
	ival[v].push_back(1LL * ival[v].back() * ival[v].back() % mod * iv[x] % mod);
}
int tot = 1;
inline void upd(int x, int v) {
	for (int i : id[x]) {
		tot = 1LL * tot * ival[i][cnt[i]] % mod;
		cnt[i] += v;
		tot = 1LL * tot * val[i][cnt[i]] % mod;
	}
}
struct query {
	int l, r, id;
};
query q[maxn];
int blo[maxn];
int ans[maxn];
int main() {
	freopen("ddickky.in", "r", stdin);
	freopen("ddickky.out", "w", stdout);
	for (int i = 1; i <= int(2e5); i++) {
		val[i].push_back(1), ival[i].push_back(1);
	}
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x;
		read(x);
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				if (! iv[j]) {
					iv[j] = qpow(j, mod - 2);
				}
				int v = 1;
				while (x % j == 0) {
					x /= j, v *= j, id[i].push_back(v), ins(v, j);
				}
			}
		}
		if (x ^ 1) {
			if (! iv[x]) {
				iv[x] = qpow(x, mod - 2);
			}
			id[i].push_back(x), ins(x, x);
		}
	}
	for (int i = 1; i <= m; i++) {
		read(q[i].l), read(q[i].r), q[i].id = i;
	}
	int B = sqrt(n);
	for (int i = 1; i <= n; i++) {
		blo[i] = (i - 1) / B;
	}
	std::sort(q + 1, q + m + 1, [](query x, query y) {
		return blo[x.l] ^ blo[y.l] ? x.l < y.l : (blo[x.l] & 1 ? x.r > y.r : x.r < y.r);
	});
	for (int i = 1, l = 1, r = 0; i <= m; i++) {
		while (l > q[i].l) {
			upd(--l, 1);
		}
		while (r < q[i].r) {
			upd(++r, 1);
		}
		while (l < q[i].l) {
			upd(l++, -1);
		}
		while (r > q[i].r) {
			upd(r--, -1);
		}
		ans[q[i].id] = tot;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}