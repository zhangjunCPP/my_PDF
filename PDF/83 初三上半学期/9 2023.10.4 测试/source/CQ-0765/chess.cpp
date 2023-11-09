#include<bits/stdc++.h>
const int maxn = 2e3 + 10;
int p, k, n;
bool vis[maxn][maxn];
int ch[maxn];
bool d(int w) {
	if (w == p + 1) return true;
	for (int i = 0; i < n; i++) {
		bool flg = 1;
		for (int j = 1; j < w && flg; j++) flg &= vis[ch[j]][i] == 0 && ch[j] != i;
		if (flg) {
			ch[w] = i;
			if (d(w + 1)) return true;
		}
	}
	return false;
}
int ans;
int a[maxn][maxn], c[maxn][maxn];
void dfs(int w) {
	if (w > ans) {
		ans = w;
		for (int i = 0; i < w; i++)
			for (int j = 1; j <= p; j++)
				a[i][j] = c[i][j];
	}
	if (! d(1)) return ;
	memcpy(c[w], ch, sizeof(int) * (p + 1));
	for (int i = 1; i <= p; i++)
		for (int j = 1; j < i; j++)
			vis[c[w][i]][c[w][j]] = vis[c[w][j]][c[w][i]] = 1;
	dfs(w + 1);
	for (int i = 1; i <= p; i++)
		for (int j = 1; j < i; j++)
			vis[c[w][i]][c[w][j]] = vis[c[w][j]][c[w][i]] = 0; 
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d%d", &p, &k);
	n = 1;
	for (int i = 1; i <= k; i++) n *= p;
	if (k == 1) {
		printf("1\n");
		for (int i = 0; i < p; i++) printf("%d ", p);
		return 0;
	}
	if (p == 2) {
		printf("%d\n", n * (n - 1) / 2);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				printf("%d %d\n", i, j);
		return 0;
	}
	dfs(0);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		for (int j = 1; j <= p; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}