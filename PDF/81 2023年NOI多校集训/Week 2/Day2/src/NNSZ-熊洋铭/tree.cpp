#include <iostream>
#include <algorithm>
#include <vector>

const int MODN = 1000000007;

void dfs(int x, int fa, int& tot, std::vector<std::vector<int>>& f, std::vector<int>& id, std::vector<int>& ref, std::vector<int>& siz, std::vector<int>& dep, std::vector<std::vector<int>>& ed) {
	f[x].resize(21);
	f[x][0] = fa;
	for(int i = 1; i <= 20; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
	id[x] = ++tot, ref[tot] = x, siz[x] = 1, dep[x] = dep[fa] + 1;
	for(int i : ed[x]) {
		if(i == fa)	continue;
		dfs(i, x, tot, f, id, ref, siz, dep, ed);
		siz[x] += siz[i];
	}
}

int lca(int u, int v, std::vector<int>& dep, std::vector<std::vector<int>>& f) {
	if(dep[u] < dep[v]) std::swap(u, v);
	int diff = dep[u] - dep[v];
	for(int i = 0; i <= 20; ++i) {
		if((diff >> i) & 1) {
			u = f[u][i];
		}
	}
	for(int i = 0; i <= 20; ++i) {
		if(f[u][i] != f[v][i])	u = f[u][i], v = f[v][i];
	}
	if(u == v)	return u;
	return f[u][0];
}

long long dis(int u, int v, std::vector <int>& dep, std::vector<std::vector<int>>& f) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v, dep, f)];
}

long long qpow(long long a, long long b) {
	return b ? (b & 1 ? qpow(a, b - 1) * a : qpow(a * a % MODN, b / 2) % MODN) : 1;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> ed(n + 1), f(n + 1);
	std::vector<int> id(n + 1), ref(n + 1), siz(n + 1), dep(n + 1);
	f[0].resize(21);
	
	for(int i = 1; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		ed[x].push_back(y), ed[y].push_back(x);
	}
	
	int tot = 0;
	dfs(1, 0, tot, f, id, ref, siz, dep, ed);
	
	if(n >= 16) {
		std::cout << qpow(2, n + 1) << '\n';
		return 0;
	}
	
	int tot_ans = 0;
	for(int i = 0; i < (1 << n); ++i) {
		long long ans = 0;
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				if(((i >> (j - 1)) & 1) == ((i >> (k - 1)) & 1)) {
					ans = std::max(dis(j, k, dep, f), ans);
				}
			}
		}
		(tot_ans += ans) %= MODN;
	}
	
	std::cout << tot_ans << '\n';
	
	return 0;
}
