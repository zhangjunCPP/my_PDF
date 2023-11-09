#include<bits/stdc++.h>
using LL = long long;
const LL mod = 998244353;
const int maxn = 5e5 + 10;
int n;
std::vector<int> a[maxn];
int siz[maxn];
int mx[maxn], mxn[maxn];
int deg[maxn];
LL ans;
int ch[maxn];
int cnt[maxn];
void dfs(int x) {
	if (x == n + 1) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				cnt[i] += ch[i] > ch[j];
		for (int i = 1; i <= n; i++)
			if (cnt[i] != deg[i])
				return ;
		ans = (ans + 1) % mod;
		return ;
	}
	for (int i = 0; i < siz[x]; i++)
		ch[x] = a[x][i], dfs(x + 1);
}
int main() {
	freopen("marketeers.in", "r", stdin);
	freopen("marketeers.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &siz[i]);
		for (int j = 1; j <= siz[i]; j++) {
			int x;
			scanf("%d", &x);
			a[i].push_back(x);
		}
		std::sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++)
		mxn[i] = int(2e9);
	for (int i = 1; i <= n; i++) {
		for (; mx[i] + 1 < siz[i] && a[i][mx[i] + 1] < mxn[i]; mx[i]++);
		for (int j = i + 1; j <= n; j++)
			if (a[i][mx[i]] > a[j][0])
				deg[i]++, mxn[j] = std::min(mxn[j], a[i][mx[i]]);
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
