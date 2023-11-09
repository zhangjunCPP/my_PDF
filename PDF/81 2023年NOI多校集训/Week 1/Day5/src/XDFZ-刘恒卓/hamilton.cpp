#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 5;
int n, m;
int deg[N][N];
vector<int> rd[N];
void dfs(int u, int s, int tot, int z) {
	z |= (1 << (u - 1)), rd[tot].push_back(u);
	if (deg[u][s]) {
		int c = 0;
		for (int j = 1; j <= n; j++) {
			if (((z >> (j - 1)) & 1) == 0) {
				c = j;
				break;
			}
		}
		if (c) {
			dfs(c, c, tot + 1, z);
		}
		else {
			printf("YES\n");
			for (int i = 1; i <= tot; i++) {
				printf("%zu", rd[i].size());
				for (int j : rd[i]) {
					printf(" %d", j);
				}
				printf("\n");
			}
			exit(0);
		}
	}
	for (int v = 1; v <= m; v++) {
		if (deg[u][v] && ((z >> (v - 1)) & 1) == 0) {
			dfs(v, s, tot, z);
		}
	}
	return ;
} 
int main() {
	freopen("hamilton.in", "r", stdin);
	freopen("hamilton.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n > 20) {
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u][v] = 1;
	}
	dfs(1, 1, 1, 0);
	printf("NO\n");
	return 0;
}
