#include<bits/stdc++.h> 
const int maxn = 1e5 + 10;
char s[maxn];
void solve() {
	int n, m, k;
	scanf("%d%d%d%s", &n, &m, &k, s);
	for (int i = 1; i <= m; i++) scanf("%*d%*d");
	m -= (n - 1), m %= k;
	printf("%c\n", s[m] == 'P' ? 'G' : 'P');
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (; T; T--) solve();
	return 0;
}
