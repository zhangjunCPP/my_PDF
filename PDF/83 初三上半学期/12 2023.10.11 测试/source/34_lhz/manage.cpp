#include<bits/stdc++.h>
const int maxn = 5e5 + 10;
int a[maxn], lst[maxn];
struct query {
	int l, r;
};
query q[maxn];
int bl[maxn];
int ans[maxn];
int cnt[maxn];
int main() {
	freopen("manage.in", "r", stdin);
	freopen("manage.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	ans[0] = m;
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	int b = sqrt(m);
	for (int i = 1; i <= m; i++) bl[i] = (i - 1) / b;
	int _m = 0;
	for (int i = 1; i <= m; i++) {
		if (! lst[a[i]]) {lst[a[i]] = i; continue;}
		q[++_m] = {lst[a[i]] + 1, i}, lst[a[i]] = i;
	}
	m = _m;
	std::sort(q + 1, q + m + 1, [](query x, query y) {
		return bl[x.l] != bl[y.l] ? x.l < y.l : ((bl[x.l] & 1) ? x.r > y.r : x.r < y.r);
	});
	int tot = 0;
	std::function<void (int)> add = [&](int x) -> void {
		x = a[x];
		if (! (cnt[x]++)) tot++;
	};
	std::function<void (int)> del = [&](int x) -> void {
		x = a[x];
		if (! (--cnt[x])) tot--;
	};
	for (int i = 1, l = 1, r = 0; i <= m; i++) {
		while (r < q[i].r) add(++r);
		while (l > q[i].l) add(--l);
		while (r > q[i].r) del(r--);
		while (l < q[i].l) del(l++);
		ans[tot]--;
	}
	for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); 
	return 0;
}
