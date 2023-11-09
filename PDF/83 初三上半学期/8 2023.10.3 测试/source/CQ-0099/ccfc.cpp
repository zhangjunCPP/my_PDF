#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int n;
int nxt[N], ans[N];
vector<int> E[N];
char a[N];
bitset<N> p, q;
bitset<N> ad[33335];
void dfs(int x) {
	p.set(x);
	q.set(n - x + 1);
	if (x > 3) {
		int l = (x - 1) / 3;
		ans[x] = ((p & (q >> (n - x + 1))) & ad[l]).count();
	}
	for (int y: E[x]) dfs(y);
	p.reset(x);
	q.reset(n - x + 1);
}
int main() {
	freopen("ccfc.in", "r", stdin);
	freopen("ccfc.out", "w", stdout);
	scanf("%s", a + 1);
	n = strlen(a + 1);
	reverse(a + 1, a + 1 + n);
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && a[j + 1] != a[i]) j = nxt[j];
		j += a[j + 1] == a[i];
		nxt[i] = j, E[j].push_back(i);
	}
	for (int i = 1; i * 3 + 1 <= n; i++) {
		ad[i] = ad[i - 1];
		ad[i].set(i);
	}
	dfs(0);
	for (int i = n; i >= 2; i--) printf("%d ", ans[i]);
	printf("%d\n", ans[1]);
	return 0;
}
