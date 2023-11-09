#include<bits/stdc++.h>
using LL = long long;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
int n;
LL a[maxn];
LL f[maxn];
LL solve(LL minn) {
	for (int i = 1; i <= n; i++) {
		f[i] = inf;
		if (a[i] >= minn && f[i - 1] != inf) f[i] = std::max(f[i - 1], a[i]);
		if (i >= 2 && a[i] + a[i - 1] >= minn && f[i - 2] != inf) f[i] = std::min(f[i], std::max(f[i - 2], a[i] + a[i - 1]));
	}
	return f[n];
}
int main() {
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	std::set<LL> s;
	for (int i = 1; i <= n; i++) 
		s.insert(a[i]);
	for (int i = 1; i < n; i++)
		s.insert(a[i] + a[i + 1]);
	std::vector<LL> S;
	for (LL minn : s) S.push_back(minn);
	LL ans = inf;
	for (LL minn : S) ans = std::min(ans, solve(minn) - minn);
	for (int i = 0; i < int(S.size()); ) {
		LL val = solve(S[i]);
		if (val == inf) break;
		int l = i + 1, r = int(S.size()) - 1, tot = i;
		for (; l <= r; ) {
			int mid = (l + r) >> 1;
			if (solve(S[mid]) == val) tot = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans = std::min(ans, val - S[tot]);
		i = tot + 1;
	}
	printf("%lld\n", ans);
	return 0;
}