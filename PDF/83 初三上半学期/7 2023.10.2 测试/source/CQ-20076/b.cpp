#include<bits/stdc++.h>
using LL = long long;
const int maxn = 20 + 10;
LL a[maxn];
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		LL sum = 0, siz = 0;
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				sum += a[j], siz++;
		int tot = 0;
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				tot += a[j] * siz > sum;
		ans = std::max(ans, tot);
	}
	printf("%d\n", ans);
	return 0;
}
