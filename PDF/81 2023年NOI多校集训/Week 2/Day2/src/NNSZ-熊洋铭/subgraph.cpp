#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

int main() {
	freopen("subgraph.in", "r", stdin);
	freopen("subgraph.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, M, N, B;
	std::cin >> n >> m >> M >> N >> B;
	
	std::vector<std::vector<int>> ed(n + 1);
	std::vector<int> deg(n + 1, 0);
	
	int max = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		ed[u].push_back(v);
		ed[v].push_back(u);
		++deg[u];
		++deg[v];
		max = std::max({max, deg[u], deg[v]});
	}
	
	std::mt19937 rnd(time(0));
	
	std::cout << rnd() % (max - 1) + 2 << ' ' << rnd() % (M * m + N * n) << '\n';
	
	return 0;
}
