#include<bits/stdc++.h>
const int maxn = 1e5 + 10, maxm = 1e6 + 10;
int a[maxn], b[maxn];
int ans[maxn];
int vis[maxm];
bool hve[maxm];
int n, m;
int getid(int x) {
	vis[x] = x;
	for (int i = 1; i <= n; i = i % n + 1)
		if (vis[a[i]] != x)
			vis[a[i]] = x;
		else if (vis[b[i]] != x)
			vis[b[i]] = x;
		else
			return i;
	return -1;
}
int main() {
	freopen("marketplace.in", "r", stdin);
	freopen("marketplace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= n; i++)
		hve[a[i]] = hve[b[i]] = 1;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		if (hve[i])
			cnt++, ans[getid(i)]++;
	ans[getid(m + 1)] += m - cnt;
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
