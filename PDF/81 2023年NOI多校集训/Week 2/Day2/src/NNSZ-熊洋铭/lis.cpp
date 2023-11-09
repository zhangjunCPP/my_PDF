#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> ed(n + 1);
	for(int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	
	std::vector<int> w(n + 1);
	for(int i = 1; i <= n; ++i)
		std::cin >> w[i];
	
	std::vector<int> len(2);
	len[1] = w[1];
	for(int i = 2; i <= n; ++i) {
		if(w[i] > *len.rbegin())	{
			len.push_back(w[i]);
		} else {
			*lower_bound(len.begin() + 1, len.end(), w[i]) = w[i];
		}
	}
	
	std::cout << (len.size() - 1) / 2 << '\n';
	
	return 0;
}
