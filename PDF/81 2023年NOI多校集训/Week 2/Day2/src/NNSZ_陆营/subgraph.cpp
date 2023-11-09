#include <iostream>
#include <queue>
using namespace std;

const int inf = 1 << 30;
const int max_n = 1e6 + 10;
const int max_m = 1e6 + 10;

int degree[max_n];

int main() {

	freopen("subgraph.in", "r", stdin);
	freopen("subgraph.out", "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	long long M, N, B;
	scanf("%lld %lld %lld", &M, &N, &B);
	for (int i = 1; i <= m; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		++degree[from];
		++degree[to];
	}

	int k = inf;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			continue;
		}
		k = min(k, degree[i]);
	}

	printf("%d %lld\n", k, M * m - N * n);

	return 0;
}
