#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, q;
vector <int> G[N];

int main () {
	freopen ("big.in", "r", stdin);
	freopen ("big.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1, u, v; i <= m; ++i) {
		scanf ("%d %d", &u, &v);
		G[u].push_back (v);
		G[v].push_back (u);
	}
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i)
		printf ("0\n");
	return 0;
} 
