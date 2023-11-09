#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, k;
char s[N];

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d %d", &n, &m, &k);
		cin >> s;
		for (int i = 1, u, v; i <= m; ++i)
			scanf ("%d %d", &u, &v);
		int x = m - n + 2;
		int cnt = x % k;
		if (!cnt)
			cnt = k;
		if (s[cnt - 1] == 'G')
			printf ("P\n");
		else
			printf ("G\n");
	}
	return 0;
} 
